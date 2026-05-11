#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int,int>;

int main(){
	int next[105]={-1};
	string a,b;
	cin>>a;
	cin>>b;
	int i = 0,j = -1;
	while(i<b.size())
	{
		if(j==-1||a[i]==a[j])
		next[++i] = ++j;
		else
		j = next[j]; 
	}
	i = 0,j = 0;
	while(i<a.size())
	{
		if(a[i] == b[j])
		i++,j++;
		else
		{
			if(j > 0)
				j = next[j];
			else
				i++;
		}
		if(j==b.size()){
			j = 0;
			cout<<i-b.size()+1<<endl;
			i = i-b.size()+1;
		}
	}
	for(i = 0;i<b.size();i++)
		cout<<next[i]<<' ';
}

