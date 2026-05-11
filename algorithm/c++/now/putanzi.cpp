#include<iostream>
using namespace std;
int a[10005][10005]={0};
  void st() { 
    for(int i=0;i<=10004;i++)
{
    for(int j=0;j<=10004;j++)
    a[i][j]=-1;
}
  }
int main(){
    st();
    int n,x,y,s1,s2;
    cin>>n;
    int count=1;
    int i,j;
    while(n--){
        cin>>x>>y>>s1>>s2;
        if(x+s1<=10000&&y+s2<=10000){
        for(i=x;i<=x+s1;i++){
            for(j=y;j<=y+s2;j++)
            a[i][j]=count++;
        }
    }
    else if(x+s1>10000&&y+s2<=10000)
    for(i=x;i<=10000;i++){
        for(j=y;j<=y+s2;j++)
        a[i][j]=count++;
    }
    else if(x+s1<=10000&&y+s2>10000)
    for(i=x;i<=x+s1;i++){
        for(j=y;j<=10000;j++)
        a[i][j]=count++;
    }else if(x+s1>10000&&y+s2>10000)
    for(i=x;i<=10000;i++){
        for(j=y;j<=10000;j++)
        a[i][j]=count++;
    }
    }
    cin>>x>>y;
    cout<<a[x][y];
    return 0;
}