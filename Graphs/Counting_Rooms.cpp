#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
int n,m;
vector<vector<char>>grid;
vector<vector<bool>>vis;
void fill(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=m)return;
    if(grid[i][j]=='#' || vis[i][j])return;
    vis[i][j]=1;
    fill(i+1,j);
    fill(i-1,j);
    fill(i,j-1);
    fill(i,j+1);
}
signed main()
{
    speed;
    cin>>n>>m;
    grid.resize(n,vector<char>(m));
    vis.resize(n,vector<bool>(m));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>grid[i][j],vis[i][j]=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='#' || vis[i][j])
            continue;
            fill(i,j);
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}


