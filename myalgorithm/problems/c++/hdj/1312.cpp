/*
你妹的
*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
char s1 = '@';
char s2 = '#';
int fx[4] = {0,0,1,-1};
int fy[4] = {1,-1,0,0};
int main()
{
    int w,h;
    while(cin>>w>>h)
    {
        if(w==0&&h==0)
            break;
        char a[25][25];
        int ans = 0;
        int x,y;
        for(int i = 0;i<h;i++)
        {
            for(int j = 0;j<w;j++)
            {
                char c;
                cin>>c;
                a[i][j] = c;
                if(a[i][j] == s1)
                    x = i,y = j;
            }
        }
        queue<pair<int,int>>q;
        q.push({x,y});
        ans = 1;
        a[x][y] = s2;
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            int x = t.first,y = t.second;
            for(int i =0;i<4;i++)
            {
                int xx = x+fx[i],yy = y +fy[i];
                if(xx<0||yy<0||xx>=h||yy>=w)continue;
                if(a[xx][yy] == s2)continue;
                q.push({xx,yy});
                ans++;
                a[xx][yy] = s2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/////////////