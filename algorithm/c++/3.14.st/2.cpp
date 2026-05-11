#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    int t,n;
    cin>>t;
    while(t--){
        cin>>n>>s;
        if(n==1)
            cout<<"no"<<endl;
        else{
            while(s.length()>0){
                int temp=0;
                for(int i=0;i<s.length()-1;i++){
                    if(s[i]==s[i+1]){
                        s.erase(s.begin()+i);
                        s.erase(s.begin()+i);
                        temp=1;
                        break;
                    }
                }
                if(temp==0){
                    cout<<"no"<<endl;
                    break;
                }
            }
            if(s.length()==0)
            cout<<"yes"<<endl;
        }
    }
}