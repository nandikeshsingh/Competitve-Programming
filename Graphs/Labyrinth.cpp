#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
int n,m;
bool ok(int i,int j)
{
    if(i<0 || i>=n ||j<0 || j>=m)return 0;
    else return 1;
}
signed main()
{
    speed;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    vector<vector<int>>dis(n,vector<int>(m,0));
    vector<vector<char>>path(n,vector<char>(m,'c'));
    vector<vector<bool>>vis(n,vector<bool>(m));
    int x=-1,y=-1,xx=-1,yy=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='A')x=i,y=j;
            if(grid[i][j]=='B')xx=i,yy=j;
        }
    }
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y]=1;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    while(!q.empty())
    {
        pair<int,int>p=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int cur_x=p.first+dx[i];
            int cur_y=p.second+dy[i];
            if(ok(cur_x,cur_y) && grid[cur_x][cur_y]!='#' && vis[cur_x][cur_y]==0)
            {
                vis[cur_x][cur_y]=1;
                q.push({cur_x,cur_y});
                dis[cur_x][cur_y]=dis[p.first][p.second]+1;
                if(i==0)path[cur_x][cur_y]='D';
                else if(i==1)path[cur_x][cur_y]='R';
                else if(i==2)path[cur_x][cur_y]='U';
                else path[cur_x][cur_y]='L';
            }
        }
    }
    if(vis[xx][yy])
    {
        cout<<"YES"<<endl;
        cout<<dis[xx][yy]<<endl;
        int u=xx,v=yy;
        string ans;
        while(u!=x || v!=y)
        {
            ans+=path[u][v];
            if(path[u][v]=='D')u--;
            else if(path[u][v]=='U')u++;
            else if(path[u][v]=='L')v++;
            else v--;
        }
        reverse(all(ans));
        cout<<ans<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}
