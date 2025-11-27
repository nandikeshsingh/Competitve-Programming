#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int mod=1e9+7;
vector<vector<char>>grid;
int n;
int dp[1001][1001];
int get(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=n)return 0;
    if(grid[i][j]=='*')return 0;
    if(i==n-1 && j==n-1)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=0;
    ans=(get(i+1,j)+get(i,j+1))%mod;
    return dp[i][j]=ans;
}
signed main()
{
    speed;
    cin>>n;
    grid.resize(n,vector<char>(n));
    for(int i=0;i<1001;i++)
    for(int j=0;j<1001;j++)
    dp[i][j]=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>grid[i][j];
    }
    cout<<get(0,0)<<endl;
    return 0;
}


