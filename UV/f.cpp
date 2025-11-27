#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n,k;
vector<long double>x,y;
long double dis(int i,int j)
{
    long double ret=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    return sqrt(ret);
}
signed main()
{
    speed;
    cin>>n>>k;
    x.resize(n+1);y.resize(n+1);
    for(int i=0;i<=n;i++)cin>>x[i]>>y[i];
    long double ans=0;
    vector<long double>d;
    d.push_back(0);
    for(int i=1;i<=n;i++)
    {
        ans+=dis(i,i-1);
        if(i<n)
        d.push_back(dis(i,0)+dis(0,i+1)-dis(i,i+1));
    }
    ans+=dis(n,0);
    d.push_back(0);
    vector<long double>dp(n+1,0);
    multiset<long double>mst;
    for(int i=1;i<=n;i++)
    {
        if(i<=k)mst.insert(d[i]);
        else 
        {
            dp[i]=*mst.begin();
            mst.erase(mst.find(d[i-k]+dp[i-k]));
            mst.insert(dp[i]+d[i]);
        }

    }
    cout<<fixed<<setprecision(15)<<ans+dp[n]<<endl;
    return 0;
}


