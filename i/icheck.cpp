#include<bits/stdc++.h>

using namespace std;

typedef struct{
	int col;
	int row;
	int value;
}node;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> input(n, vector<int>(m));
	for(auto& v: input){
		for(auto& c: v){
			char in;
			cin >> in;
			if(in == '.'){
				c = -1;
			}else{
				c = 0;
			}

		}
	}
	vector<vector<int>>output(n, vector<int>(m));
	vector<node> order;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> output[i][j];
		}
	}

	int col;
	int row;
	int value;
	bool bad = false;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(input[i][j] == -1 && output[i][j]== 0){
				cout << "forgets edges" << endl;
				bad = true;
				return 1;
			}

			if(output[i][j] != 0){
				if(input[i][j] != -1){
					cout << "creates new eges" << endl;
					bad = true;
					return 1;
				}
				node no;
				no.col = j;
				no.row = i;
				no.value = output[i][j];
				order.push_back(no);
			}
		}
	}
	sort(order.begin(), order.end(), [](node o1, node o2){
		return o1.value < o2.value;
	});

	set<pair<int, int>> visited;
	visited.insert({order[0].row, order[0].col});

	for(int i = 1; i < order.size(); i++){
		node o1 = order[i-1];
		node o2 = order[i];
		pair<int, int> p1 ={o1.row, o1.col};
		pair<int, int> p2 ={o2.row, o2.col};
		if(visited.count(p2) != 0){
			cout << "node visited twice" << endl;
			bad = true;
			return 1;
		}
		visited.insert(p2);
		if(o1.col != o2.col && o1.row != o2.row){
			cout << "nodes are not neighbours" << endl;
			cout << o1.col << " "<< o2.col << " ";
			cout << o1.row<< " "<< o2.row<< endl;


			bad = true;
			return 1;
		}
		if(o1.col == o2.col && o1.row == o2.row){
			cout << "nodes are the same" << endl;
			cout << o1.col << " "<< o2.col << " ";
			cout << o1.row<< " "<< o2.row<< endl;
			bad = true;
			return 1;
		}
		if(o1.value != i || o2.value != i+1){
			cout << "nodes are not contiguous" << endl;
			bad = true;
			return 1;
		}
	}


	return 0;
}
