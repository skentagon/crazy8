
#include <string>
#include <iostream>

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "game.hpp"
#include "util.hpp"



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
    util::toLower(input);
    if ( input == "n" || input == "no" || input == "" ){
      std::cout << "bye!" << std::endl;
      break;
    }

  }

  return 0;

}