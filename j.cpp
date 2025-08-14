#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, x;
	cin >> n >> x;
	vector<int> numbers;
	int aux = n;

	int halves = 0;

	while(aux--){
		int m;
		cin >> m;
		if(m*2 == x)halves++;
		else numbers.push_back(m);

	}
	sort(numbers.begin(), numbers.end());

	int sz = numbers.size();
	int mid = -1;
	bool putInEven = false;


	for(int i = 0; i < sz-1; i++){
		if(numbers[i]+numbers[i+1] == x){
			int swap = i-1;

			while(swap >= 0 && numbers[swap] == numbers[i]){
				swap--;
			}
			if(swap == -1){
				swap = i+2;
				while(swap < sz && numbers[swap] == numbers[i+1]){
					swap++;
				}
				if(swap == sz){
					mid = i;
					break;
				}
				if(mid == i)break;
				int aux = numbers[swap];
				numbers[swap] = numbers[i+1];
				numbers[i+1] = aux;
			}else{
				int aux = numbers[swap];
				numbers[swap] = numbers[i];
				numbers[i] = aux;
			}
			if(mid == i)break;
		}
		if(mid == i)break;
	}
	if(halves > numbers.size()+1){
		cout << "*" << endl;
		return 0;
	}else if(mid != -1 && halves == 0){
		cout << "*" << endl;
		return 0;
	}else{
		if(mid != -1)halves--;
		if(halves > 0){
			halves--;
			cout << x/2 << " ";
		}
		for(int i = 0; i < sz;i++){
			cout << numbers[i] << " ";
			if(mid == i){
				cout << x/2 << " ";
			}else if(halves > 0){
				halves--;
				cout << x/2 << " ";
			}
		}
		cout << endl;

	}

	





	return 0;
}
