  #include "Manger.h"
#include "boardNEW.h"
#include "Board.h"
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
using namespace std;

int main()
{
  /* auto manger = Manger();
    manger.ran();*/

    board board("level01.txt");
    board.print();

    vector <Guard> guards_location;
    vector<Rock> rocks_location;
    Robot robot(board.getRobot());

    for (int i = 0; i < board.getVecGuard().size(); i++)
    {
        guards_location.push_back(board.getVecGuard().at(i));
    }

    for (int i = 0; i < board.getVecRock().size(); i++)
    {
        rocks_location.push_back(board.getVecRock().at(i));
    }

    return 0;
}
