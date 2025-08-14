#include<bits/stdc++.h>

using namespace std;

typedef struct {
	int a, b, c;
}weapon;

int main(){

	int n, p;
	cin >> n >> p;
	vector<weapon>weapons(n);
	for(auto& w: weapons){
		cin >> w.a >> w.b >> w.c;
	}

	for(int i = 0; i < n; i++){
		int currPoints = p;
		vector<bool>vis(n, 0);

	}






	

	
	return 0;
}

