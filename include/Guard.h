#pragma once
#include "Location.h"
#include <fstream>
#include <iostream>
#include <string>
class board;

class Guard
{
public:
	Guard(const Location& location);
	Location get_location();
	void set_location(Location& location);
	Location get_first_loction();
	void print(Location);
	void move(board&); // NOT CONST!!
	//bool isLeagalMove(Location, Board&) const;
	Location chooseNewLocation(Location);
	
 private:
	 Location m_location;
	 Location m_first_loction;
};

