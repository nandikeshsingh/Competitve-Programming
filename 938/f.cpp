#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int dp[201][201][201];
int get(int a,int b,int c)
{
    if(a==0 && b==0 && c==0)return dp[a][b][c]=0;
    if(a<0 || b<0 || c<0)return -1e18;
    int ans=0;
    if(dp[a][b][c]!=-1)return dp[a][b][c];
    if(a%2==0 && b%2==0 && c%2==0)
    {
        ans=1+max({get(a-1,b,c),get(a,b-1,c),get(a,b,c-1)});
    }
    else if(a%2 && b%2 && c%2)
    {
        ans=1+max({get(a-1,b,c),get(a,b-1,c),get(a,b,c-1)});
    }
    else ans=max({get(a-1,b,c),get(a,b-1,c),get(a,b,c-1)});
    return dp[a][b][c]=ans;
}
signed main()
{
    speed;

    for(int i=0;i<=200;i++)for(int j=0;j<=200;j++)for(int k=0;k<=200;k++)
    dp[i][j][k]=-1;
    get(200,200,200);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,c4;cin>>a>>b>>c>>c4;
        int ans=c4/2;
        cout<<ans+dp[a][b][c]<<endl;
    }
    return 0;
}