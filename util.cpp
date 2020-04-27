
#include <string>
#include "util.hpp"

namespace util {
  std::string getSuitString( int suit ) {
    switch(suit){
      case 0:
        return "club";
      case 1:
        return "diamond";
      case 2:
        return "heart";
      case 3:
        return "space";
      default:
        return "";
    }
  };
  void toLower( std::string& s ){
    for( int t=0; t<s.length(); ++t ){
      if ( 'A' <= s[t] && s[t] <= 'Z' ) s[t] -= (char)('A' - 'a');
    }
  }
}