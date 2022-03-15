#include "Orb.h"

Orb::Orb(string entityName, string orbType, int ox, int oy, string orb) : Entity(ox, oy, 50, 50, orb)
{
    this->entityName = entityName;
    this->orbType = orbType;
}

void Orb::tickOverworld()
{  

}

void Orb::renderOverworld()
{
    // uncomment these if you want the coordinates of the orb in the current area
    // ofDrawBitmapString("rX:" + to_string(renderX), 100 + 125 * ((stoi(id) % 10) - 1), 100);
    // ofDrawBitmapString("rY:" + to_string(renderY), 100 + 125 * ((stoi(id) % 10) - 1), 120);
    // ofDrawBitmapString("ow:" + to_string(ox), 100 + 125 * ((stoi(id) % 10) - 1), 140);
    // ofDrawBitmapString("oy:" + to_string(oy), 100 + 125 * ((stoi(id) % 10) - 1), 160);
    overworldSprite.draw(renderX, renderY, ow, oh);
}

void Orb::keyPressed(int key)
{
    
}

void Orb::keyReleased(int key)
{

}

void Orb::reset()
{
    
}