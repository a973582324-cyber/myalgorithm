#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    unordered_map<int,int>hash;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        hash[a[i]^i]++;
    }
    int max_=-1;
    for(auto a:hash)
    max_=max(a.second,max_);
    cout<<n-max_;
}
