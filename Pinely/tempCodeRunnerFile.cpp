#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<int>a;
vector<vector<int>>dp;
int get(int l,int r)
{
    if(l==r)return dp[l][r]=1;
    if(dp[l][r]!=-1)return dp[l][r];
    else 
    {
        if(a[l]!=a[r])return dp[l][r]=1+max(get(l+1,r),get(l,r-1));
        else return dp[l][r]=max(get(l+1,r),get(l,r-1));
    }
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        a.clear();
        for(auto& u : dp)u.clear();
        dp.clear();
        a.resize(n);
        dp.resize(n,vector<int>(n));
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)dp[i][j]=-1;
        cout<<get(0,n-1)<<endl;
    }
    return 0;
}


