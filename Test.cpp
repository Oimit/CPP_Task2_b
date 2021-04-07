#include "Direction.hpp"
#include "Board.hpp"
#include "doctest.h"
#include <string>
using namespace std;
using namespace ariel;


TEST_CASE("funcutions: post & read:"){
ariel::Board board;
board.post(1, 1,Direction::Horizontal, "hello world");
CHECK(board.read(1, 1, Direction::Horizontal, 2) == "hello world");


board.post(100, 200, Direction::Horizontal, "Amit");
CHECK(board.read(100, 200, Direction::Horizontal, 3) == "Amit");

board.post(10, 20, Direction::Vertical, "Harry");
CHECK(board.read(10, 20, Direction::Vertical, 4) == "Harry");

board.post(100, 201, Direction::Vertical, "Potter");
CHECK(board.read(99, 200, Direction::Horizontal, 13) == "Poter");

board.post(500, 498, Direction::Vertical, "shalom");
CHECK(board.read(501, 498, Direction::Vertical, 6) == "shal");

board.post(1032, 1030, Direction::Vertical, "Pokemon");
CHECK(board.read(1032, 1030, Direction::Vertical, 15) == "Pokemins");

board.post(3730, 3830, Direction::Horizontal, "C++");
CHECK(board.read(3729, 3833, Direction::Vertical, 3) == "C");

board.post(1024, 1029, Direction::Horizontal, "Java");
CHECK(board.read(1024, 1029, Direction::Horizontal, 4) == "Javaa");

board.post(333, 333, Direction::Vertical, "Professor");
CHECK(board.read(333, 333, Direction::Vertical, 9) == "Professor");
CHECK(board.read(333, 333, Direction::Vertical, 10) == "Professor");


board.post(400000, 400005, Direction::Horizontal, "Python");
CHECK(board.read(400000, 400005, Direction::Horizontal, 7) == "python*");

        
board.post(0, 2, Direction::Horizontal, "salam");
CHECK(board.read(0, 0, Direction::Horizontal, 10) == "vvv");
CHECK(board.read(10, 25, Direction::Horizontal, 15) == "vvvv");
CHECK(board.read(0, 2, Direction::Horizontal, 5) == "salam");

board.post(100, 101, Direction::Horizontal, "Cristiano Ronaldo");
CHECK(board.read(99, 101, Direction::Horizontal, 9) == "Ronaldo");
CHECK(board.read(100, 119, Direction::Horizontal, 15) == "Cristiano ron");

}

TEST_CASE("bad cases:"){
ariel::Board board;
board.post(32, 36, Direction::Vertical, " ");
CHECK(board.read(32,36, Direction::Vertical, 9) == "test fail");

board.post(1, 10, Direction::Horizontal, " ");
CHECK(board.read(1,10, Direction::Horizontal, 5) == "error");

board.post(100000, 2, Direction::Horizontal, " ");
CHECK(board.read(100000, 2, Direction::Horizontal, 2) == "incorrect");

board.post(4000, 5000, Direction::Vertical, " ");
CHECK(board.read(4000,5000, Direction::Vertical, 9) == "failed");


}