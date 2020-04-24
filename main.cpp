
#include <string>
#include <iostream>
#include <algorithm>

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "game.hpp"

int main(){

  try {

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
      std::transform( input.begin(), input.end(), input.begin(), ::tolower );
      if ( input == "n" || input == "no" || input == "" ){
        std::cout << "bye!" << std::endl;
        std::exit(EXIT_SUCCESS);
      }

    }
  
  } catch(std::runtime_error& e) {
    std::cerr << "runtime_error : " << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  } catch(...) {
    std::cerr << "unknown error" << std::endl;
    std::exit(EXIT_FAILURE);
  }

}