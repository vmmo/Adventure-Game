#include "OverworldState.h"

OverworldState::OverworldState(Player *player, Area *area)
{
    this->player = player;
    camera = new OverworldCamera(player);
    loadArea(area);
    music.setVolume(0.25);
    music.setLoop(true);
}

void OverworldState::loadArea(Area *area)
{
    this->area = area;
    overworldImage = area->getImage();
    powerUp.load("audio/power-up.wav");
    music = area->getMusic();
    music.setVolume(0.25);
    music.setLoop(true);
    player->setOX(area->getEntrancePos().x);
    player->setOY(area->getEntrancePos().y);
}

void OverworldState::tick()
{
    player->tickOverworld();
    for (unsigned int i = 0; i < area->getEnemies().size(); i++)
    {
        if (!area->getEnemies().at(i)->isDead())
        {
            area->getEnemies().at(i)->tickOverworld();
            if (player->collides(area->getEnemies().at(i)))
            {
                setEnemy(area->getEnemies().at(i));
                setNextState("Loading");
                setFinished(true);
            }
        }
    }

    for (unsigned int i = 0; i < area->getFriends().size(); i++)
    {
            area->getFriends().at(i)->tickOverworld();
            if(player->collides(area->getFriends().at(i)))
        {
            if(player->getDirection() == Direction::up)
            {
                player->setOY(player->getOY() + 12);
            }
            else if(player->getDirection() == Direction::down)
            {
                player->setOY(player->getOY() - 12);
            }
            else if(player->getDirection() == Direction::right)
            {
                player->setOX(player->getOX() - 12);
            }
            else
            {
                player->setOX(player->getOX() + 12);
            }          
        }
    }

    if(area->getRemainingEnemies() == 0)
    {
        for (unsigned int i = 0; i < area->getBoss().size(); i++)
        {
            if (!area->getBoss().at(i)->isDead())
            {
                area->getBoss().at(i)->tickOverworld();
                if (player->collides(area->getBoss().at(i)))
                {
                    setEnemy(area->getBoss().at(i));
                    setNextState("Loading");
                    setFinished(true);
                }
            }
        }
    }

    for (unsigned int i = 0; i < area->getTrees().size(); i++)
    {
        area->getTrees().at(i)->tickOverworld();
        if(player->collides(area->getTrees().at(i)))
        {
            if(player->getDirection() == Direction::up)
            {
                player->setOY(player->getOY() + 12);
            }
            else if(player->getDirection() == Direction::down)
            {
                player->setOY(player->getOY() - 12);
            }
            else if(player->getDirection() == Direction::right)
            {
                player->setOX(player->getOX() - 12);
            }
            else
            {
                player->setOX(player->getOX() + 12);
            }          
        }
    }

    for (unsigned int i = 0; i < area->getOrbs().size(); i++)
    {
        if (!area->getOrbs().at(i)->isUsed())
        {  
            area->getOrbs().at(i)->tickOverworld();
            if(player->collides(area->getOrbs().at(i)))
            {
                powerUp.play();
                if(!area->getOrbs().at(i)->getOrbType().compare("Damage"))
                {
                    player->setDmg(player->getDmg() + 2);
                    area->getOrbs().at(i)->consume();
                }
                else if(!area->getOrbs().at(i)->getOrbType().compare("Speed"))
                {
                    player->setSpeed(player->getSpeed() + 4);
                    area->getOrbs().at(i)->consume();
                }
                else if(!area->getOrbs().at(i)->getOrbType().compare("Health"))
                {
                    // player->setHealth(player->getHealth() - 50);
                    area->getOrbs().at(i)->consume();
                }
            }
        }
    }
    
    camera->tick();
}

