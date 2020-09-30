
#ifndef CRAZY8_GAME_HEADER_INCLUDED
#define CRAZY8_GAME_HEADER_INCLUDED


#include "deck.hpp"
#include "card.hpp"
#include "player.hpp"

class Game {
  private:
    Deck cards;
    Player players[2];
    Card pile;
    int nextSuit = -1;
    
  public:
    Game();
    //~Game(); // automatically provided

    void executeTurn(){
      printGameState();
      playCards();
    }
    bool checkGameEnd();
    bool canPutCard( Card* card );

  private:
    void printWin(){
      std::cout << "========================================\n"
        << "You Win!!" << std::endl;
    }
    void printLose(){
      std::cout << "========================================\n"
        << "You Lose..." << std::endl;
    }
    void printDraw(){
      std::cout << "========================================\n"
        << "Draw!" << std::endl;
    }
    void printGameState();
    void playCards();
};

#endif