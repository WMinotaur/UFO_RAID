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
};

GameOptions Game::PlayLevel1(RenderWindow* okno) {
    std::string path{ ".\\Textures\\background.jpg" };
    Background background(path);
    if (background.if_initialised() == false)
    {
        Message_box box("nie udalo sie zaladowac tla", "blad");
        return InitialisationError;
    }

    Ship ship;
    if (ship.if_initialised() == false) {
        Message_box box("nie udalo sie zaladowac statku", "blad");
        return InitialisationError;
    }
    std::vector<Missile*> missiles;
    std::vector<FriendlyMissile*> friendlyMissile;



    if (ship.if_initialised() == false) {
        Message_box box("nie udalo sie zaladowac statku", "blad");
        return InitialisationError;
    }

    GameOptions return_value{Title};

    //interactions game_interactions;
    DWORD start_time{ GetTickCount() };
    DWORD CurrentTime{ GetTickCount() };



    bool paused = false;
    //-------------------------------------------------------------------------------
    while (okno->isOpen()) {
        Event event;
        while (okno->pollEvent(event)) {
            if (event.type == Event::Closed) {
                okno->close();
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
        if (GetTickCount64() - CurrentTime > constants::MISSILE_GENERATION_PERIOD && ship.isShipDetonated() == false && ship.isShipFinished() == false)
        {
            GameElementPosition* ShipPosition = ship.getPosition();
            Missile* newMissile = new Missile(ShipPosition->x, 0);
            missiles.push_back(newMissile);
            CurrentTime = GetTickCount64();
        }


        // Obs³uga klawiatury: ruch statku
        if (ship.isShipDetonated() == false && ship.isShipFinished() == false) {
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                ship.move(-5.f, 0.f); // Przesuwanie w lewo
                if (ship.isOnTheRoad(background.getImage(), background.getDistanceTraveled(), background.getBackgroundHeight()) == false) {
                    ship.detonate();
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                ship.move(5.f, 0.f); // Przesuwanie w prawo
                if (ship.isOnTheRoad(background.getImage(), background.getDistanceTraveled(), background.getBackgroundHeight()) == false) {
                    ship.detonate();
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Up )) {
                if (friendlyMissile.empty()) {
                    GameElementPosition* ShipPosition = ship.getPosition();
                    FriendlyMissile* newFriendlyMissile = new FriendlyMissile(ShipPosition->x, ShipPosition->y);
                    friendlyMissile.push_back(newFriendlyMissile);
                }
            }
        }
        
        
        //update
        for (FriendlyMissile* m : friendlyMissile) {
            m->update();
        }
        for (Missile* m : missiles) {
            m->update();
            m->detectColision(&ship);
            m ->detectBeingShotDown(&friendlyMissile);
        }
        

        if (ship.HasShipFinished(background.getImage(), background.getDistanceTraveled(), background.getBackgroundHeight())) {
            for (Missile* m : missiles) {
                delete m;
            }
            missiles.erase(missiles.begin(), missiles.end());
            background.ShowWinGameScreen();
            return_value = Level2;
        }
        else {
            if (ship.isShipDetonated()) {

                for (Missile* m : missiles) {
                    delete m;
                }
                missiles.erase(missiles.begin(), missiles.end());
                background.ShowEndGameScreen();
                return_value = Title;

            }
        }


        background.update();


        // Rysowanie
        okno->clear();
        background.draw(okno);
        //if (ship.isShipDetonated() == false) { okno.draw(plansza); }
        ship.draw(okno);
        for (int i{}; i < missiles.size(); i++) {
            Missile* m = missiles[i];
            if (m != NULL) {
                if (m->toBeDeleted()) {
                    missiles.erase(missiles.begin() + i);
                    delete m;
                    break;
                }
                m->draw(okno);

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
                m->draw(okno);

            }

        }
        okno->display();
    }

      return return_value;
}

GameOptions Game::PlayLevel2(RenderWindow* okno) {
    std::string path{ ".\\Textures\\background.jpg" };
    Background background(path);
    if (background.if_initialised() == false)
    {
        Message_box box("nie udalo sie zaladowac tla", "blad");
        return InitialisationError;
    }

    Ship ship;
    if (ship.if_initialised() == false) {
        Message_box box("nie udalo sie zaladowac statku", "blad");
        return InitialisationError;
    }
    std::vector<Missile*> missiles;
    std::vector<FriendlyMissile*> friendlyMissile;



    if (ship.if_initialised() == false) {
        Message_box box("nie udalo sie zaladowac statku", "blad");
        return InitialisationError;
    }

    GameOptions return_value{ Title };

    //interactions game_interactions;
    DWORD start_time{ GetTickCount() };
    DWORD CurrentTime{ GetTickCount() };



    bool paused = false;
    //-------------------------------------------------------------------------------
    while (okno->isOpen()) {
        Event event;
        while (okno->pollEvent(event)) {
            if (event.type == Event::Closed) {
                okno->close();
            }
            if (event.type == Event::KeyReleased) {

                if (event.key.code == Keyboard::P) {
                    paused = !paused;
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            return_value = Title;
            break;
        }
        if (GetTickCount64() - CurrentTime > constants::MISSILE_GENERATION_PERIOD && ship.isShipDetonated() == false && ship.isShipFinished() == false)
        {
            GameElementPosition* ShipPosition = ship.getPosition();
            Missile* newMissile = new Missile(ShipPosition->x, 0);
            missiles.push_back(newMissile);
            CurrentTime = GetTickCount64();
        }


        // Obs³uga klawiatury: ruch statku
        if (ship.isShipDetonated() == false && ship.isShipFinished() == false) {
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                ship.move(-5.f, 0.f); // Przesuwanie w lewo
                if (ship.isOnTheRoad(background.getImage(), background.getDistanceTraveled(), background.getBackgroundHeight()) == false) {
                    ship.detonate();
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                ship.move(5.f, 0.f); // Przesuwanie w prawo
                if (ship.isOnTheRoad(background.getImage(), background.getDistanceTraveled(), background.getBackgroundHeight()) == false) {
                    ship.detonate();
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                if (friendlyMissile.empty()) {
                    GameElementPosition* ShipPosition = ship.getPosition();
                    FriendlyMissile* newFriendlyMissile = new FriendlyMissile(ShipPosition->x, ShipPosition->y);
                    friendlyMissile.push_back(newFriendlyMissile);
                }
            }
        }


        //update
        for (FriendlyMissile* m : friendlyMissile) {
            m->update();
        }
        for (Missile* m : missiles) {
            m->update();
            m->detectColision(&ship);
            m->detectBeingShotDown(&friendlyMissile);
        }


        if (ship.HasShipFinished(background.getImage(), background.getDistanceTraveled(), background.getBackgroundHeight())) {
            for (Missile* m : missiles) {
                delete m;
            }
            missiles.erase(missiles.begin(), missiles.end());
             background.ShowWinGameScreen();
            return_value = Title;
        }
        else {
            if (ship.isShipDetonated()) {

                for (Missile* m : missiles) {
                    delete m;
                }
                missiles.erase(missiles.begin(), missiles.end());
                background.ShowEndGameScreen();
                return_value = Title;

            }
        }


        background.update();


        // Rysowanie
        okno->clear();
        background.draw(okno);
        //if (ship.isShipDetonated() == false) { okno.draw(plansza); }
        ship.draw(okno);
        for (int i{}; i < missiles.size(); i++) {
            Missile* m = missiles[i];
            if (m != NULL) {
                if (m->toBeDeleted()) {
                    missiles.erase(missiles.begin() + i);
                    delete m;
                    break;
                }
                m->draw(okno);

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
                m->draw(okno);

            }

        }
        okno->display();
    }

    return return_value;
}


void Game::Credits() {
    std::string path(".\\Textures\\credits.jpg");
    Background background(path);
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

