#ifndef __BOARD_H
#define __BOARD_H
#include <iostream>
#include <string.h>
#include "Direction.hpp"
#include <map>
using namespace std;

namespace ariel {

    class Board	{
        private:
          typedef pair <unsigned int, unsigned int> location; 
          map <location, char> mBoard;
        public:
          void post(unsigned int row, unsigned int column, Direction direction, const std::string &post);
          string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
          void show();
    };

}
#endif