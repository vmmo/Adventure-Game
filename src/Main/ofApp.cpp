#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(30);
	ofSetWindowTitle("PA2");
	setupAreas();
	// Declaration and Initialization of States
	player = new Player(100, 6);
	titleState = new TitleState();
	overworldState = new OverworldState(player, currentArea);
	battleState = new BattleState(player, currentArea);
	pauseState = new PauseState();
	winState = new WinState();
	endGameState = new EndGameState();
	loadingState = new LoadingState();

	// Initial State
	currentState = titleState;
}

//--------------------------------------------------------------
void ofApp::setupAreas()
{
	//each area is 672 pixels wide and 640 pixels high, with 10 and 8 pixels of space between the player and the edge of the map respectively
	//each in-game pixel is 4 * 1 screen pixel

	// Area 3

	vector<Enemy *> enemies3;
	ofPoint entrancePosition3(4 * 414, 4 * 566);
	Enemy *area3Enemy1 = new Enemy("31", 30, 8, "enemy4", 4 * 120, 4 * 342, 80, 80, "images/entities/enemy4/enemy4.png", "images/entities/enemy4/fightingframes/enemy4-f1.png");
	Enemy *area3Enemy2 = new Enemy("32", 30, 8, "enemy4", 4 * 254, 4 * 130, 80, 80, "images/entities/enemy4/enemy4.png", "images/entities/enemy4/fightingframes/enemy4-f1.png");
	Enemy *area3Enemy3 = new Enemy("33", 30, 8, "enemy4", 4 * 542, 4 * 124, 80, 80, "images/entities/enemy4/enemy4.png", "images/entities/enemy4/fightingframes/enemy4-f1.png");
	Enemy *area3Enemy4 = new Enemy("34", 30, 8, "enemy5", 4 * 532, 4 * 368, 80, 80, "images/entities/enemy5/enemy5.png", "images/entities/enemy5/fightingframes/enemy5-f1.png");
	Enemy *area3Enemy5 = new Enemy("35", 30, 8, "enemy5", 4 * 266, 4 * 312, 80, 80, "images/entities/enemy5/enemy5.png", "images/entities/enemy5/fightingframes/enemy5-f1.png");
	Enemy *area3Enemy6 = new Enemy("36", 30, 8, "enemy5", 4 * 194, 4 * 532, 80, 80, "images/entities/enemy5/enemy5.png", "images/entities/enemy5/fightingframes/enemy5-f1.png");
	enemies3.push_back(area3Enemy1);
	enemies3.push_back(area3Enemy2);
	enemies3.push_back(area3Enemy3);
	enemies3.push_back(area3Enemy4);
	enemies3.push_back(area3Enemy5);
	enemies3.push_back(area3Enemy6);
	vector<Boss *> bosses3;
	Boss *area3Boss = new Boss("27", 50, 10, "Boss3", 4 * 300, 4 * 450, 200, 200, "images/entities/Boss3/Boss3.png", "images/entities/Boss3/fightingframes/Boss3-f1.png");
	bosses3.push_back(area3Boss);
	vector<StaticTree *> Trees3;
	StaticTree *Area3Tree1 = new StaticTree("tree2", 4 * 180, 4 * 250);
	StaticTree *Area3Tree2 = new StaticTree("tree2", 4 * 100, 4 * 280);
	StaticTree *Area3Tree3 = new StaticTree("tree2", 4 * 200, 4 * 300);
	Trees3.push_back(Area3Tree1);
	Trees3.push_back(Area3Tree2);
	Trees3.push_back(Area3Tree3);
	vector<Orb *> Orbs3;
	Orb *Area3Orb1 = new Orb("Orb1", "Speed", 4 * 400, 4 * 450, "images/entities/Orb/BlueOrb.png");
	Orb *Area3Orb2 = new Orb("Orb1", "Health", 4 * 420, 4 * 450, "images/entities/Orb/GreenOrb.png");
	Orb *Area3Orb3 = new Orb("Orb1", "Damage", 4 * 414, 4 * 500, "images/entities/Orb/RedOrb.png");
	Orbs3.push_back(Area3Orb1);
	Orbs3.push_back(Area3Orb2);
	Orbs3.push_back(Area3Orb3);
	vector<Friend *> areaFriends3;
	Friend *friendsArea3 = new Friend(4 * 120, 4 * 342, 64, 64, "images/entities/player/downframes/player-ow-front1.png", "hello friend!");
	areaFriends3.push_back(friendsArea3);
	area3 = new Area(NULL, "images/areas/area3.png", "audio/ice.wav", "images/stages/stage2.png", entrancePosition3, enemies3, bosses3, Trees3, Orbs3, areaFriends3); 

	// Area 2

	vector<Enemy *> enemies2;
	ofPoint entrancePosition2(4 * 110, 4 * 116);
	Enemy *area2Enemy1 = new Enemy("21", 20, 6, "enemy2", 4 * 120, 4 * 342, 70, 70, "images/entities/enemy2/downframes/enemy2-ow-down1.png", "images/entities/enemy1/fightingframes/enemy2-f1.png");
	Enemy *area2Enemy2 = new Enemy("22", 20, 6, "enemy2", 4 * 254, 4 * 130, 70, 70, "images/entities/enemy2/downframes/enemy2-ow-down1.png", "images/entities/enemy1/fightingframes/enemy2-f1.png");
	Enemy *area2Enemy3 = new Enemy("23", 20, 6, "enemy2", 4 * 542, 4 * 124, 70, 70, "images/entities/enemy2/downframes/enemy2-ow-down1.png", "images/entities/enemy1/fightingframes/enemy2-f1.png");
	Enemy *area2Enemy4 = new Enemy("24", 20, 6, "enemy2", 4 * 532, 4 * 368, 70, 70, "images/entities/enemy2/downframes/enemy2-ow-down1.png", "images/entities/enemy1/fightingframes/enemy2-f1.png");
	Enemy *area2Enemy5 = new Enemy("25", 20, 6, "enemy2", 4 * 266, 4 * 312, 70, 70, "images/entities/enemy2/downframes/enemy2-ow-down1.png", "images/entities/enemy1/fightingframes/enemy2-f1.png");
	Enemy *area2Enemy6 = new Enemy("26", 20, 6, "enemy2", 4 * 194, 4 * 532, 70, 70, "images/entities/enemy2/downframes/enemy2-ow-down1.png", "images/entities/enemy1/fightingframes/enemy2-f1.png");
	enemies2.push_back(area2Enemy1);
	enemies2.push_back(area2Enemy2);
	enemies2.push_back(area2Enemy3);
	enemies2.push_back(area2Enemy4);
	enemies2.push_back(area2Enemy5);
	enemies2.push_back(area2Enemy6);
	vector<Boss *> bosses2;
	Boss *area2Boss = new Boss("27", 30, 8, "Boss2", 4 * 300, 4 * 450, 150, 150, "images/entities/Boss2/Boss2.png", "images/entities/Boss2/fightingframes/Boss2-f1.png");
	bosses2.push_back(area2Boss);
	vector<StaticTree *> Trees2;
	StaticTree *Area2Tree1 = new StaticTree("tree2", 4 * 180, 4 * 250);
	StaticTree *Area2Tree2 = new StaticTree("tree2", 4 * 100, 4 * 280);
	StaticTree *Area2Tree3 = new StaticTree("tree2", 4 * 200, 4 * 300);
	Trees2.push_back(Area2Tree1);
	Trees2.push_back(Area2Tree2);
	Trees2.push_back(Area2Tree3);
	vector<Orb *> Orbs2;
	Orb *Area2Orb1 = new Orb("Orb1", "Speed", 4 * 414, 4 * 500, "images/entities/Orb/BlueOrb.png");
	Orb *Area2Orb2 = new Orb("Orb1", "Health", 4 * 420, 4 * 450, "images/entities/Orb/GreenOrb.png");
	Orb *Area2Orb3 = new Orb("Orb1", "Damage", 4 * 250, 4 * 300, "images/entities/Orb/RedOrb.png");
	Orbs2.push_back(Area2Orb1);
	Orbs2.push_back(Area2Orb2);
	Orbs2.push_back(Area2Orb3);
	vector<Friend *> areaFriends2;
	Friend *friendsArea2 = new Friend(4 * 120, 4 * 342, 64, 64, "images/entities/player/downframes/player-ow-front1.png", "hello friend!");
	areaFriends2.push_back(friendsArea2);
	area2 = new Area(area3, "images/areas/area2.png", "audio/ice.wav", "images/stages/stage2.png", entrancePosition2, enemies2, bosses2, Trees2, Orbs2, areaFriends2); 

	
	// Area 1

	vector<Enemy *> enemies1;
	ofPoint entrancePosition1(4 * 414, 4 * 566);
	Enemy *area1Enemy1 = new Enemy("11", 10, 4, "enemy1", 4 * 480, 4 * 432);
	Enemy *area1Enemy2 = new Enemy("12", 10, 4, "enemy1", 4 * 225, 4 * 178);
	Enemy *area1Enemy3 = new Enemy("13", 10, 4, "enemy1", 4 * 420, 4 * 178);
	vector<Boss *> bosses1;
	Boss *area1Boss1 = new Boss("14", 20, 6, "Boss1", 4 * 200, 4 * 150);
	bosses1.push_back(area1Boss1);
	enemies1.push_back(area1Enemy1);
	enemies1.push_back(area1Enemy2);
	enemies1.push_back(area1Enemy3);
	vector<StaticTree *> Trees1;
	StaticTree *Area1Tree1 = new StaticTree("tree1", 4 * 300, 4 * 450);
	StaticTree *Area1Tree2 = new StaticTree("tree1", 4 * 150, 4 * 250);
	StaticTree *Area1Tree3 = new StaticTree("tree1", 4 * 500, 4 * 200);
	Trees1.push_back(Area1Tree1);
	Trees1.push_back(Area1Tree2);
	Trees1.push_back(Area1Tree3);
	vector<Orb *> Orbs1;
	Orb *Area1Orb1 = new Orb("Orb1", "Speed", 4 * 414, 4 * 500, "images/entities/Orb/BlueOrb.png");
	Orb *Area1Orb2 = new Orb("Orb1", "Health",  4 * 250, 4 * 300, "images/entities/Orb/GreenOrb.png");
	Orb *Area1Orb3 = new Orb("Orb1", "Damage", 4 * 350, 4 * 450, "images/entities/Orb/RedOrb.png");
	Orbs1.push_back(Area1Orb1);
	Orbs1.push_back(Area1Orb2);
	Orbs1.push_back(Area1Orb3);
	vector<Friend *> areaFriends1;
	Friend *friendsArea1 = new Friend(4 * 120, 4 * 342, 64, 64, "images/entities/player/downframes/player-ow-front1.png", "hello friend!");
	areaFriends1.push_back(friendsArea1);
	area1 = new Area(area2, "images/areas/area1.png", "audio/forest.wav", "images/stages/stage1.png", entrancePosition1, enemies1, bosses1, Trees1, Orbs1, areaFriends1);
	currentArea = area1;
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (currentState != nullptr)
	{
		currentState->tick();
		if (currentState->hasFinished())
		{
			currentState->toggleMusic();
			if (currentState->getNextState() == "Title")
			{
				endGameState->setWin(false);
				area1->resetEnemies();
				area2->resetEnemies();
				area3->resetEnemies();
				currentArea = area1;
				battleState->resetPlayer();
				battleState->setStage(currentArea->getStage());
				overworldState->loadArea(currentArea);
				currentState = titleState;
			}
			else if(currentState-> getNextState() == "Loading")
			{
				if(dynamic_cast<TitleState*> (currentState) != nullptr)
				{
					loadingState->setNextState("Overworld");
				}

				else if(dynamic_cast<OverworldState*> (currentState) != nullptr)
				{
					loadingState->setNextState("Battle");
				}

				else if(dynamic_cast<WinState*> (currentState) != nullptr)
				{
					loadingState->setNextState("Overworld");
				}

				currentState = loadingState;

			}
			else if (currentState->getNextState() == "Overworld")
			{
				currentState = overworldState;
			}
			else if (currentState->getNextState() == "Battle")
			{
				// if the previous state was not pause, the battle starts from the beginning
				// if the previous state was pause, the battle resumes from where it left off before PauseState
				if(!fromPause)
				{
					battleState->startBattle(overworldState->getEnemy());
				}

				fromPause = false;
				currentState = battleState;
			}
			else if(currentState->getNextState() == "Pause")
			{
				if(dynamic_cast<BattleState*> (currentState) != nullptr)
				{
					pauseState->setNextState("Battle");
				}
				else if(dynamic_cast<OverworldState*> (currentState) != nullptr)
				{
					pauseState->setNextState("Overworld");
				}
				else return;
								
				currentState = pauseState;
				fromPause = true;
			}
			else if (currentState->getNextState() == "Win")
			{
				overworldState->getEnemy()->kill();
				if (currentArea->getRemainingEnemies() == 0 && currentArea->getRemainingBoss() == 0)
				{
					if (currentArea->getNextArea() == NULL)
					{
						endGameState->setWin(true);
						currentState = endGameState;
					}
					else
					{
						currentArea = currentArea->getNextArea();
						overworldState->loadArea(currentArea);
						battleState->setStage(currentArea->getStage());
						currentState = winState;
					}
				}
				else
				{
					currentState = winState;
				}
			}
			else if (currentState->getNextState() == "End")
				currentState = endGameState;
			currentState->toggleMusic();
			currentState->reset();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	if (currentState != nullptr)
	{
		currentState->render();
	}

	if(currentState == overworldState)
	{
		ofSetColor(255);
		ofDrawBitmapString("Health: " + ofToString(battleState->getCurrentPlayerHealth()), 70, 20);	

		if(currentArea == area1)
		{
			ofSetColor(255);
			ofDrawBitmapString("Area 1", 10, 20);
			ofDrawBitmapString(" Enemies:  " + ofToString(area1->getRemainingEnemies()), 170, 20);
		}
		else if(currentArea == area2)
		{
			ofSetColor(0);
			ofDrawBitmapString("Area 2", 10, 20);
			ofDrawBitmapString("Enemies:  " + ofToString(area2->getRemainingEnemies()), 170, 20);
		}
		else if(currentArea == area3)
		{
			ofSetColor(255);
			ofDrawBitmapString("Area 3", 10, 20);
			ofDrawBitmapString("Enemies:  " + ofToString(area3->getRemainingEnemies()), 170, 20);
		}
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (currentState != nullptr)
		currentState->keyPressed(key);

	if (key == 'h')
	{
		battleState->resetPlayer();
	}
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	if (currentState != nullptr)
		currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
	if (currentState != nullptr)
		currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
	if (currentState != nullptr)
		currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}