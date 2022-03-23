
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;
namespace ariel{

    class Notebook{
        public:
            Notebook(){}
            //
            void write(int,int,int, Direction , string);
            string read(int,int,int, Direction, int);
            void erase(int,int,int, Direction, int);
            void show(int);
    };

}