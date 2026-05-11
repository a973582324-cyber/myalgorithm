#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
struct cou
{
    int num;
    int power;
};
bool cmp(cou a,cou b){
    return a.power<b.power;
}
int main(){
    int n;
    cin>>n;
    int len=pow(2,n);
    vector<cou>a(len);
    for(int i=0;i<len;i++){
    cin>>a[i].power;
    a[i].num=i+1;
    }  
    sort(a.begin(),a.begin()+len/2,cmp);
    sort(a.begin()+len/2,a.end(),cmp);
    int ans=a[len/2-1].power>a[len-1].power?a[len-1].num:a[len/2-1].num;
    cout<<ans;
}