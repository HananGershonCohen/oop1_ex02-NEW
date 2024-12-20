#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Location.h"
#include <fstream>

using namespace std;

class board
{
public:
	board(const string&);
	int getRows();
	void print() const;
	void setLocation(Location oldLoc, Location newLoc, char);
	bool isSpace(Location) const;
	bool isRobot(Location)const;
	bool isRock(Location)const;
	bool isDoor(Location)const;
	bool isGuard(Location) const;
	bool isWall(Location) const;
	bool isInLevel(Location) const;
	Location getRobotFirstLoc() const;
	vector<Location> getVecGuardFirstLoc() const;
	//vector<Location> getVecRock() const;

private:
	string m_fileName;
	vector<string> m_level;
	vector<Location> m_guardLoc;
	//vector<Location> m_rockLoc;
	Location m_robotLoc;
	int m_numRow;
	int m_numCol;

	void updateLevel(const string);

};
