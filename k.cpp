#include<bits/stdc++.h>

using namespace std;

const int A = 1, T = 2, P = 3;

int scheck(vector<vector<bool>>&map, int i, int j){
	if(map[i][j] == false)return -1;
	// A
	if(map[i+3][j]){
		for(int x = 0; x < 3; x++){
			map[i][j-x] = false;
			map[i+2][j-x] = false;
		}
		for(int x = 0; x < 5; x++){
			map[i+x][j] = false;
			map[i+x][j-2] = false;
		}
		return A;
	}
	// P
	if(map[i+1][j]){
		for(int x = 0; x < 3; x++){
			map[i][j-x] = false;
			map[i+2][j-x] = false;
			map[i+x][j] = false;
		}
		for(int x = 0; x < 5; x++){
			map[i+x][j-2] = false;
		}
		return P;
	}
	// T
	for(int x = 0; x < 3; x++){
		map[i][j-x] = false;
	}
	for(int x = 0; x < 5; x++){
		map[i+x][j-1] = false;
	}
	return T;
}


int main(){

	int n, m;
	cin >> n >> m;
	vector<vector<bool>> map;

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		map.push_back(vector<bool>());
		for(auto c: s){
			map[i].push_back(c == '#');
		}
	}

	int t = 0, a = 0, p = 0;

	for(int j = m-1; j >= 2; j--){
		for(int i = 0; i < n-4; i++){
			int aux = scheck(map, i, j);
			if(aux == T){
				t++;
			}
			if(aux == A){
				a++;
			}
			if(aux == P){
				p++;
			}
		}
	}
	printf("%d %d %d\n", t,a,p);


	return 0;
}
