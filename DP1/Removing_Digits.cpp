#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
int dp[1000001];
int get(int n)
{
    if(n<0)return 2e18;
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    int ans=1e18;
    set<int>temp;
    int cn=n;
    while(cn)
    {
        if(cn%10!=0)
        temp.insert(cn%10);
        cn/=10;
    }
    for(auto& u : temp)
    {
        ans=min(ans,get(n-u)+1);
    }
    return dp[n]=ans;
}
signed main()
{
    speed;
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<get(n)<<endl;
    return 0;
}


