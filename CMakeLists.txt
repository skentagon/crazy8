cmake_minimum_required(VERSION 2.8)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D NDEBUG")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D -Wbad-function-cast -Wconversion -Wctor-dtor-privacy -Wdouble-promotion -Weffec++ -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat-y2k -Winit-self -Wmultichar -Wold-style-cast -Wpedantic -Wpointer-arith -Wredundant-decls -Wreorder -Wsuggest-attribute=const -Wsuggest-attribute=format -Wsuggest-attribute=noreturn -Wsuggest-attribute=pure -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef -Wunsafe-loop-optimizations -Wunsuffixed-float-constants -Wuseless-cast -Wwrite-strings -Wzero-as-null-pointer-constant -Wunused-macros")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D -Wdelete-non-virtual-dtor -Wdisabled-optimization -Wnoexcept -Woverloaded-virtual -Wpacked -Wsign-promo -Wold-style-definition -Wstrict-prototypes -Wvariadic-macros")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D -Wabi-tag -Waggregate-return -Wcast-align -Wcast-qual -Wconditionally-supported -Wdate-time -Wfloat-equal -Wpadded -Wshadow -Wsystem-headers -Wtraditional -Wtraditional-conversion -Wvector-operation-performance")
# -Wc++-compat -Wc++0x-compat -Wc++14-compat -Wtrampolines
find_package(Threads REQUIRED)

project(crazy8)

if(MSVC)
  # Force to always compile with W4
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

add_executable(crazy8
  main.cpp
  game.cpp
  player.cpp
  util.cpp
)