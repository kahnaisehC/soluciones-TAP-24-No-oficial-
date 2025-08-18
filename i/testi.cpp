#include<bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]){
	int seed = 10;
	if(argc > 1) seed = stoi(argv[1]);
	int n = 4;
	int m = 4;
	cout << n << " " << m << endl;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if((seed & (1<<(i*n+j))) != 0){
				cout << ". ";
			}else{
				cout << "0 ";
			}
		}
		cout << endl;
	}

	return 0;
}
