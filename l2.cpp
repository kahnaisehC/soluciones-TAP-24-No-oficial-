#include<bits/stdc++.h>

using namespace std;

bool isOdd(long long n){
	if(n == 1)return false;
	return n&1;
}

bool isPow(long long n){
	if(n&1)return false;
	if(n == 2)return true;
	return isPow(n/2);

}

int main(){
	int n, q;
	cin >> n >> q;
	vector<long long> numbers(n);
	for(auto& n: numbers){
		cin >> n;
	}

	vector<long long> pows(n, 0);
	vector<long long> odds(n, 0);
	vector<long long> ones(n, 0);

	if(isPow(numbers[0])){
		pows[0] = numbers[0];
	}
	if(isOdd(numbers[0])){
		odds[0] = numbers[0];
	}
	if(numbers[0] == 1){
		ones[0] = 1;
	}

	for(int i = 1; i < n; i++){
		ones[i] = ones[i-1];
		pows[i] = pows[i-1];
		odds[i] = odds[i-1];
		if(numbers[i] == 1)ones[i]++;

		if(isPow(numbers[i])){
			pows[i] = 1ll*(pows[i]+numbers[i]);
		}

		if(isOdd(numbers[i])){
			odds[i] = 1ll*(odds[i]+numbers[i]);
		}

	}





	while(q--){
		int l, r;
		cin >> l >> r;
		r--;
		l-=2;
		long long agus;
		long long brian;
		long long one;

		if(l == -1){
			agus = (pows[r] + (ones[r]&1));
			brian = (odds[r] );
		}else{
			one = ones[r] - ones[l];
			agus = (pows[r] - pows[l] + (one&1));
			brian = (odds[r] - odds[l]);
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
