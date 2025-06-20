#include <bits/stdc++.h>

std::vector<int> getResult(std::string& guess){
    std::vector<int> res(guess.size());
	std::cout << guess << '\n';
    for(int i=0;i<guess.size();i++){
		char in;
		std::cin >> in;
        res[i] = in-'0';
		//0->none 1->somewhere 2->right
    }
	//std::cout << 'D';
	return res;
}

std::vector<int> getResultTest(std::string& guess,std::string& base){
    std::vector<int> res(guess.size());
    for(int i=0;i<guess.size();i++){
		if(guess[i]==base[i]);
    }
	return res;
}

std::set<char> exist;
std::vector<std::set<char>> invalidP;
std::string guess;
std::string fe;
std::list<std::string> possibleAnswer;

long long getSizeAfter(std::string guess){
	long long count = 0;
	//this method is EXTREMELY SLOW
	auto testAnswer = possibleAnswer
	
	for(auto ansItr=testAnswer.begin();ansItr!=testAnswer.end();){
		std::string answer = *ansItr;
		std::vector res = guessResultTest(guess,answer);
		std::set<char> neT;
		std::set<char> eT;
		for(int i=0;i<res.size();i++){
			if(res[i]==0)
			neT.insert(guess[i]);
			if(res[i]==1)
			eT.insert(guess[i]);
		}
		for(auto it=possibleAnswer.begin();it!=possibleAnswer.end();){
			std::string curr = *it;
			for(int i=0;i<curr[i];i++)
			if(currTest.size()!=0)valid=false;
			if(valid)count += 1;
		}
	}
	return count;
}
void guess(const int& WORD_SIZE,std::list<std::string>& wList,const int& GUESS_LIMIT){
	invalidP.resize(WORD_SIZE);
	fe.assign(WORD_SIZE,'X');
	possibleAnswer=wList;
	std::cout << "enter start:";
	std::cin >> guess;
	std::set<char> nonExist;

	for(int att=1;att<=GUESS_LIMIT;att++){
		std::vector<int> res = getResult(guess);
		bool cor = true;
		for(int i=0;i<res.size();i++){
			if(res[i]==3){
				cor = false;
				att-=1;
				continue;
			}
			if(res[i]==0){
				bool existS = false;
				for(int j=0;j<res.size();j++){
					if(i!=j&&guess[i]==guess[j]&&res[j]!=0)existS = true;
				}
				if(existS)continue;
				nonExist.insert(guess[i]);
			}
			if(res[i]==1){exist.insert(guess[i]);invalidP[i].insert(guess[i]);}
			if(res[i]==2)fe[i]=guess[i];
			if(res[i]!=2)cor=false;
		}
		std::cout << "scope:" << possibleAnswer.size() << '\n';

		guess=*possibleAnswer.begin();
		possibleAnswer.erase(possibleAnswer.begin());
	}
}