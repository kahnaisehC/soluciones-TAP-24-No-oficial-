#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	vector<set<int>>rowRanges(n);
	vector<set<int>>colRanges(m);


	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			if(c != '0'){
				rowRanges[i].insert(j);
				colRanges[j].insert(i);
			}
		}
	}

	vector<int>rowOdds;
	vector<int>colOdds;

	for(int i = 0; i < n; i++){
		if(rowRanges[i].size()%2 == 1){
			rowOdds.push_back(i);
		}
	}
	for(int i = 0; i < m; i++){
		if(colRanges[i].size()%2 == 1){
			colOdds.push_back(i);
		}
	}
	int allOdds = colOdds.size() + rowOdds.size();
	if(allOdds !=  2 && allOdds != 0){
		cout << "*" << endl;
		return 0;
	}

	bool ROWS = 0;
	bool COLS = 1;

	// allOdds = 0
	while(true){

	}



	// allOdds = 2 y son el mismo vertice

	// allOdds = 2 y son distinto verticec

	return 0;

}
