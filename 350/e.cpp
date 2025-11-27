#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n,a;
double x,y;
map<int,double>dp;
double get(int n)
{
    // cout<<"n="<<n<<endl;
    if(n==0)return dp[n]=0.0;
    if(dp.find(n)!=dp.end())return dp[n];
    double ans=0.0;
    ans=x+get(n/a);
    double best=get(n/2)+get(n/3)+get(n/4)+get(n/5)+get(n/6);
    best/=5.0;
    best+=((double)6*y/(double)5);
    // cout<<"ans="<<ans<<" best="<<best<<endl;
    ans=min(ans,best);
    return dp[n]=ans;
}
signed main()
{
    speed;
    cin>>n>>a>>x>>y;
    cout<<fixed<<setprecision(10)<<get(n)<<endl;
    return 0;
}


