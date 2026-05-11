#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    string s;
    string s1,s2;
    s1="map";
    s2="pie";
    while(t--){
        cin>>n;
        cin>>s;
        int ans=0;
        int j=0,i=0;
        unordered_map<int,int>hs;
        while(i<s.size()){
            if(s[i]==s1[j]){
                j++;
                i++;
            }
            else if(j>0){
                j=0;
            }
            else if(s[i]!=s1[j]){
                i++;
            }
            if(j==3){
                ans++;
                j=0;
                hs[i]=j;
            }
        }
        i=0,j=0;
        while(i<s.size()){
            if(s[i]==s2[j]){
                j++;
                i++;
            }
            else if(j>0){
                j=0;
            }
            else if(s[i]!=s2[j]){
                i++;
            }
            if(j==3){
                auto it =hs.find(i-2);
                if(it==hs.end())
                ans++;
                j=0;
            }
        }
        cout<<ans<<endl;
    }
}