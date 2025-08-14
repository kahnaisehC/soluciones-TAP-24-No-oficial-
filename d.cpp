#include<bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;

	bool cond = (a >= b+c) || (b >= c+a) || (c >= b+a);

	if(cond){
		cout << "S" << endl;
		return 0;
	}
	cout << "N" << endl;
	return 0;
}
