#include<iostream>
using namespace std;
int a[5000003];
void quicksort(int l,int r){
    if(l>=r)return;
    int i=l,j=r;
    int mid=l+(r-l)/2;
    int p=a[mid];
    while(i<=j){
       while(a[i]<p)i++;
       while(a[j]>p)j--;
       if(i<=j){
        swap(a[i],a[j]);
        i++;
        j--;
       }
    }
    if(l<j)quicksort(l,j);
    if(r>i)quicksort(i,r);
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(0,n-1);
    cout<<a[k];
}