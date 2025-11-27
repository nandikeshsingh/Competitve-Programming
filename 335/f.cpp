#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int mod=998244353;
int dp[500][500];
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n+1),ans(n+1,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    ans[1]=1;
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<500;j++)
        {
            ans[i]+=dp[j][i%j];
            ans[i]%=mod;
        }
        if(a[i]<500)
        {
            dp[a[i]][i%a[i]]+=ans[i];
            dp[a[i]][i%a[i]]%=mod;
        }
        else 
        {
            for(int j=i+a[i];j<=n;j+=a[i])
            {
                ans[j]+=ans[i];
                ans[j]%=mod;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        tot+=ans[i];
        tot%=mod;
    }
    cout<<tot<<endl;
    return 0;
}


