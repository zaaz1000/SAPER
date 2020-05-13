#ifndef SAPER_2_MSTEXTCONTROLER_H
#define SAPER_2_MSTEXTCONTROLER_H

#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"

class MinesweeperBoard;
class MSBoardTextView;

class MSTextController
{
    MSBoardTextView & view;
    MinesweeperBoard & board;

public:
    MSTextController(MSBoardTextView & V, MinesweeperBoard & B);
    void play();
};

#endif //SAPER_2_MSTEXTCONTROLER_H
