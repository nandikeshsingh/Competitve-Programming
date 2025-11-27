#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
long double dp[(1<<15)][16];
signed main()
{
    speed;
    int n,d;
    cin>>n>>d;
    vector<long double>w(n);
    long double tot=0;
    for(int i=0;i<n;i++)cin>>w[i],tot+=w[i];
    long double av=tot/(long double)d;
    for(int i=0;i<(1<<n);i++)
    {
        dp[i][0]=0;
        long double sum=0;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))sum+=w[j];
        }
        dp[i][1]=(sum-av)*(sum-av);
        for(int j=2;j<=d;j++)
        {
            dp[i][j]=dp[i][j-1]+dp[0][1];
            int cur=i;
            while(cur)
            {
                dp[i][j]=min(dp[i][j],dp[i-cur][j-1]+dp[cur][1]);
                cur=(cur-1)&i;
            }
        }
    }
    long double ans=dp[(1<<n)-1][d];
    cout<<setprecision(7)<<(ans/(long double)d)<<endl;
    return 0;
}


