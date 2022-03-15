#include "PauseState.h"

PauseState::PauseState() {
    pauseImage.load("images/ui/Gamepause.png");
    music.load("audio/ui/beep.wav");

}

void PauseState::tick() {

}

void PauseState::render(){
    pauseImage.draw(0, 0, ofGetWidth(), ofGetHeight());
}

void PauseState::keyPressed(int key) {

    if(key == 'p')
    {
        setFinished(true);
    }
}

void PauseState::mousePressed(int x, int y, int button) {

}

void PauseState::reset() {
    setFinished(false);
}