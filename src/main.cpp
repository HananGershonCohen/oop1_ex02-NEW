  #include "Manger.h"
#include "boardNEW.h"
using namespace std;

int main()
{
  /* auto manger = Manger();
    manger.ran();*/

    board board("level01.txt");

    board.print();

    return 0;
}
