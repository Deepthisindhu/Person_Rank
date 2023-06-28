#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
bool cmp(pair<string,int>&a,pair<string,int>&b){
	return a.second > b.second;
}
void read(vector<string>&tweets){
	fstream newfile;
	newfile.open("tweets.txt");
	if(newfile.is_open()){
		string tweet;
		while(getline(newfile,tweet)){
			tweets.push_back(tweet);
		}
		newfile.close();
	}
}
void solution(vector<string>tweets){
	for(int i=0;i<tweets.size();i++){
		stringstream ss(tweets[i]);
		int j=tweets[i].size()-1,k=0,likes=0;
		while(isdigit(tweets[i][j])){
			likes=likes+(tweets[i][j]-'0')*pow(10,k);
			j--;
			k++;
		}
		string word;
		ss>>word;
		m[word]+=10*likes;
		while(ss>>word){
			if(word[0]=='@'){
				m[word]+=50+5*likes;
			}
		}
	}
	vector<pair<string,int> > Info;
	for(auto& itr:m){
		Info.push_back(itr);
	}
	sort(Info.begin(),Info.end(),cmp);
	for(auto itr: Info)
		cout<<itr.first<<"\t\t"<<itr.second<<endl;
}
int main(){
	vector<string>tweets;
	read(tweets);
	solution(tweets);
}
