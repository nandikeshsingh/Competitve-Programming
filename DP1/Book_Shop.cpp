#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<int>h,s;
int n,x;
int dp[1010][100100];
signed main()
{
    speed;
    cin>>n>>x;
    h.resize(n+1);
    s.resize(n+1);
    for(int i=1;i<=n;i++)cin>>h[i];
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(j==0 || i==0)dp[i][j]=0;
            else 
            {
                if(j>=h[i])
                dp[i][j]=max({dp[i-1][j-h[i]]+s[i],dp[i-1][j]});
                else dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][x]<<endl;
    return 0;
}