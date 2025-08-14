#include<bits/stdc++.h>

using namespace std;


int main(){
	int n;
	cin >> n;

	int apex, apey, apez;
	cin >> apex >> apey >> apez;

	int sunx, suny, sunz;
	cin >> sunx >> suny >> sunz;

	vector<pair<int, int>> points(n);
	for(auto& p: points){
		cin >> p.first >> p.second;
	}

	int slopey = (suny-apey)/(sunz-apez);
	int slopex = (sunx-apex)/(sunz-apez);










	return 0;
}
