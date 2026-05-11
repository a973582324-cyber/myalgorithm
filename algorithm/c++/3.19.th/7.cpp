#include<iostream>
#include<cmath>
#include<unordered_map>
using namespace std;
unordered_map<int,int>hashmap;
void st(){
    for(int i=1;i<10000;i++){
        hashmap[i]=pow(i,2);
    }
}
int main(){
    int x,l,r;
    cin>>x>>l>>r;
    for(int i=l;i<=r;i++){
        auto it=hashmap.find(x*i);
        if(it!=hashmap.end()){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}