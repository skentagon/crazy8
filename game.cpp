
#include "deck.hpp"
#include "card.hpp"
#include "player.hpp"
#include "game.hpp"
#include "util.hpp"

Game::Game(){
  // deal 7 cards
  for( int i=0; i<2; ++i ){
    for( int j=0; j<7; ++j ){ players[i].push(cards.pop()); }
  }
  // set players info
  players[0].setName("player");
  players[0].setType(Player::Type::player);
  players[1].setName("COM");
  players[1].setType(Player::Type::com);
  pile = cards.pop();
  std::cout << "Game initialization completed." << std::endl;
}

bool Game::checkGameEnd(){
  if ( players[0].getCardsNum() == 0 ){
    printWin();
    return true;
  }
  if ( players[1].getCardsNum() == 0 ){
    printLose();
    return true;
  }
  if ( cards.getCardsNum() == 0 ){
    if ( players[0].getCardsNum() < players[1].getCardsNum() ){
      printWin();
      return true;
    } else if ( players[0].getCardsNum() == players[1].getCardsNum() ){
      printDraw();
      return true;
    } else {
      printLose();
      return true;
    }
  }
  return false;
}

bool Game::canPutCard( Card* card ){
  if ( card->getRank() == 8 ) return true;
  if ( card->getRank() == pile.getRank() ) return true;
  if ( nextSuit == -1 && pile.getSuit() == card->getSuit() ) return true;
  if ( nextSuit == card->getSuit() ) return true;
  return false;
}

void Game::printGameState(){
  std::cout << "========================================\n"
    << "The number of left cards in deck : " << cards.getCardsNum() << "\n";
  for( int i=0; i<2; ++i ){
    std::cout << players[i].getName() << "'s left cards : " << players[i].getCardsNum() << "\n";
  }
  std::cout << "Your cards:" << std::endl;
  for( int i=0; i<players[0].getCardsNum(); ++i ){
    if ( canPutCard(players[0].getCard(i)) ){
      std::cout << "\033[34m\033[1m";
    } else {
      std::cout << "\033[31m";
    }
    std::cout
      << std::setfill(' ')
      << std::setw(2)
      << (i+1)
      << "\033[m : ";
    players[0].getCard(i)->printCard();
    std::cout << "\n";
  }
  std::cout << "Current pile: ";
  if ( nextSuit == -1 ){
    pile.printCard();
  } else {
    std::cout << "\033[31m";
    pile.printCard();
    std::cout << "\033[m ( next suit is \033[1m'" << util::getSuitString(nextSuit) << "'\033[m )";
  }
  std::cout << std::endl;
}

void Game::playCards(){
  for( int i=0; i<2; ++i ){
    int next;
    int cmd = players[i].getCmd(this,&next);
    if ( cmd == -1 ) { // draw card
      players[i].push(cards.pop());
      if (!cards.getCardsNum()) return; // No cards in deck
    } else {
      pile = *players[i].getCard(cmd);
      nextSuit = -1;
      if ( pile.getRank() == 7 ) nextSuit = next;
      players[i].pop(cmd);
    }
  }
}