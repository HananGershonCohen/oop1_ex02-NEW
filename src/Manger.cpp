#include "Manger.h"
#include "boardNEW.h"
#include "io.h"
#include "Location.h"
#include <conio.h>
#include"Rock.h"
#include"ExitDoor.h"
#include"Bomb.h"
#include"Wall.h"
#include"Robot.h"
#include"Guard.h"
#include"Space.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>


using namespace std::chrono_literals;

void Manger::ran()
{

    board board("level01.txt");
    board.print();

    Robot robot = board.getRobotFirstLoc();

    vector <Guard> guards_location;
    //vector<Rock> rocks_location;

    for (int i = 0; i < board.getVecGuardFirstLoc().size(); i++)
    {
        guards_location.push_back(board.getVecGuardFirstLoc().at(i));
    }

 /*   for (int i = 0; i < board.getVecRock().size(); i++)
    {
        rocks_location.push_back(board.getVecRock().at(i));
    }*/


        for (int i = 0; i < guards_location.size(); i++)
        {
            guards_location[i].move(board);                
            std::this_thread::sleep_for(100ms);

            if (guards_location[i].getTouch()) // if guard touch at robot.
            {
                break;
            }
        }
    

    Screen::setLocation(Location(board.getRows()+1,0));

   
}
