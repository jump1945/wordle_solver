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

const int DIRECT_GUESS=2;
void guess(const int& WORD_SIZE,std::list<std::string>& wList,const int& GUESS_LIMIT){
	auto wCutList=wList;
	bool term = false;
	std::string guess = "crate";
	std::cout << "enter start";
	std::cin >> guess;
	std::set<char> nonExist;
	std::string fe = "XXXXX";
	std::vector<std::set<char>> invalidP(WORD_SIZE);
	std::set<char> exist;
	std::vector<int> wfqc(26);
	for(int att=1;att<=GUESS_LIMIT;att++){
		wfqc.assign(26,0);
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
		if(cor)break;
		for(auto it=wCutList.begin();it!=wCutList.end();){
			//std::cout << "E";
			auto currTest = exist;
			bool valid = true;
			std::string curr = *it;
			for(int i=0;i<WORD_SIZE;i++){
				if(invalidP[i].find(curr[i])!=invalidP[i].end()){
					valid = false;
				}
				if(curr[i]!=fe[i]&&fe[i]!='X'){
					valid = false;
				}
				if(nonExist.find(curr[i])!=nonExist.end()){
					valid = false;
				}
				currTest.erase(curr[i]);
			}
			if(currTest.size()!=0)valid=false;
			auto old = it;
			it++;
			if(valid){
				for(int i=0;i<WORD_SIZE;i++){
					if(fe[i]!='X'){
						//any unknow letter guess is count into wordfre;
						wfqc[curr[i]-'0']+=1;
					}
				}
			}
			else
			wCutList.erase(old);
			if(it==wCutList.end())break;
		}
		for(int i=0;i<26;i++){
			if(nonExist.find('a'+i)!=nonExist.end()){
				wfqc[i]=-5;
			}
		}
		std::cout << "scope:" << wCutList.size() << '\n';
		if(att>=GUESS_LIMIT+1-DIRECT_GUESS||wCutList.size()==1)//this will guess whatever left on the scope
		{
			guess=*wCutList.begin();
			wCutList.erase(wCutList.begin());
		}
		//this is hardest part guess what would bring the most useful result diminshing the scope down the most
		else{
			std::string MAX_STR;
			int max = -1;
			auto ci=wList.begin();
			for(auto it=wList.begin();it!=wList.end();it++){
				int OPTIM=0;
				std::set<char> wfqcSet;
				for(int i=0;i<WORD_SIZE;i++){
					wfqcSet.insert((*it)[i]);
				}
				for(auto v:wfqcSet){
					OPTIM+=wfqc[v];
				}
				if(OPTIM>max){
					MAX_STR=*it;
					max=OPTIM;
					ci=it;
				}
			}
			for(auto it=wCutList.begin();it!=wCutList.end();it++){
				if(*it==MAX_STR){
					wCutList.erase(it);
					break;
				}
			}
			wList.erase(ci);
			guess=MAX_STR;
		}
	}
}