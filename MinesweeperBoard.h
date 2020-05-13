#ifndef SAPER_2_MINESWEEPERBOARD_H
#define SAPER_2_MINESWEEPERBOARD_H
#include"Field.h"

enum GameMode { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

class MinesweeperBoard
{

    GameMode mode;
    int width, height, amount_of_mines;
    GameState status;
    bool Outside(int x, int y) const;
    Field board[100][100];

public:

    GameState getGameState() const;

    void revealField(int x, int y);

    explicit MinesweeperBoard(int width=10, int height=10, GameMode mode=EASY);

    int getBoardWidth() const;

    int getBoardHeight() const;

    int getMineCount() const;

    int countMines(int x, int y) const;

    bool hasFlag(int x, int y) const;

    bool hasMine(int x, int y) const;

    bool first_move();

    void toggleFlag(int x, int y);

    bool isRevealed(int x, int y) const;

    char getFieldInfo(int x, int y) const;

    void debug_display() const;

};

#endif //SAPER_2_MINESWEEPERBOARD_H
