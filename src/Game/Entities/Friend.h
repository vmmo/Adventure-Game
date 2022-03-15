#pragma once
#include "Entity.h"
#include "Animation.h"

class Friend : public Entity
{
private:
    string textSpeech;
    bool walking = false;
    int moveTimer = 60;
    Direction direction = Direction::down;
    int speed = 8;
    bool talking = false;
    int counter = 90;
    Animation *walkUp;
    Animation *walkDown;
    Animation *walkLeft;
    Animation *walkRight;

public:
    Friend(int ox, int oy, int ow, int oh, string overworldPath, string textSpeech);
    void setRenderX(int x) { renderX = x; };
    void setRenderY(int y) { renderY = y; };
    void talk() { talking = true; };
    void shutUp() { talking = false; };
    void renderOverworld();
    void tickOverworld();
};