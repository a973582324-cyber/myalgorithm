#include<iostream>
using namespace std;
int a[10005];
void decompose(int x){
    for(int i = 2;i*i<=x;i++)
    {
        while(x%i == 0){
            a[i]++;
            x /= i;
        }
    }
    if(x>1)
    a[x]++;
}
int main(){
    int n;
    cin>>n;
    for(int i = 2;i<=n;i++)
    decompose(i);
    for(int i = 1;i<=n;i++){
        if(a[i]){
            cout<<i<<' '<<a[i]<<' '<<endl;;
        }
    }
}