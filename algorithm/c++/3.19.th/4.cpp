#include<iostream>
#include<unordered_map>
using namespace std;
struct star
{
    int row;
    int len;
};
int main(){
    int t,n;
    cin>>t;
    char s[25][25];
    while(t--){
        cin>>n;
        int temp=0;
        int r=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>s[i][j];
            }
        }
        int count[4]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i][j]=='*'){
                    if(s[i-1][j]=='*'&&i-1>=0)
                    count[r]++;
                    if(s[i+1][j]=='*'&&i+1<n)
                    count[r]++;
                    if(s[i][j+1]=='*'&&j+1<n)
                    count[r]++;
                    if(s[i][j-1]=='*'&&j-1>=0)
                    count[r]++;
                    r++;
                }
            }
        }
        for(int i=0;i<4;i++){
            if(count[i]==3)
            temp=1;
        }
        if(temp)
        cout<<'T'<<endl;
        else
        cout<<'L'<<endl;
    }


}