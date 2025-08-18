#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<set<int>> adj(n+m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int col = j;
			int row = i+m;
			char c;
			cin >> c;
			if(c == '.'){
				adj[col].insert(row);
				adj[row].insert(col);
			}
		}
	}
	int nodes = n+m;


	int v1 = -1, v2 = -1;
	bool can = true;
	for(int i = 0; i < nodes; i++){
		if((adj[i].size() & 1) == 1){
			if(v1 == -1){
				v1 = i;
			}else if(v2 == -1){
				v2 = i;
			}else{
				can = false;
			}
		}
	}

	if(!can){
		cout << "*" << endl;
		return 0;
	}
	stack<int> st;
	int v3 = -1;
	if(v1 != -1){
		v3 = nodes;
		nodes++;
		st.push(v3);
		adj.push_back(set<int>({v1, v2}));
		adj[v1].insert(v3);
		adj[v2].insert(v3);
	}else{
		int first = 0;
		for(int i = 0; i < adj.size(); i++){
			if(adj[i].size() != 0){
				first = i;
			}
		}

		st.push(first);
	}

	vector<int> path;

	while(!st.empty()){
		int top = st.top();
		if(adj[top].size() == 0){
			path.push_back(top);
			st.pop();
		}else{
			int next = *adj[top].begin();
			adj[top].erase(next);
			adj[next].erase(top);
			st.push(next);
		}
	}

	for(int i = 0; i < nodes; i++){
		if(adj[i].size() != 0){
			can = false;
			break;
		}
	}
	if(can){
		vector<vector<int>> matrix(n, vector<int>(m, 0));
		if(v1 != -1){
			vector<pair<int, int>> edgePath;
			for(int i = 0; i < path.size()-1; i++){
				edgePath.push_back({path[i], path[i+1]});
			}
			edgePath.push_back({path[0], path[path.size()-1]});
			for(int i = 0; i < edgePath.size(); i++){
				int f = edgePath[i].first;
				int s = edgePath[i].second;
				if(f == v3){
					int counter = 1;
					int j = (i+1)%edgePath.size();
					while(edgePath[j].second != v3){
						int row = edgePath[j].first;
						int col = edgePath[j].second;
						if(row < col)swap(row, col);
						row -= m;
						matrix[row][col] = counter;
						j = (j+1)%edgePath.size();
						counter++;
					}
					break;
				}
			}
		}else{
			for(int i = 0; i < path.size()-1; i++){
				int row = path[i];
				int col = path[i+1];
				if(row < col)swap(row, col);
				row -= m;
				matrix[row][col] = i+1;
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}

	}else{
		cout << '*' << endl;
	}
	return 0;
}
