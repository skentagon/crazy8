
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
  }
}