#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long t,l,r;
    cin>>t;
    while(t--){
        scanf("%lld %lld",&l,&r);
        long long count=0,ans=0;
        long long temp=l;
        while(temp>0){
            temp/=3;
            count++;
        }
        temp=pow(3,count);
        if(temp<r)
        ans+=count*(temp-l+1);
        else if(temp==r){
        ans+=count*(r-l+2)+1;
        printf("%lld\n",ans);
        continue;
        }
        else{
        ans+=count*(r-l+2);
        printf("%lld\n",ans);
        continue;
        }
        count++;
        while(1){
            if(temp*3<r){
                ans+=count*(temp*3-temp);
                temp*=3;
                count++;
            }
            else if(temp*3==r){
                ans+=count*(r-temp+1)+1;
                break;
            }
            else{
                ans+=count*(r-temp+1);
                break;
            }
        }
        
        printf("%lld\n",ans);
    }

}