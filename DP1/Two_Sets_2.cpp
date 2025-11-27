#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int mod=1e9+7;
int n;
int dp[(125*(501))+1][500+1];
int get(int cur,int val)
{
    if(cur==0)return 1;
    if(cur<0)return 0;
    if(val>n)return 0;
    if(dp[cur][val]!=-1)return dp[cur][val];
    return dp[cur][val]=(get(cur-val,val+1)+get(cur,val+1))%mod;
}
int binpow(int a,int b)
{
    int ret=1;
    while(b)
    {
        if(b%2)ret=(ret*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ret;
}
signed main()
{
    speed;

    cin>>n;
        for(int i=0;i<(125*(501))+1;i++)
    for(int j=0;j<=n;j++)
    dp[i][j]=-1;
    int sum=(n*(n+1))/2;
    if(sum%2)cout<<0<<endl;
    else 
    {
        cout<<(get(sum/2,1)/2)%mod<<endl;
    }
    return 0;
}


