#include "Guard.h"
#include "io.h"
#include "boardNEW.h"
Guard::Guard(const Location& location)
: m_location(location), m_first_loction (location)
{}

Location Guard::get_location() 
{
	return m_location;
}

void Guard::set_location(Location& location)
{
	m_location = location;
}

Location Guard::get_first_loction()
{
	return m_first_loction;
}

void Guard::print(Location newLoc)
{
	Screen::setLocation(m_location);
	std::cout << ' ';
	Screen::setLocation(newLoc);
	std::cout << '!';
}


void Guard::move(board& board)
{
	bool moved = false;
	while (!moved) // לולאה שתמשיך לנסות עד שהשומר יזוז
	{
		Location newLoc = chooseNewLocation(m_location);
		if (!board.isWall(newLoc) && !board.isRock(newLoc) && board.isInLevel(newLoc))
		{
			
			moved = true; // שים לב, עכשיו השומר זז
			print(newLoc); // הדפסת המיקום החדש		
			if (board.isRobot(newLoc))
			{
				cout << "stop the game";
				// stop the game
			}
			board.setLocation(m_location, newLoc, '!');
			m_location = newLoc; // עדכון מיקום השומר
		}
	}
}


Location Guard::chooseNewLocation(Location loc)
{
	Location newLoc = loc;

	// random move.
	int direction = rand() % 4; // 0 = למעלה, 1 = למטה, 2 = שמאלה, 3 = ימינה
	//direction = 0;
	switch (direction)
	{
	case 0: // move up.
		newLoc.row--;
		break;

	case 1: // move down.
		newLoc.row++;
		break;

	case 2: // move left.
		newLoc.col--;
		break;

	case 3: // move right.
		newLoc.col++;
		break;
	}
	return newLoc;
}

