#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        unordered_map<int,int>hashmap;
        cin>>n;
        int x;
        vector<int>res(n);
        int count=0;
        for(int i=0;i<n;i++){
            cin>>x;
            auto it=hashmap.find(x);
            if(it==hashmap.end()){
                hashmap[x]=1;
                res[count]=x;
                count++;
            }
        }
        for(int i=0;i<count;i++){
            cout<<res[i]<<' ';
        }
        cout<<'\n';
    }
}