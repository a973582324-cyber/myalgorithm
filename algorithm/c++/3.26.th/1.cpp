#include<iostream>
using namespace std;
int main(){
    long long t,n;
    cin>>t;
    long long a[200005];
    while(t--){
        cin>>n;
        long long sum1=0;
        long long sum2=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum1+=a[i];
            sum2=min(sum2,sum1);
        }
        cout<<sum1-2*sum2<<endl;
    }
}