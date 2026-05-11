#include<iostream>
using namespace std;
int a[1000];
int rank_[1000];
void std(){
    for(int i=0;i<1000;i++){
    a[i]=i;rank_[i]=0;
    }
}

//按轶合并
/*int find(int x)
{
	if(bin[i]==[i])
		return bin[i];
	return bin[i] = find(bin[i]);	
}
void unite(int x,int y,int w)
{
	int fx = find(x);
	int fy = find(y);
	if(x==y)
	return;
	if(rank[fx]>rank[fy])swap(fx,fy);
	bin[fx] = fy;
	rank[fy]+=rank[fx];
}*/
//按节点合并
int point[10000]{};
int find(int r){
    if(a[r]==r)
    return a[r];
    else
    return a[r]=find(a[r]);
}
void unit(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx==fy){
        return;
    }
    else{
    if(point[fx]>point[fy]){
        a[fy]=fx;
        point[fx]+=point[fy];
    }
    else if(point[fx]>=point[fy]){
        a[fx]=fy;
        point[fy]+=point[fx];

    }
    }
}
int main(){






}
