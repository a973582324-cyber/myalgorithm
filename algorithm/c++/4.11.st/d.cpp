#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
#define int long long
void solve(){
   int n;
   cin>>n;
   vector<int>c;
   int l=0,r=1e9,k=0,a,b;
   for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a==1)
			l=max(l,b);
		else if(a==2)
			r=min(r,b);
		else if(a==3)
			c.push_back(b);
   }
   if(l>r)
   		cout<<0<<endl;
   else
   {
		int ans=r-l+1;
		for(int i=0;i<c.size();i++){
			if(c[i]>=l&&c[i]<=r)
				ans--;
		}
		cout<<ans<<endl;
   }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);	
    int t;
    cin>>t;
    while(t--)
    solve();
}