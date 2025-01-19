#include "Game.h"


class Message_box {
public:
    Message_box(std::string message, std::string title) {
        RectangleShape wi0adomosc;
        //todo:dorobic pozniej
        //pauza
        // mapy i obrazy

    }
};

Game::Game() {
    paused = false;
};

bool Game::GameInitialized(Background *bkg, Ship *shp)
{
    if (bkg->if_initialised() == false)
    {
        Message_box box("nie udalo sie zaladowac tla", "blad");
        return false;
    }

    if (shp->if_initialised() == false) {
        Message_box box("nie udalo sie zaladowac statku", "blad");
        return false;
    }

}
GameOptions Game::GameLoop(RenderWindow* window, Background* bgr, Ship *ship)
{
    GameOptions return_value{ Title };
    //interactions game_interactions;
    DWORD start_time{ GetTickCount() };
    DWORD CurrentTime{ GetTickCount() };

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
            Missile* newMissile = new Missile(ShipPosition->x, 0);
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
                    FriendlyMissile* newFriendlyMissile = new FriendlyMissile(ShipPosition->x, ShipPosition->y);
                    friendlyMissile.push_back(newFriendlyMissile);
                }
            }
        }
        

        if (ship->isShipFinished() == false && ship->isOnTheRoad(bgr->getImage(), bgr->getDistanceTraveled(), bgr->getBackgroundHeight()) == false) {
            ship->detonate();
        }

        //update
        UpdateMissles(ship);


        if (ship->HasShipFinished(bgr->getImage(), bgr->getDistanceTraveled(), bgr->getBackgroundHeight())) {
            DeleteMissless(window);
            bgr->ShowWinGameScreen();
            return_value = NextLevel;
        }
        else {
            if (ship->isShipDetonated()) {
                DeleteMissless(window);
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
        DeleteMissless(window);
        window->display();
    }

    return return_value;
}
void Game::DeleteMissless(RenderWindow* window)
{
    for (int i{}; i < missiles.size(); i++) {
        Missile* m = missiles[i];
        if (m != NULL) {
            if (m->toBeDeleted()) {
                missiles.erase(missiles.begin() + i);
                delete m;
                break;
            }
            m->draw(window);

        }
    }
    for (int i{}; i < friendlyMissile.size(); i++) {
        FriendlyMissile* m = friendlyMissile[i];
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
void Game::UpdateMissles(Ship *ship)
{
    for (FriendlyMissile* m : friendlyMissile) {
        m->update();
    }
    for (Missile* m : missiles) {
        m->update();
        m->detectColision(ship);
        m->detectBeingShotDown(&friendlyMissile);
    }
}

GameOptions Game::PlayLevel1(RenderWindow* okno) {
    std::string path{ ".\\Textures\\background.jpg" };
    Background background(path);
    Ship ship;
    
    if (!GameInitialized(&background, &ship))
    {
        return GameOptions::InitialisationError;
    }


    GameOptions return_value{Title};


    return_value = GameLoop(okno, &background, &ship);
    if (return_value == NextLevel)
        return_value = Level2;
    return return_value;

}

GameOptions Game::PlayLevel2(RenderWindow* okno) {
    std::string path{ ".\\Textures\\background.jpg" };
    Background background(path);
    Ship ship;

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
    StaticBackground background(".\\Textures\\TittleScreen.jpg");
    if (background.if_initialised() == false)
    {
        Message_box box("nie udalo sie zaladowac tla", "blad");
        return InitialisationError;
    }
    GameElementPosition Pos1(constants::Position, constants::Position1);
    GameElementPosition Pos2(constants::Position, constants::Position2);
    GameElementPosition Pos3(constants::Position, constants::Position3);
    Pointer pointer(&Pos1,&Pos2,&Pos3);
    if (pointer.if_initialised() == false) {
        Message_box box("nie udalo sie zaladowac wstaznika", "blad");
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
};

