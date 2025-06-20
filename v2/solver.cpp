#include <bits/stdc++.h>
#include "guesser.cpp"

const int WORD_SIZE=5;
const int GUESS_LIMIT=6;
std::list<std::string> wList;

signed main(){
    std::string guessWord;
    std::cin >> base;
    std::ifstream file("words.txt");
	if (!file.is_open()) {
		std::cerr << "fail to open\n";
		return 1;
	}
    std::string line;
	while (std::getline(file, line)) {
		wList.push_back(line);
	}
    file.close();
    guess(WORD_SIZE,wList,GUESS_LIMIT);
}