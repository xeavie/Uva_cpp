#include <bits/stdc++.h>
using namespace std;

int getDir(char next , char cur){
	if(next == 'L'){
		switch(cur){
			case 'N':
				return 'W';
			case 'S':
				return 'E';
			case 'E':
				return 'N';
			case 'W':
				return 'S';
		}
	}
	if(next == 'R'){
		switch(cur){
			case 'N':
				return 'E';
			case 'S':
				return 'W';
			case 'E':
				return 'S';
			case 'W':
				return 'N';
		}
	}
}

int main() {
	int x,y;
	cin >> x >> y;

	int x_s,y_s;
	char dir;
	string orders;
	map<char,int> mp = {{'E',0},{'W',1},{'N',2},{'S',3}};
	vector<pair<int,int>> inc = {{1,0},{-1,0},{0,1},{0,-1}};
	map<pair<int,int>,bool> vis;

	jump :

	while(cin >> x_s >> y_s >> dir >> orders){

		for(int i = 0 ; i < orders.size() ; i++){
			if(orders[i] == 'F'){
				if(x_s+inc[mp[dir]].first < 0 || x_s+inc[mp[dir]].first > x
				|| y_s+inc[mp[dir]].second < 0 || y_s+inc[mp[dir]].second > y){
					if(!vis[{x_s,y_s}]){
						cout << x_s << " " << y_s << " " << dir << " " << "LOST" << endl;
						vis[{x_s,y_s}] = true;
						goto jump;
					}
				}else{
					x_s = x_s+inc[mp[dir]].first;
					y_s = y_s+inc[mp[dir]].second;
				}
			}else{
				dir = getDir(orders[i],dir);
			}

		}
		cout << x_s << " " << y_s << " " << dir << endl;
	}

	return 0;
}
