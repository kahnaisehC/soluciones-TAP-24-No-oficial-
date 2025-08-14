#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	int prev = -1;
	int prevPrev = -1;


	cin >> prevPrev;


	if(n == 1){
		if(prevPrev == 0) prevPrev = -1;
		cout << prevPrev << endl;
		return 0;
	}

	cin >> prev;

	int cnt = prev+prevPrev;
	if (cnt == 0)cnt = -2;
	if (cnt == 1)cnt=0;



	for(int i = 2;i < n; i++){
		int a;
		cin >> a;
		if(a == 1){
			cnt++;
			if(a == prev && prev == prevPrev)cnt++;
		}else{
			cnt--;
		}
		prevPrev = prev;
		prev = a;
	}
	cout << cnt << endl;
	return 0;
}
