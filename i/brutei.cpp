#include<bits/stdc++.h>

using namespace std;

int amEdges;
int counter = 1;
int n, m;
vector<vector<int>> matrix;

const bool HOR = true;
const bool VER = false;



bool solve(int node, bool direction){
	if(amEdges == 0){
		return true;
	}
	if(direction == HOR){
		for(int i = 0; i < m; i++){
			if(matrix[node][i] == -1){
				matrix[node][i] = counter;
				counter++;
				amEdges--;

				if(solve(i, !direction)){
					return true;
				}

				amEdges++;
				counter--;
				matrix[node][i] = -1;
			}
		}
	}else{
		for(int i = 0; i < n; i++){
			if(matrix[i][node] == -1){
				matrix[i][node] = counter;
				counter++;
				amEdges--;

				if(solve(i, !direction)){
					return true;
				}

				amEdges++;
				counter--;
				matrix[i][node] = -1;
			}
		}
	}
	return false;
}

int main(){
	cin >> n >> m;
	matrix.resize(n);
	for(auto& v: matrix){
		for(int i = 0; i < m; i++){
			char in;
			cin >> in;
			if(in == '0'){
				v.push_back(0);
			}else{
				v.push_back(-1);
				amEdges++;
			}
		}
	}

	bool solved  = false;

	for(int i = 0; i < n; i++){
		if(solve(i, HOR)){
			solved = true;
			break;
		}
	}

	for(int i = 0; i < m; i++){
		if(solved)break;
		if(solve(i, VER)){
			solved = true;
			break;
		}
	}
	if(solved){
		for(auto& v: matrix){
			for(auto& c: v){
				cout << c << " ";
			}
			cout << endl;
		}
	}else{
		cout << "*" << endl;
	}


	return 0;
}
