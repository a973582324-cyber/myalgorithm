#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int t,n;
    int a[200005];
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int>b(n+1);
        int temp;
        int st=0,end=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b.begin()+1,b.end(),cmp);
        for(int i=1;i<=n;i++){
            if(a[i]!=b[i]){
            st=i;
            temp=1;
                for(int j=i;j<=n;j++){
                    if(a[j]==b[i]){
                    end=j;
                    break;
                    }
                }
            break;
            }
        }
    if(temp)
    for(int i=st;i<=(st+end)/2;i++){
       temp=a[i];
       a[i]=a[(st+end)-i];
       a[(st+end)-i]=temp;
    }
        for(int i=1;i<=n;i++)
            cout<<a[i]<<' ';
            cout<<endl;
    }
    return 0;    
}