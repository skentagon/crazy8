
#ifndef CRAZY8_HAND_HEADER_INCLUDED
#define CRAZY8_HAND_HEADER_INCLUDED

#include "card.hpp"

class Hand {
  private:
    Card *cards = nullptr;
    int n_cards = 0;
  public:
    Hand(){} // automatically provided
    ~Hand(){
      delete[] cards;
    }

    int getCardsNum() const { return n_cards; }
    Card* getCard( int index ) const { return &cards[index]; }

    void push( Card card ){
      ++n_cards;
      Card* temp = new Card[n_cards];
      for( int i=0; i<n_cards-1; ++i ){
        temp[i] = cards[i];
      }
      temp[n_cards-1] = card;
      delete[] cards;
      cards = temp;
    }
    void pop( int index ){
      --n_cards;
      Card* temp = new Card[n_cards];
      int tdx = 0;
      for( int i=0; i<n_cards+1; ++i ){
        if ( index == i )continue;
        temp[tdx] = cards[i];
        ++tdx;
      }
      delete[] cards;
      cards = temp;
    }
};


#endif