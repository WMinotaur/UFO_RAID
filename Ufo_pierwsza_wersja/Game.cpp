#include "Game.h"

/**
 * @brief Construct a new Game::Game object
 */
Game::Game() {
    paused = false;
    wchar_t path[MAX_PATH];
    
    GetModuleFileNameW(NULL, path, MAX_PATH);
    std::wstring ws(path);
    std::string executablePath(ws.begin(), ws.end());
   
    size_t lastSlash = executablePath.find_last_of("\\/");

    executable_path = executablePath.substr(0, lastSlash);
}

/**
 * @brief Check if the game is initialized
 * 
 * @param bkg Background object
 * @param shp Ship object
 * @return true if both background and ship are initialized
 * @return false otherwise
 */
bool Game::GameInitialized(Background *bkg, Ship *shp)
{
    if (bkg->if_initialised() == false)
    {     
        return false;
    }

    if (shp->if_initialised() == false) {
        return false;
    }
    return true;
}

/**
 * @brief Main game loop
 * 
 * @param window Render window
 * @param bgr Background object
 * @param ship Ship object
 * @return GameOptions The next game option
 */
GameOptions Game::GameLoop(RenderWindow* window, Background* bgr, Ship *ship)
{
    GameOptions return_value{ Title };
    ULONGLONG start_time{ GetTickCount() };
    ULONGLONG CurrentTime{ GetTickCount() };

    while (window->isOpen()) {
        Event event;
        while (window->pollEvent(event)) {
            if (event.type == Event::Closed) {
                window->close();
            }
            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::P) {
                    paused = !paused;
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            return_value = Title;
            break;
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            if (return_value != Title) { 
                 break;
            }
        }
        if (paused) {
            continue;
        }
        if (GetTickCount64() - CurrentTime > constants::MISSILE_GENERATION_PERIOD && ship->isShipDetonated() == false && ship->isShipFinished() == false)
        {
            GameElementPosition* ShipPosition = ship->getPosition();
            AbstractMissile* newMissile = MissileFactory(enemy, ShipPosition->x, 0);
            missiles.push_back(newMissile);
            CurrentTime = GetTickCount64();
        }

        if (ship->isShipDetonated() == false && ship->isShipFinished() == false) {
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                ship->move(-5.f, 0.f);
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                ship->move(5.f, 0.f);
            }
            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                if (friendlyMissile.empty()) {
                    GameElementPosition* ShipPosition = ship->getPosition();
                    AbstractMissile* newFriendlyMissile = MissileFactory(friendly, ShipPosition->x, ShipPosition->y);
                    friendlyMissile.push_back(newFriendlyMissile);
                }
            }
        }

        if (ship->isShipFinished() == false && ship->isOnTheRoad(bgr->getImage(), bgr->getDistanceTraveled(), bgr->getBackgroundHeight()) == false) {
            ship->detonate();
        }

        UpdateMissiles(ship);

        if (ship->HasShipFinished(bgr->getImage(), bgr->getDistanceTraveled(), bgr->getBackgroundHeight())) {
            DeleteAllMissiles(window);
            bgr->ShowWinGameScreen();
            return_value = NextLevel;
        }
        else {
            if (ship->isShipDetonated()) {
                DeleteAllMissiles(window);
                bgr->ShowEndGameScreen();
                return_value = Title;
            }
        }

        bgr->update();
        window->clear();
        bgr->draw(window);
        ship->draw(window);
        DeleteMissiless(window);
        window->display();
    }

    return return_value;
}

/**
 * @brief Delete all missiles
 * 
 * @param window Render window
 */
void Game::DeleteAllMissiles(RenderWindow* window) {
    for (size_t i{}; i < missiles.size(); i++) {
        AbstractMissile* m = missiles[i];
        if (m != NULL) {     
            missiles.erase(missiles.begin() + i);
            delete m;
        }
    }
    for (size_t i{}; i < friendlyMissile.size(); i++) {
        AbstractMissile* m = friendlyMissile[i];
        if (m != NULL) {
            friendlyMissile.erase(friendlyMissile.begin() + i);
            delete m;
        }
    }
}

/**
 * @brief Delete missiles that need to be deleted
 * 
 * @param window Render window
 */
void Game::DeleteMissiless(RenderWindow* window)
{
    for (size_t i{}; i < missiles.size(); i++) {
        AbstractMissile* m = missiles[i];
        if (m != NULL) {
            if (m->toBeDeleted()) {
                missiles.erase(missiles.begin() + i);
                delete m;
                break;
            }
            m->draw(window);
        }
    }
    for (size_t i{}; i < friendlyMissile.size(); i++) {
        AbstractMissile* m = friendlyMissile[i];
        if (m != NULL) {
            if (m->toBeDeleted()) {
                friendlyMissile.erase(friendlyMissile.begin() + i);
                delete m;
                break;
            }
            m->draw(window);
        }
    }
}

