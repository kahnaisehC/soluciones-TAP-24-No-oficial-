#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;

	int ts = 0;
	int us = 0;
	int as = 0;
	int ps = 0;

	for(auto c: s){
		if(c == 'T'){
			ts++;
		}
		if(c == 'U'){
			us++;
		}
		if(c == 'A'){
			as++;
		}
		if(c == 'P'){
			ps++;
		}
	}

	cout << min(us+as, min(ts, ps)) << endl;


	return 0;
}

