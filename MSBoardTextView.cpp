#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
#include "MSTextControler.h"
#include <stdlib.h>
#include <iostream>


MSBoardTextView::MSBoardTextView(MinesweeperBoard & B) : board(B)
{

}

void MSBoardTextView::display()
{
    std::cout<<"   0  1  2  3  4  5  6  7  8  9  x"<<std::endl;
    for(int y=0; y<board.getBoardHeight(); y++)
    {
        std::cout<<y<<" ";
        for(int x=0; x<this->board.getBoardWidth(); x++)
        {
            std::cout<<"[";
            std::cout<<board.getFieldInfo(x,y);
            std::cout<<"]";
        }


        std::cout<<" |"<<std::endl;
    }
    std::cout<<"y--------------------------------"<<std::endl;
}