#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    char c;
    while(cin>>c){
        if(c=='E')break;
        s+=c;
    }
    int a=0,b=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='W')a++;
        if(s[i]=='L')b++;
        if(max(a,b)>=11&&abs(a-b)>=2){
            cout<<a<<':'<<b<<endl;
            a=0;b=0;
        }
    }
    cout<<a<<':'<<b<<endl<<endl;
    a=0;b=0;
     for(int i=0;i<s.size();i++){
        if(s[i]=='W')a++;
        if(s[i]=='L')b++;
        if(max(a,b)>=21&&abs(a-b)>=2){
            cout<<a<<':'<<b<<endl;
            a=0;b=0;
        }
    }
    cout<<a<<':'<<b<<endl;
    return 0;
}