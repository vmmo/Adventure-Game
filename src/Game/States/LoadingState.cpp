#include "LoadingState.h"

LoadingState::LoadingState() {
    LoadingImage.load("images/ui/mainLoading.png");
    music.load("audio/ui/beep.wav");

}

void LoadingState::tick() {
    if (time == 90)
    {
        time = 0;
        setFinished(true);
    }
    else
    {
        time++;
    }
}

void LoadingState::render(){
    LoadingImage.draw(0, 0, ofGetWidth(), ofGetHeight());
}

void LoadingState::keyPressed(int key) {

}

void LoadingState::mousePressed(int x, int y, int button) {

}

void LoadingState::reset() {
    setFinished(false);
}