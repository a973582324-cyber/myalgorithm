// list 是双向链表，已知迭代器时插入和删除为 O(1)，但不支持随机访问。
// advance 需要逐节点移动，因此移动 k 步的复杂度为 O(k)。
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
