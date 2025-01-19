#include "Game.h"


class Message_box {
public:
    Message_box(std::string message, std::string title) {
        RectangleShape wi0adomosc;
        //todo:dorobic pozniej

    }
};

Game::Game() {
};

void Game::PlayGame(RenderWindow* okno) {
    Background background;
    if (background.if_initialised() == false)
    {
        Message_box box("nie udalo sie zaladowac tla", "blad");
        return;
    }

    Ship ship;
    if (ship.if_initialised() == false) {
        Message_box box("nie udalo sie zaladowac statku", "blad");
        return;
    }
    std::vector<Missile*> missiles;



    if (ship.if_initialised() == false) {
        Message_box box("nie udalo sie zaladowac statku", "blad");
        return;
    }
    //interactions game_interactions;
    DWORD start_time{ GetTickCount() };
    DWORD CurrentTime{ GetTickCount() };




    //-------------------------------------------------------------------------------
    while (okno->isOpen()) {
        Event event;
        while (okno->pollEvent(event)) {
            if (event.type == Event::Closed) {
                okno->close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            okno->close();
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
        }
        //update

        for (Missile* m : missiles) {
            m->update();
            m->detectColision(&ship);
        }
        if (ship.HasShipFinished(background.getImage(), background.getDistanceTraveled(), background.getBackgroundHeight())) {
            for (Missile* m : missiles) {
                delete m;
            }
            missiles.erase(missiles.begin(), missiles.end());
            background.ShowWinGameScreen();
        }
        else {
            if (ship.isShipDetonated()) {

                for (Missile* m : missiles) {
                    delete m;
                }
                missiles.erase(missiles.begin(), missiles.end());
                background.ShowEndGameScreen();
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
        okno->display();
    }

}


void Game::Credits() {
    Background background;
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
                        return Play;
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
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            okno->close();
        }
        // Obs³uga klawiatury: ruch statku
      /*
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            pointer.moveDown(); 
                
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            pointer.moveUp(); 
                
        }

        if (Keyboard::isKeyPressed(Keyboard::Enter)) {
            choice = pointer.getCurrentSelection();
            switch (choice) {
                case 0:
                    return Play;
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
          
        }
        */

        //update

        // Rysowanie
        okno->clear();
        background.draw(okno);
        pointer.draw(okno);
        okno->display();
    }
};

