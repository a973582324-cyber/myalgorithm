#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    int a[55];
    while(t--){
        cin>>n;
        int index=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>a[index])
            index=i;
        }
        cout<<a[index]*n<<endl;;
    }
}