#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextControler.h"
#include <ctime>

int main()
{
    srand(time(NULL));
    MinesweeperBoard B1(10, 10, NORMAL);
    MSBoardTextView view(B1);
    MSTextController ctrl ( view,B1 );
    B1.debug_display();
    view.display();
    ctrl.play();

    return 0;
}