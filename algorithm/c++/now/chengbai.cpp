#include<iostream>
using namespace std;
int add(int a){
    int sum=0;
    while(a>0){
        sum=sum*10+a%10;
        a/=10;
    }
    return sum;
}
bool jud(int a){
    int temp=add(a);
    if(a==temp)
    return true;
    else
    return false;
}
int main(){
    int l,count,m;
    cin>>l;
    while(l--){
        count=0;
        cin>>m;
        while(count<=8){
                m=m+add(m);
                count++;
                if(jud(m)){
                    cout<<count<<endl;
                    break;
            }          
        }
        if(count>8)
        cout<<0<<endl;
    }
    return 0;
}