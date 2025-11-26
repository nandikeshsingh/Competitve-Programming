#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int dp[101][1<<17];
int val[101][1<<17];
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    int p[17]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
    int bit[60]={0};
    for(int i=2;i<60;i++)
    {
        for(int j=0;j<17;j++)
        {
            if(i%p[j]==0)bit[i]|=(1<<j);
        }
    }
    int pos=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<(1<<17);j++)
        {
            dp[i][j]=1e18;
            for(int b=1;b<60;b++)
            {
                if((bit[b]&j)==bit[b])
                {
                    int cur=dp[i-1][j^bit[b]]+abs(b-a[i]);
                    if(cur<dp[i][j])
                    {
                        dp[i][j]=cur;
                        val[i][j]=b;
                    }
                }
            }
        }
    }
    int mn=1e18;
    for(int j=0;j<(1<<17);j++)
    {
        if(dp[n][j]<mn)
        {
            mn=dp[n][j];
            pos=j;
        }
    }
    int idx=n;
    vector<int>ans;
    while(idx>0)
    {
        ans.push_back(val[idx][pos]);
        pos^=bit[val[idx][pos]];
        idx--;
    }
    reverse(all(ans));
    for(auto& u : ans)cout<<u<<" ";
    cout<<endl;
    return 0;
}


