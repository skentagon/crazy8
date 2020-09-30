
#ifndef CRAZY8_CARD_HEADER_INCLUDED
#define CRAZY8_CARD_HEADER_INCLUDED

#include <iostream>
#include <iomanip>
#include "util.hpp"

class Card {
  private:
    int rank; // Should be in the range 0-12.
    int suit; // Should be in the range 0-3.

  public:
    Card() = default; // use default constructor
    Card( int rank, int suit ) : rank(rank), suit(suit) {}
    ~Card(){}; // automaticaly provided

    // accessors
    int getRank() const { return rank; }
    int getSuit() const { return suit; }
    void setRank( int rank ){
      if ( 0<=rank && rank < 13){
        this->rank = rank;
      }
    }
    void setSuit( int suit ){
      if ( 0<=rank && rank < 4 ){
        this->suit = suit;
     }
    }
    void printCard(){
      std::cout << "["
        << std::setfill(' ')
        << std::setw(7)
        << getSuitString()
        << "-"
        << std::setw(2)
        << getRankString()
        << "]";
    }


    
  private:
    std::string getSuitString() const { return util::getSuitString(suit); }
    std::string getRankString() const {
      switch(rank){
        case 0: // represents 1
          return "A";
        case 10: // represents 11
          return "J";
        case 11: // represents 12
          return "Q";
        case 12: // represents 13
          return "K";
        default:
          return std::to_string(rank+1);
      }
    }
};

#endif