void OverworldState::render()
{
    overworldImage.drawSubsection(0, 0, camera->getDimensionX(), camera->getDimensionY(), camera->getLeftCornerX(), camera->getTopCornerY());
    player->renderOverworld();

    for (unsigned int i = 0; i < area->getEnemies().size(); i++)
    {
        if (!area->getEnemies().at(i)->isDead())
        {
            int playerDistanceX = area->getEnemies().at(i)->getOX() - camera->getPlayerX();
            int playerDistanceY = area->getEnemies().at(i)->getOY() - camera->getPlayerY();
            area->getEnemies().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            area->getEnemies().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            area->getEnemies().at(i)->renderOverworld();
        }
    }

    for (unsigned int i = 0; i < area->getFriends().size(); i++)
    {
        int playerDistanceX = area->getFriends().at(i)->getOX() - camera->getPlayerX();
        int playerDistanceY = area->getFriends().at(i)->getOY() - camera->getPlayerY();
        area->getFriends().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
        area->getFriends().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
        area->getFriends().at(i)->renderOverworld();
    }

    for (unsigned int i = 0; i < area->getTrees().size(); i++)
    {
        int playerDistanceX = area->getTrees().at(i)->getOX() - camera->getPlayerX();
        int playerDistanceY = area->getTrees().at(i)->getOY() - camera->getPlayerY();
        area->getTrees().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
        area->getTrees().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
        area->getTrees().at(i)->renderOverworld();
    
    }

    if(area->getRemainingEnemies() == 0)
    {
        for (unsigned int i = 0; i < area->getBoss().size(); i++)
        {
            if(!area->getBoss().at(i)->isDead())
            {
                int playerDistanceX = area->getBoss().at(i)->getOX() - camera->getPlayerX();
                int playerDistanceY = area->getBoss().at(i)->getOY() - camera->getPlayerY();
                area->getBoss().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
                area->getBoss().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
                area->getBoss().at(i)->renderOverworld();
            }

        }
    }

    for (unsigned int i = 0; i < area->getOrbs().size(); i++)
    {
        if(!area->getOrbs().at(i)->isUsed())
        {
            int playerDistanceX = area->getOrbs().at(i)->getOX() - camera->getPlayerX();
            int playerDistanceY = area->getOrbs().at(i)->getOY() - camera->getPlayerY();
            area->getOrbs().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            area->getOrbs().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            area->getOrbs().at(i)->renderOverworld();
        }
    
    }

    
}

void OverworldState::keyPressed(int key)
{
    player->keyPressed(key);
    for (unsigned int i = 0; i < area->getFriends().size(); i++){
            if((player->getOX() < area->getFriends().at(i)->getOX() + 124 &&
            player->getOX() > area->getFriends().at(i)->getOX() - 124) &&
            (player->getOY() < area->getFriends().at(i)->getOY() + 124 &&
            player->getOY() > area->getFriends().at(i)->getOY() - 124))
            {
                area->getFriends().at(i)->shutUp();
            }
        }

    if(key == 'p')
    {
        setNextState("Pause");
        setFinished(true);
    }

    if (key == 'r')
    {
        area-> resetEnemies();
    }

    if (key == 'e'){
        for (unsigned int i = 0; i < area->getFriends().size(); i++){
            if((player->getOX() < area->getFriends().at(i)->getOX() + 124 &&
            player->getOX() > area->getFriends().at(i)->getOX() - 124) &&
            (player->getOY() < area->getFriends().at(i)->getOY() + 124 &&
            player->getOY() > area->getFriends().at(i)->getOY() - 124))
            {
                area->getFriends().at(i)->talk();
            }
        }

        // check if player is within range of any friend, if so, set that friend's talking boolean to true

    }
}

void OverworldState::keyReleased(int key)
{
    player->keyReleased(key);
}

void OverworldState::mousePressed(int x, int y, int button)
{
}

void OverworldState::reset()
{
    player->keyReleased('w');
    player->keyReleased('a');
    player->keyReleased('s');
    player->keyReleased('d');
    player->setSpeed(8);
    setFinished(false);
    setNextState("");
}