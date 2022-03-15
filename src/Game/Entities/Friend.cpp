#include "Friend.h"

Friend::Friend(int ox, int oy, int ow, int oh, string overworldPath, string textSpeech) : Entity(ox, oy, ow, oh, overworldPath)
{
    this->textSpeech = textSpeech;

    vector<ofImage> downFrames = {};
    vector<ofImage> upFrames = {};
    vector<ofImage> leftFrames = {};
    vector<ofImage> rightFrames = {};
    vector<ofImage> fightingFrames = {};
    ofImage temp;

    for (int i = 1; i < 5; i++)
    {
        temp.load("images/entities/player/downframes/player-ow-front" + std::to_string(i == 3 ? 1 : i) + ".png");
        downFrames.push_back(temp);
        temp.load("images/entities/player/upframes/player-ow-up" + std::to_string(i == 3 ? 1 : i) + ".png");
        upFrames.push_back(temp);
        temp.load("images/entities/player/leftframes/player-ow-left" + std::to_string(i == 3 ? 1 : i) + ".png");
        leftFrames.push_back(temp);
        temp.load("images/entities/player/rightframes/player-ow-right" + std::to_string(i == 3 ? 1 : i) + ".png");
        rightFrames.push_back(temp);
    }

    walkDown = new Animation(5, downFrames);
    walkUp = new Animation(5, upFrames);
    walkLeft = new Animation(5, leftFrames);
    walkRight = new Animation(5, rightFrames);
}

void Friend::tickOverworld()
{
    if (talking)
    {
        counter--;
        if (counter <= 0)
        {
            talking = false;
            counter = 90;
        }
    }
    if (moveTimer == 60)
    {
        walking = true;
        switch (direction)
        {
        case Direction::left:
            direction = Direction::down;
            break;
        case Direction::right:
            direction = Direction::up;
            break;
        case Direction::up:
            direction = Direction::left;
            break;
        case Direction::down:
            direction = Direction::right;
            break;
        }
    }
    if (moveTimer == 45)
    {
        walking = false;
    }
    moveTimer--;
    if (moveTimer == 0)
        moveTimer = 60;

    if (walking)
    {
        switch (direction)
        {
        case Direction::left:
            this->ox -= speed;
            walkLeft->tick();
            overworldSprite = walkLeft->getCurrentFrame();
            break;
        case Direction::right:
            this->ox += speed;
            walkRight->tick();
            overworldSprite = walkRight->getCurrentFrame();
            break;
        case Direction::up:
            this->oy -= speed;
            walkUp->tick();
            overworldSprite = walkUp->getCurrentFrame();
            break;
        case Direction::down:
            this->oy += speed;
            walkDown->tick();
            overworldSprite = walkDown->getCurrentFrame();
            break;
        }
    }
    else
    {
        switch (direction)
        {
        case Direction::left:
            overworldSprite.load("images/entities/player/leftframes/player-ow-left1.png");
            break;
        case Direction::right:
            overworldSprite.load("images/entities/player/rightframes/player-ow-right1.png");
            break;
        case Direction::up:
            overworldSprite.load("images/entities/player/upframes/player-ow-up1.png");
            break;
        case Direction::down:
            overworldSprite.load("images/entities/player/downframes/player-ow-front1.png");
            break;
        }
    }
}

void Friend::renderOverworld()
{
    //ofDrawBitmapString("rX:" + to_string(renderX), 100 + 125, 100);
    //ofDrawBitmapString("rY:" + to_string(renderY), 100 + 125, 120);
    //ofDrawBitmapString("ow:" + to_string(ox), 100 + 125, 140);
    //ofDrawBitmapString("oy:" + to_string(oy), 100 + 125, 160);
    ofSetColor(0,81,98);
    overworldSprite.draw(renderX, renderY, ow, oh);
    ofSetColor(255, 255, 255);
    
    if (talking)
    {
        ofDrawBitmapString(textSpeech, renderX, renderY - 50);
    }
}
