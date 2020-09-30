
#include <string>
#include <iostream>
#include <algorithm>
#include "Ncursescpp/src/Ncurses.hpp"

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "game.hpp"



int main(){

  while(true){

    // initializae Game
    Game game;

    // execute
    while(!game.checkGameEnd()){
      game.executeTurn();
    }

    std::cout << "========================================\n"
      << "Do you wanna play again? [Y/n]" << std::endl;
    std::string input;
    std::cin >> input;
    //std::transform( input.begin(), input.end(), input.begin(), ::tolower );
    if ( input == "n" || input == "no" || input == "" ){
      std::cout << "bye!" << std::endl;
      break;
    }

  }

  return 0;

}