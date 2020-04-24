
#ifndef CRAZY8_PLAYER_HEADER_INCLUDED
#define CRAZY8_PLAYER_HEADER_INCLUDED

#include <algorithm>
#include <string>
#include "card.hpp"
#include "hand.hpp"

class Game;
class Player {
  public:
    enum Type {
      player,
      com
    };

  private:
    Hand hand;
    std::string name;
    Type type;

  public:
    // Player(); // automatically provided
    // ~Player(); // automatically provided
    int getCardsNum() const { return hand.getCardsNum(); }
    Card* getCard( int index ) const { return hand.getCard(index); }
    const std::string& getName(){ return name; }
    void setName( const std::string& name ){ this->name = name; }
    void setType( Type t ){ type = t; }
    
    void pop( int dx ){ hand.pop(dx); } // play a card
    void push( Card top ){ hand.push(top); } // draw a card

    int getCmd( Game* game, int* next );
};


#endif