#include<bits/stdc++.h>

using namespace std;

bool isOdd(long long n){
	if(n==1)return false;
	return n%(1ll*2);
}

bool isSquare(long long n){
	if(n == 1)return true;
	if(n%(1ll*2) == 1)return false;
	return isSquare(n/(1ll*2));
}


int main(){
	int n, q;
	cin >> n >> q;
	vector<long long> l(n);
	for(auto& a: l){
		cin >> a;
	}
	vector<long long> square(n, 0);
	vector<long long> odds(n, 0);

	if(isSquare(l[0]))square[0]=l[0];
	if(isOdd(l[0]))odds[0]=l[0];

	for(int i = 1; i < n; i++){
		square[i] = 1ll*square[i-1];
		odds[i] = 1ll*odds[i-1];
		if(isSquare(l[i])){
			square[i]+=1ll*l[i];
		}
		if(isOdd(l[i])){
			odds[i]+=1ll*l[i];
		}
	}
	while(q--){
		int a, b;
		cin >> a >> b;
		long long agus;
		long long brian;
		if(a != 1){
			agus = 1ll*square[b-1]-1ll*square[a-2];
			brian = 1ll*odds[b-1]-1ll*odds[a-2];
		}else{
			agus = 1ll*square[b-1];
			brian = 1ll*odds[b-1];
		}
		if(agus > brian){
			cout << "A" << endl;
		}else if(brian > agus){
			cout << "B" << endl;
		}else{
			cout << "E" << endl;
		}

	}

	return 0;
}
