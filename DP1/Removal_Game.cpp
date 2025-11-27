#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<int>x;
int dp[5001][5001][2];
int get(int l,int r,int t)
{
    if(l==r && t==1)return x[l];
    else if(l==r && t==0)return 0;
    if(dp[l][r][t]!=-1)return dp[l][r][t];
    if(t) return dp[l][r][t]=max(x[l]+get(l+1,r,1-t),x[r]+get(l,r-1,1-t));
    else return dp[l][r][t]=min(get(l+1,r,1-t),get(l,r-1,1-t));
}
signed main()
{
    speed;
    int n;
    cin>>n;
    x.resize(n);
    for(int i=0;i<=5000;i++)
    for(int j=0;j<=5000;j++)
    for(int k=0;k<2;k++)
    dp[i][j][k]=-1;
    for(int i=0;i<n;i++)cin>>x[i];
    cout<<get(0,n-1,1)<<endl;
    return 0;
}


