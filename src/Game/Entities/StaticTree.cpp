#include "StaticTree.h"

StaticTree::StaticTree(string entityName, int ox, int oy) : Entity(ox, oy, 64, 64, "images/entities/world/tree.png")
{
    this->entityName = entityName;
}

void StaticTree::tickOverworld()
{  

}

void StaticTree::renderOverworld()
{
    // uncomment these if you want the coordinates of the trees in the current area
    // ofDrawBitmapString("rX:" + to_string(renderX), 100 + 125 * ((stoi(id) % 10) - 1), 100);
    // ofDrawBitmapString("rY:" + to_string(renderY), 100 + 125 * ((stoi(id) % 10) - 1), 120);
    // ofDrawBitmapString("ow:" + to_string(ox), 100 + 125 * ((stoi(id) % 10) - 1), 140);
    // ofDrawBitmapString("oy:" + to_string(oy), 100 + 125 * ((stoi(id) % 10) - 1), 160);
    overworldSprite.draw(renderX, renderY, ow, oh);
}

void StaticTree::keyPressed(int key)
{
    
}

void StaticTree::keyReleased(int key)
{

}

void StaticTree::reset()
{
    
}
