#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int mod=1e9+7;
vector<int>c;
int n,x;
signed main()
{
    speed;
    cin>>n>>x;
    c.resize(n);
    vector<int>dp(x+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(j<c[i])continue;
            dp[j]=(dp[j]+dp[j-c[i]])%mod;
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}

