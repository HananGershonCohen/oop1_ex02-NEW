#include "boardNEW.h"


board::board(const std::string& fileName) :m_fileName(fileName), m_robotLoc(), m_numRow(0),m_numCol(0)
{
    auto file = ifstream(fileName);
    if (!file) {
        std::cerr << "Error: Cannot open file " << fileName << endl;
        return;
    }

    string line; 
    while (getline(file, line)) // reading file.
    {
        updateLevel(line);
        m_numRow++;
        m_numCol = static_cast<int>(line.size());// Convert size_t to int explicitly to avoid potential data loss warning
    }
    m_numRow--;
    
}

int board::getRows()
{
    return m_numRow;
}

void board::updateLevel(const string line)
{
    m_level.push_back(line);
    for (int col = 0; col < line.size(); col++)
    {
        Location loc(m_numRow, col);
        if (line[col] == '/') m_robotLoc = loc;
        else if (line[col] == '!') m_guardLoc.push_back(loc);
       // else if (line[col] == '@') m_rockLoc.push_back(loc);
    }
}

void board::print() const
{
    for (int i = 0; i < m_level.size(); i++)
        cout << m_level[i] << endl ;
    cout << "m_numRow" << m_numRow << endl;
    cout << "m_numCol" << m_numCol << endl;

}

bool board::isInLevel(Location loc) const
{
    return loc.row >= 0 && loc.row <= m_numRow && loc.col >= 0 && loc.col <= m_numCol;
}


Location board::getRobot() const
{
    return m_robotLoc;
}

vector<Location> board::getVecGuard() const
{
    return m_guardLoc;
}

void board::setLocation(Location oldLoc, Location newLoc, char c)
{
    m_level[oldLoc.row][oldLoc.col] = ' ';
    m_level[newLoc.row][newLoc.col] = c;
}

bool board::isWall(Location loc) const
{
    return m_level[loc.row][loc.col] == '#';
}

bool board::isSpace(Location loc) const
{
    return m_level[loc.row][loc.col] == ' ';
}

bool board::isRobot(Location loc)const
{
    return m_level[loc.row][loc.col] == '/';
}

bool board::isRock(Location loc)const
{
    return m_level[loc.row][loc.col] == '@';

}

bool board::isDoor(Location loc)const
{
    return m_level[loc.row][loc.col] == 'D';

}
bool board::isGuard(Location loc) const
{
    return m_level[loc.row][loc.col] == '!';
}
//vector<Location> board::getVecRock() const
//{
//    return m_rockLoc;
//}
