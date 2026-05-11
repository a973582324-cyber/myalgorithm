#include<iostream>
using namespace std;
int main(){
    int n,t;
    cin>>t;
    char a[55];
    while(t--){
        cin>>n;
        int count=0;
        for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]=='B')
        count++;
        }
        if(n==2){
            if(a[0]=='A')
            cout<<"Alice"<<endl;
            else
            cout<<"Bob"<<endl;
        }
        else{
            if(a[0]=='B'){
                if(a[n-1]=='B')
                cout<<"Bob"<<endl;
                else{
                    if(a[n-2]=='B')
                    cout<<"Bob"<<endl;
                    else
                    cout<<"Alice"<<endl;
                }
            }
            else{
                if(a[n-1]=='A')
                cout<<"Alice"<<endl;
                else{
                    if(count>1)
                    cout<<"Bob"<<endl;
                    else
                    cout<<"Alice"<<endl;
                }
            }
        }
    }

    return 0;
}