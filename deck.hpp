
#ifndef CRAZY8_DECK_HEADER_INCLUDED
#define CRAZY8_DECK_HEADER_INCLUDED

#include <exception>
#include <random>
#include "card.hpp"

class Deck {
  private:
    Card cards[52];
    int n_cards; // Number of cards remaining in the deck.

  public:
    Deck(){
      // prepare 52 cards
      n_cards = 52;
      for( int i=0; i<n_cards; ++i ){ cards[i] = Card( i%13, i/13 ); }
      //sufflel;
      std::random_device seed_gen;
      std::mt19937_64 engine(seed_gen());
      for( int i=0; i<10000; ++i ){
        swapCards( static_cast<int>(engine()%52), static_cast<int>(engine()%52) );
      }
      std::cout << "Deck initialization completed." << std::endl;
    }
    ~Deck(){}; // automatically provided

    int getCardsNum() const { return n_cards; }

    Card pop(){ // get top card
      //if (!n_cards) throw std::runtime_error("cards don't exist");
      --n_cards;
      return cards[n_cards];
    }
  
  private:
    void swapCards( int dx1, int dx2 ){
      Card tmp = cards[dx1];
      cards[dx1] = cards[dx2];
      cards[dx2] = tmp;
    }

};


#endif