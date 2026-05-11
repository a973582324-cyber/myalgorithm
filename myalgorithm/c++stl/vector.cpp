#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,temp;
    int count1=0;
    vector<int>a(10);
    a.push_back(1);
        cout<<a.size()<<endl;;
    int len=a.size();
        cout<<a.back()<<endl;
    a.pop_back();
        cout<<a.size()<<endl;
    a.insert(a.begin()+1,2);
        cout<<a.size()<<endl;
    a.insert(a.end()-3,5);
    a.erase(a.end()-3);
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    return 0;
}