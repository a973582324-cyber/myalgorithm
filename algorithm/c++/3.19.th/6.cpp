#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int,int>hashmap;
    int n;
    cin>>n;
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        hashmap[x^i]++;
    }
    int max_=0;
    for(auto&[key, value]:hashmap){
        max_=max(value,max_);
    }
    int ans=n-max_;
    cout<<ans<<endl;
}