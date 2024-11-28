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
   auto manger = Manger();
    manger.ran();


    return 0;
}
