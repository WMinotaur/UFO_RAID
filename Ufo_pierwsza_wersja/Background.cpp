#include "Background.h"


Background::Background():GameElement(){
    Create(path);

}

void Background::ShowEndGameScreen() {
    Create(gameover);
}

