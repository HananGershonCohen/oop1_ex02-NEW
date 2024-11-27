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
	void print() const;
	bool isInLevel(Location) const;
	bool isWall(Location) const;
	Location getRobot() const;
	vector<Location> getVecGuard() const;
	vector<Location> getVecRock() const;

private:
	string m_fileName;
	vector<string> m_level;
	vector<Location> m_guardLoc;
	vector<Location> m_rockLoc;
	Location m_robotLoc;
	int m_numRow;
	int m_numCol;

	void updateLevel(const string);

};