/**
 * @brief Update all missiles
 * 
 * @param ship Ship object
 */
void Game::UpdateMissiles(Ship *ship)
{
    for (AbstractMissile* m : friendlyMissile) {
        m->update();
    }
    for (AbstractMissile* m : missiles) {
        m->update();
        m->detectColision(ship);
        m->detectBeingShotDown(&friendlyMissile);
    }
}

/**
 * @brief Play level 1
 * 
 * @param okno Render window
 * @return GameOptions The next game option
 */
GameOptions Game::PlayLevel1(RenderWindow* okno) {
    std::string path{ ".\\Textures\\background_level1.jpg" };
    std::string next_path{ ".\\Textures\\background_next.png" };
    Background background(path,next_path);
    Ship ship(Color(212, 106, 48));
    
    if (!GameInitialized(&background, &ship))
    {
        return GameOptions::InitialisationError;
    }

    GameOptions return_value{Title};

    return_value = GameLoop(okno, &background, &ship);
    if (return_value == NextLevel) {
        return_value = Level2;
    }
    return return_value;
}

/**
 * @brief Play level 2
 * 
 * @param okno Render window
 * @return GameOptions The next game option
 */
GameOptions Game::PlayLevel2(RenderWindow* okno) {
    std::string path{ ".\\Textures\\background_level2.jpg" };
    std::string win_path{ ".\\Textures\\background_won.jpg" };
    Background background(path,win_path);
    Ship ship(Color(8, 175, 219));

    GameOptions return_value{ Title };

    return_value = GameLoop(okno, &background, &ship);
    if (return_value == NextLevel)
        return_value = Title;
    return return_value;
}

/**
 * @brief Display credits screen
 * 
 * @param window Render window
 * @return GameOptions The next game option
 */
GameOptions Game::Credits(RenderWindow* window) {
    std::string path(".\\Textures\\credits.jpg");
    StaticBackground background(path);
    GameOptions return_value{ Title };
    while (window->isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            return_value = Title;
            break;
        }
        window->clear();
        background.draw(window);
        window->display();
    }
    return return_value;
}

/**
 * @brief Display title screen
 * 
 * @param okno Render window
 * @return GameOptions The next game option
 */
GameOptions Game::TitleScreen(RenderWindow* okno) {
    StaticBackground background(this->executable_path+"\\Textures\\TittleScreen.jpg");

    if (background.if_initialised() == false)
    {
        return InitialisationError;
    }
    GameElementPosition Pos1(constants::Position, constants::Position1);
    GameElementPosition Pos2(constants::Position, constants::Position2);
    GameElementPosition Pos3(constants::Position, constants::Position3);
    Pointer pointer(&Pos1,&Pos2,&Pos3);
    if (pointer.if_initialised() == false) {
        return InitialisationError;
    }
    int choice{};
    while (okno->isOpen()) {
        Event event;
        while (okno->pollEvent(event)) {
            if (event.type == Event::Closed) {
                okno->close();
            }
            if (event.type == Event::KeyReleased) {
                Keyboard::Key zmienna = event.key.code;
                switch (zmienna) {
                case Keyboard::Down:
                    pointer.moveDown();
                    break;
                case Keyboard::Up:
                    pointer.moveUp();
                    break;
                case Keyboard::Enter:
                    choice = pointer.getCurrentSelection();
                    switch (choice) {
                    case 0:
                        return Level1;
                        break;
                    case 1:
                        return CreditsGame;
                        break;
                    case 2:
                        return ExitGame;
                        break;
                    default:
                        return InitialisationError;
                        break;
                    }
                    break;
                }
            }
        }
        okno->clear();
        background.draw(okno);
        pointer.draw(okno);
        okno->display();
    }
    return Title;
}

/**
 * @brief Display a message box with a given message
 * 
 * @param message The message to display
 */
void Game::displayMessageBox(const std::string& message) {
    sf::RenderWindow window(sf::VideoMode(600, 200), "Problem with loading game elements");

    sf::Font font;
    if (!font.loadFromFile(executable_path + "arial.ttf")) {
        std::cerr << "Error loading font\n";
        return;
    }

    sf::Text text;
    text.setString(message);
    text.setFillColor(sf::Color::Black);
    text.setPosition(50, 80);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        window.draw(text);
        window.display();
    }
}
