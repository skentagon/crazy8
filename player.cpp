
//#include <algorithm>
#include <string>
#include "card.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "game.hpp"
#include "util.hpp"

int Player::getCmd( Game* game, int* next ){
  if ( type == 1 ){ // COM
    int rv = -1; // return value
    for( int i=0; i<getCardsNum(); ++i ){
      if ( getCard(i)->getRank() == 7 ){
        rv = i;
        continue;
      }
      if ( game->canPutCard(getCard(i)) ) return i;
    }
    if ( rv == -1 )return -1;
    // select the most common suit
    int cnt[4] = {0};
    for( int i=0; i<getCardsNum(); ++i ){
      if ( getCard(i)->getRank() == 7 ) continue;
      ++cnt[getCard(i)->getSuit()];
    }
    *next = 0;
    for( int i=0; i<4; ++i ){ if ( cnt[*next] < cnt[i] ) *next = i; }
    return rv;
  } else { // player
    while(true){
      std::cout << "Please enter selected card number. If you want to pick card, please input -1." << std::endl;
      int t; std::cin >> t;
      if ( t == -1 ) return -1;
      if ( t<0 || getCardsNum()<t ){
        std::cout << "Invalid input. Card number should be (0," + getCardsNum() << "] or -1." << std::endl;
        continue;
      }
      if ( !game->canPutCard(getCard(t-1)) ){
        std::cout << "You cannot use the card: ";
        getCard(t-1)->printCard();
        std::cout << std::endl;
        continue;
      }
      if ( getCard(t-1)->getRank() == 7 ){
        while(true){
          std::cout << "Please selecte the next suit. (club,diamond,heart,space)" << std::endl;
          std::string s; std::cin >> s;
          //std::transform( s.begin(), s.end(), s.begin(), ::tolower );
          util::toLower(s);
          if ( s == "club" || s == "c" ){
            *next = 0;
            break;
          }
          if ( s == "diamond" || s == "d" ){
            *next = 1;
            break;
          }
          if ( s == "heart" || s == "h" ){
            *next = 2;
            break;
          }
          if ( s == "space" || s == "s" ){
            *next = 3;
            break;
          }
          std::cout << "Invalid input." << std::endl;
        }
      }
      return (t-1);
    }
  }
}