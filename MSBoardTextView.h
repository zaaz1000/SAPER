#ifndef SAPER_2_MSBOARDTEXTVIEW_H
#define SAPER_2_MSBOARDTEXTVIEW_H
#include "MinesweeperBoard.h"

class MSBoardTextView
{
    MinesweeperBoard & board;

public:

    explicit  MSBoardTextView(MinesweeperBoard & B);
    void display();
};

#endif //SAPER_2_MSBOARDTEXTVIEW_H
