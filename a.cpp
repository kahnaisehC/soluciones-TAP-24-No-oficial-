#include<bits/stdc++.h>

using namespace std;

const int A = 'X';
const int E = 'E';
const int B = 'O';

vector<int> indegree(9, 0);
vector<set<int>> deps(9, set<int>());
int state[3][3];

int hasSolution(){
	int emptyCount = 0;

	if(state[0][0] == state[1][1] && state[1][1] == state[2][2]){
		if(state[0][0] != E)
			return state[0][0];
	}
	if(state[2][0] == state[1][1] && state[1][1] == state[0][2]){
		if(state[2][0] != E)
			return state[2][0];
	}
	for(int i = 0; i < 3; i++){
		if(state[i][0] == state[i][1] && state[i][1] == state[i][2]){
			if(state[i][0] != E)
			return state[i][0];
		}
		if(state[0][i] == state[1][i] && state[1][i] == state[2][i]){
			if(state[0][i] != E)
			return state[0][i];
		}
		for(int j = 0; j < 3; j++){
			if(state[i][j] == E && indegree[i*3+j] == 0){
				emptyCount = 1;
			}
		}
	}
	if(emptyCount == 0)return E;
	return 0;
}

int solve(int turn){
	int solution = hasSolution();
	if(solution != 0){
		return solution;
	}
	int opposite = A;
	if(turn == A) opposite = B;

	int winner = opposite;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			int idx = i*3+j;
			int thisWinner = opposite;
			if(state[i][j] == E && indegree[idx] <= 0){
				for(auto dep: deps[idx]){
					indegree[dep]--;
				}
				state[i][j] = turn;
				thisWinner = solve(opposite);
				state[i][j] = E;
				for(auto dep: deps[idx]){
					indegree[dep]++;
				}
			}
			if(thisWinner == turn)return turn;
			if(thisWinner == E)winner = E;
		}
	}
	return winner;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if(deps[a].count(b) == 0){
			deps[a].insert(b);
			indegree[b]++;
		}
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			state[i][j] = E;
		}
	}
	char s = solve(A);


	cout << s << endl; 


	return 0;
}
