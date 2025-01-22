#include "Game.h"



Game::Game() {
    paused = false;
    wchar_t path[MAX_PATH];
    
    GetModuleFileNameW(NULL, path, MAX_PATH);
    std::wstring ws(path);
    std::string executablePath(ws.begin(), ws.end());
   
    size_t lastSlash = executablePath.find_last_of("\\/");

    
    executable_path = executablePath.substr(0, lastSlash);

};

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

//-----------------------------------------------------------------------------------------
GameOptions Game::GameLoop(RenderWindow* window, Background* bgr, Ship *ship)
{
    GameOptions return_value{ Title };
    //interactions game_interactions;
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


        // Obs³uga klawiatury: ruch statku
        if (ship->isShipDetonated() == false && ship->isShipFinished() == false) {
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                ship->move(-5.f, 0.f); // Przesuwanie w lewo
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                ship->move(5.f, 0.f); // Przesuwanie w prawo
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

        //update
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
        // Rysowanie
        window->clear();
        bgr->draw(window);
        //if (ship.isShipDetonated() == false) { okno.draw(plansza); }
        ship->draw(window);
        DeleteMissiless(window);
        window->display();
    }

    return return_value;
}


//----------------------------------------------------------------------------------
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

GameOptions Game::PlayLevel2(RenderWindow* okno) {
    std::string path{ ".\\Textures\\background_level2.jpg" };
    std::string win_path{ ".\\Textures\\background_won.jpg" };
    Background background(path,win_path);
    Ship ship(Color(8, 175, 219));

    GameOptions return_value{ Title };

    return_value = GameLoop(okno, &background, &ship);
    if (return_value == NextLevel)
        return_value = Title; // if there were more levels we would go to next level
    return return_value;
}


GameOptions Game::Credits(RenderWindow* window) {
    std::string path(".\\Textures\\credits.jpg");
    StaticBackground background(path);
    GameOptions return_value{ Title };
    while (window->isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            return_value = Title;
            break;
        }
        // Rysowanie
        window->clear();
        background.draw(window);
        window->display();
    }
    
    return return_value;
}
//---------------------------------------
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
    //-------------------------------------------------------------------------------
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
       
        //update

        // Rysowanie
        okno->clear();
        background.draw(okno);
        pointer.draw(okno);
        okno->display();
    }
    return Title;
};

