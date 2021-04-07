#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <string.h>
using namespace std;
namespace ariel {


	string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length) {
		
		string ans;
		for (unsigned int i = 0; i < length; i++) {
			pair<unsigned int, unsigned int> myPair;
			if (direction == Direction::Horizontal) {
				myPair = pair<unsigned int, unsigned int>(row, column + i);
			}
			else {
				myPair = pair<unsigned int, unsigned int>(row + i, column);
			}
			try {
				char result = mBoard.at(myPair);
				ans += result;
			}
			catch (...) {
				ans += "_";
			}
		}
		return ans;
	}

	void Board::post(unsigned int row, unsigned int column, Direction direction, const string &post) {

		for (unsigned int i = 0; i < post.length(); i++) {
			if (direction == Direction::Horizontal) {
				pair<unsigned int, unsigned int> myPair = pair<unsigned int, unsigned int>(row, column + i);
				mBoard[myPair] = post[i];
			}
			else {
				pair<unsigned int, unsigned int> myPair = pair<unsigned int, unsigned int>(row + i, column);
				mBoard[myPair] = post[i];
			}
		}
	}

void Board::show() {
	unsigned int lastUse = 0;
	unsigned int lastColum = 0;
	for (auto itr = mBoard.begin(); itr != mBoard.end(); ++itr) {
		unsigned int currentUse = (itr->first).first;	
		if (lastUse != currentUse) {
			cout << endl;
			lastColum = 0;
			lastUse = currentUse;
		}
		unsigned int spaces = (itr->first).second - lastColum;
		if(spaces > 1){
			for(unsigned int i = 0; i < spaces; i++){
				cout << " - ";
			}
		}
		lastColum = (itr->first).second;
		cout << itr->second;
		
	}
	cout << endl;
}
}