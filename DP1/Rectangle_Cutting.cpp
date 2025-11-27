#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
int dp[501][501];
int get(int a,int b)
{
    if(a==b)return 0;
    if(a==0 || b==0)return 0;
    if(dp[a][b]!=-1)return dp[a][b];
    int ans=1e18;
    for(int i=1;i<a;i++)
    {
        ans=min(ans,1+get(i,b)+get(a-i,b));
    }
    for(int j=1;j<b;j++)
    {
        ans=min(ans,1+get(a,j)+get(a,b-j));
    }
    return dp[a][b]=ans;
}
signed main()
{
    speed;
    for(int i=0;i<501;i++)
    for(int j=0;j<501;j++)
    dp[i][j]=-1;
    int a,b;
    cin>>a>>b;
    cout<<get(a,b)<<endl;
    return 0;
}
 