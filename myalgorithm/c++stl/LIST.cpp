#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<list>
using namespace std;

int main(){
	list<int>a(4,2);
		cout<<a.empty()<<endl;
		cout<<a.size()<<endl;
	a.push_front(1);
	a.push_back(1);
		cout<<a.size()<<endl;
		cout<<a.front()<<" "<<a.back()<<endl;
	auto it=a.begin();
	advance(it,2);
	a.insert(it,66);
	it=a.begin();
	advance(it,1);
	a.erase(it);
	for(int val:a){
		cout<<val<<" ";
	}
	return 0;
}