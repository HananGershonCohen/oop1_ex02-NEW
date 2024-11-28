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

    vector <Guard> guards_location;
    vector<Rock> rocks_location;
    Robot robot(board.getRobot());

    for (int i = 0; i < board.getVecGuard().size(); i++)
    {
        guards_location.push_back(board.getVecGuard().at(i));
    }

 /*   for (int i = 0; i < board.getVecRock().size(); i++)
    {
        rocks_location.push_back(board.getVecRock().at(i));
    }*/

    while (true){
        for (int i = 0; i < guards_location.size(); i++)
        {
            guards_location[i].move(board);
            std::this_thread::sleep_for(100ms);
        }
    }

    Screen::setLocation(Location(board.getRows()+1,0));


    //Board board("level01.txt");

    //board.print();

    //Location robot_location = board.getRobot_ferst_Location();
    //Robot robot(robot_location);

    //vector <Guard> guards_location = board.get_gard_ferst_location();
    //vector <Bomb> bombs_location;
    //
    ////// ����� ������
    //int row = robot_location.row;
    //int col = robot_location.col;
    //char** level = board.getLevel();
    //int rowCount = board.getRowCount();
    //int colCount = board.getColCount();

    //board.print();

   
    //for (int i = 0; i < 10; i++)
    //{

    //    if (_getch() == Keys::SPECIAL_KEY)
    //    {
    //        int move = _getch();

    //        // ����� ����� ���
    //        int newRow = row, newCol = col;
    //        if (move == SpecialKeys::UP && row > 0) newRow = row - 1;
    //        else if (move == SpecialKeys::DOWN && row < rowCount - 1) newRow = row + 1;
    //        else if (move == SpecialKeys::LEFT && col > 0) newCol = col - 1;
    //        else if (move == SpecialKeys::RIGHT && col < colCount - 1) newCol = col + 1;

    //        // ����� ����
    //        if (level[newRow][newCol] == ' ') {
    //            level[row][col] = ' ';
    //            level[newRow][newCol] = '/';
    //            row = newRow;
    //            col = newCol;
    //            robot.setLocation(Location(row, col));
    //        }

    //        // ����� ���� ����

    //       // board.print();
    //    }

    //    else //its a bomb
    //        bombs_location.push_back(Bomb(robot.get_location()));



    //    int size = bombs_location.size();
    //    for (int i = 0; i < size; i++)
    //    {
    //        if (bombs_location.at(i).isExploded())
    //        {
    //            level[bombs_location.at(i).getLocation().row][bombs_location.at(i).getLocation().col] = ' ';
    //            bombs_location.erase(bombs_location.begin());
    //            i--;
    //            size--;
    //            continue;
    //        }

    //        else if (bombs_location.at(i).isExploding())
    //            level[bombs_location.at(i).getLocation().row][bombs_location.at(i).getLocation().col] = '*';


    //        else
    //            level[bombs_location.at(i).getLocation().row][bombs_location.at(i).getLocation().col] = '0' + bombs_location.at(i).showTime();

    //        bombs_location.at(i).renwTime();

    //    }

    //  //  board.print();


    //    for (int i = 0; i < guards_location.size(); i++)
    //    {
    //        guards_location[i].move(board);
    //        std::this_thread::sleep_for(1000ms);
    //    }
    //}


   
}
