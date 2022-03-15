#pragma once

#include "State.h"
#include "Player.h"

class LoadingState: public State
{
    private:
        ofImage LoadingImage;
        int time = 0;
    public:
        LoadingState();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void reset();
};