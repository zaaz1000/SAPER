#include <iostream>
#include "MSTextControler.h"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include<conio.h>

MSTextController::MSTextController(MSBoardTextView & V, MinesweeperBoard & B) :view(V), board(B)
{

}

void MSTextController::play()
{
    int a, x, y;
    while(board.getGameState()==RUNNING)
    {
        std::cout<<" 1. Odkryj pole x, y "<<std::endl;
        std::cout<<" 2. Postaw flage na polu x, y "<<std::endl;
        std::cout<<" 3. Wyjdz z gry "<<std::endl;
        std::cin>>a;
        switch(a)
        {
            case 1:
                std::cout << "Podaj x pola ,ktore chcesz odkryc"<<std::endl;
                std::cin >> x;
                std::cout<<"Podaj y pola, ktore chcesz odkryc"<<std::endl;
                std::cin>>y;
                board.revealField(x, y);
                view.display();
                if (board.hasFlag(x,y) == true)
                {
                    std::cout << "Postawies na tym polu juz flage" << std::endl;
                    std::cout << "Podaj x innego pola" << std::endl;
                    std::cin >> x;
                    std::cout<<"Podaj y innego pola"<<std::endl;
                    std::cin>>y;
                    board.revealField(x, y);
                    view.display();
                }
                if (board.hasMine(x,y))
                {
                    std::cout << "Trafies na mine, przegrales" << std::endl;
                    getch();
                    exit(0);
                }
                break;
            case 2:
                std::cout << "Podaj x pola, na ktorym chcesz postawic flage" << std::endl;
                std::cin >> x;
                std::cout<<"Podaj y pola, na ktorym chcesz postawic flage"<<std::endl;
                std::cin>>y;
                board.toggleFlag(x, y);
                view.display();
                if (board.hasFlag(x,y) == true)
                {
                    std::cout << "juz postawiles flage na tym polu" << std::endl;
                    std::cout << "Podaj x innego pola" << std::endl;
                    std::cin >> x;
                    std::cout<<"Podaj y innego pola"<<std::endl;
                    std::cin>>y;
                    board.toggleFlag(x, y);
                    view.display();
                }
                else if (board.isRevealed(x,y) == true)
                {
                    std::cout << "nie mozesz postawic tu flagi, juz odkryles to pole" << std::endl;
                    std::cout << "Podaj x innego pola" << std::endl;
                    std::cin >> x;
                    std::cout<<"Podaj y innego pola"<<std::endl;
                    std::cin>>y;
                    board.toggleFlag(x, y);
                    view.display();
                }
                break;
            case 3:
                exit(0);
        }
    }
    if(board.getGameState()==FINISHED_WIN)
    {
        std::cout << "Wygrales" << std::endl;
        getch();
        exit(0);
    }
    if(board.getGameState()==FINISHED_LOSS)
    {
        std::cout<<"Przegrales"<<std::endl;
        getch();
        exit(0);
    }
}

