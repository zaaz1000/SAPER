//
// Created by ludwi on 13.05.2020.
//

#include<iostream>
#include<stdlib.h>
#include"Field.h"
#include"MinesweeperBoard.h"
using std::cout;
using std::endl;

MinesweeperBoard::MinesweeperBoard (int width, int height, GameMode mode)
{
    status=RUNNING;

    this->width = width;
    this->height= height;
    float percent=0;

    board[width][height];
    for(int j=0; j<height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            board[i][j].hasFlag = false;
            board[i][j].hasMine = false;
            board[i][j].isRevealed = false;
        }
    }
    amount_of_mines=0;
    if(mode==EASY)
    {
        percent=0.1;
    }
    if(mode==NORMAL)
    {
        percent=0.2;
    }
    if(mode==HARD)
    {
        percent=0.3;
    }

    if (mode==DEBUG)
        for (int i=0; i<width;i++)
        {
            board[0][i].hasMine = true;
            for (int j=0; j<height; j++)
            {
                if (j==i)
                    board[j][i].hasMine = true;
                board[2*j][0].hasMine = true;
            }
        }
    amount_of_mines=width*height*percent;
    int mine_amount = amount_of_mines;
    while (mine_amount>0)
    {
        int a = rand()%height;
        int b = rand()%width;
        if (!board[a][b].hasMine)
        {
            board[a][b].hasMine = rand() % 2;
            if (board[a][b].hasMine)
                mine_amount--;
        }
    }
}

void MinesweeperBoard::debug_display() const
{
    for(int j=0; j<height; j++)
    {
        for (int i = 0; i <width; i++)
        {
            std::cout<<"[";
            if(board[i][j].hasMine==false)
            {
                std::cout<<".";
            } else{
                std::cout<<"M";
            }
            if(board[i][j].isRevealed==false)
            {
                std::cout<<".";
            } else{
                std::cout<<"O";
            }
            if(board[i][j].hasFlag==false)
            {
                std::cout<<".";
            } else{
                std::cout<<"F";
            }
            std::cout<<"]";

        }
        std::cout<<std::endl;
    }
}

int MinesweeperBoard::getBoardWidth() const
{
    return width;
}

int MinesweeperBoard::getBoardHeight() const
{
    return height;
}

int MinesweeperBoard::getMineCount()    const
{
    return amount_of_mines;
}

bool MinesweeperBoard::Outside(int x, int y)  const
{
    if (x>width||y>height)
    {
        return true;
    }
    else
        return false;
}

int MinesweeperBoard::countMines(int x, int y) const
{
    int mines=0;
    if ((!MinesweeperBoard::board[y][x].isRevealed)||!Outside(x, y))
        return -1;
    else
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j<2; j++)
            {
                if (MinesweeperBoard::board[x - 1 + i][y + j - 1].hasMine)
                    mines++;
            }
        }
    return mines;
}

bool MinesweeperBoard::hasFlag(int x, int y) const
{
    if(x>=width || y>=height || board[x][y].hasFlag==0 || board[x][y].isRevealed==1)
    {
        return false;
    }
    else if(board[x][y].hasFlag==1)
    {
        return true;
    }
    else
        return false;
}

bool MinesweeperBoard::hasMine(int x, int y) const
{
    if(x>=width || y>=height || board[x][y].hasMine==0 || board[x][y].isRevealed==1)
    {
        return false;
    }
    else if(board[x][y].hasMine==1)
    {
        return true;
    }
    else
        return false;
}


void MinesweeperBoard::toggleFlag(int x, int y)
{
    if (Outside(x,y)||isRevealed(x,y)||status != RUNNING)
        return;
    else if (!isRevealed(x,y)&&hasFlag(x,y))
        MinesweeperBoard::board[y][x].hasFlag = false;
    else if (!isRevealed(x,y)&&!hasFlag(x,y))
        MinesweeperBoard::board[y][x].hasFlag = true;
}

char MinesweeperBoard::getFieldInfo(int x, int y) const
{
    if (Outside(x,y))
        return '#';
    else if (!isRevealed(x,y)&&hasFlag(x,y))
        return 'F';
    else if (!isRevealed(x,y)&&!hasFlag(x,y))
        return '_';
    else if (isRevealed(x,y)&&MinesweeperBoard::board[y][x].hasMine)
        return 'x';
    else if (isRevealed(x,y)&&countMines(x,y)==0)
        return ' ';
    else if (isRevealed(x,y)&&countMines(x,y)!=0)
        return countMines(x,y);

}

GameState MinesweeperBoard::getGameState() const
{
    int mines1=amount_of_mines;
    int mines2=amount_of_mines;
    for (int i=0; i<getBoardHeight(); i++)
    {
        for (int j=0; j<getBoardWidth(); j++)
        {
            if (MinesweeperBoard::board[i][j].hasMine&&isRevealed(j, i))
                return FINISHED_LOSS;
            else if (MinesweeperBoard::board[i][j].hasMine&&hasFlag(j, i))
            {
                if (!MinesweeperBoard::board[i][j].hasMine&&hasFlag(j, i))
                    mines1++;
                mines1--;
                if (mines1==0)
                    return FINISHED_WIN;
            }
            else if (!isRevealed(j, i)&&MinesweeperBoard::board[i][j].hasMine)
            {
                mines2--;
                if (mines2==0)
                {
                    return FINISHED_WIN;
                }
            }
            else
                return RUNNING;
        }
    }
}

bool MinesweeperBoard::isRevealed(int x, int y) const
{
    if(board[x][y].isRevealed==1)
    {
        return true;
    }
    else
        return false;
}

bool MinesweeperBoard::first_move()
{
    int counter=0;
    for(int j=0; j<height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            if(board[i][j].isRevealed==false)
            {
                counter++;
            }

        }

    }
    if(counter==(width*height))
    {
        return true;
    }
    else
        return false;
}

void MinesweeperBoard::revealField(int x, int y)
{
    if(board[x][y].isRevealed==false && board[x][y].hasMine==false)
    {
        board[x][y].isRevealed=true;
    }
    else if(board[x][y].isRevealed==false && board[x][y].hasMine==true)
    {
        if(first_move()==1 && mode!=DEBUG)
        {
            board[x][y].hasMine=false;
            board[rand() % width][rand() % height].hasMine = true;
            board[x][y].isRevealed=true;
        }
        else
        {
            status=FINISHED_LOSS;
        }
    }
}
