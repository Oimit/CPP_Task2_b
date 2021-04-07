#include "Board.hpp"
#include "Board.cpp"
#include "Direction.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;
using ariel::Direction;

int main() {
	ariel::Board board;
    string message;
    Direction dir;
    
    unsigned int r;
    unsigned int c;
    unsigned int userDir;
    cout << "Please Enter a row:\n";
    cin >> r;
    cout << "Please enter a column\n";
    cin >> c;
    cout << "Please enter a word you would like to publish:\n";
    cin >> message;
    cout << "In which direction would you like to publish you word?\n"
           << "1 = Vertical, 2 = Horizontal\n";
    cin >> userDir;

    if (userDir == 1) {
        dir = Direction::Vertical;
    }
    else {
        dir = Direction::Horizontal;
    }

	board.post(0,0,Direction::Horizontal,"hello");//5
	board.post(1,2,Direction::Vertical,"my");//2
	board.post(2,4,Direction::Horizontal,"name");//4
	board.post(3,6,Direction::Vertical,"is");//2
	board.post(4,8,Direction::Horizontal,"Amit.");//4
	board.post(5,10,Direction::Vertical,"How");//3
	board.post(6,12,Direction::Horizontal,"are");//3
	board.post(7,14,Direction::Vertical,"you");//3
	board.post(8,16,Direction::Horizontal,"today");//5
	board.post(9,18,Direction::Vertical,"?");//1

    board.post(r, c, dir, message);

	board.show();
}
