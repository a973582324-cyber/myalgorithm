#include<iostream>
#include<vector>
using namespace std;
vector<int>a;
vector<int>b;
int find(int x){
    int l=0,r=b.size()-1;    
    while(l<=r){
        int mid=l+(r-l)/2;
        if(b[mid]<x)l=mid+1;
        else
        r=mid-1;
    }
    return l;
}
int main(){
    int sum;
    while(cin>>sum){
        a.push_back(sum);
    }
    sum = 0;
    b.push_back(a[0]);
    for(int i=1;i<a.size();i++){
        if(a[i]<=b[b.size()-1])
        b.push_back(a[i]);
        else{
            int j=find(a[i]);
            b[j]=a[i];
        }
    }
    cout<<b.size()<<endl;
}
//二分法求最长下降子序列