#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,t,x,y;
    cin>>t;
    while(t--){
        cin>>n>>x>>y;
        vector<int>q(n);
        for(int i=0;i<n;i++){
            cin>>q[i];
        }
        q.insert(q.begin()+x,0);
        q.insert(q.begin()+y+1,0);
        
    }
}
