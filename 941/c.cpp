#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;

bool get(int i,vector<int>a)
{
    cout<<"i="<<i<<endl;
    if(i==sz(a)-1)
    {
        if(a[i]>0)return 1;
        else return 0;
    }
    else if(i==sz(a))return 0;
    bool ans=1;
    vector<int>ca=a;
    for(int i=1;i<=a[i];i++)
    {
        if(i==a[i])
        {
            ca[i]=0;
            ans&=get(i+1,ca);
        }
        else 
        {
            ca[i]-=i;
            ans&=get(i,ca);
        }
    }
    if(ans)return 0;
    else return 1;
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
        vector<int>a(n+1,0);
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(all(a));
        bool dp[2][n+1]={0};
        dp[0][n]=1;//bottom
        dp[1][n]=1;//up
        for(int i=n-1;i>=1;i--)
        {
            if(a[i]==a[i+1])
            {
                dp[0][i]=dp[0][i+1];
                dp[1][i]=dp[1][i+1];
            }
            else 
            {
                if(dp[0][i+1]==1)dp[1][i]=0;
                else dp[1][i]=1;
            }


            if(a[i]-a[i-1]>1)dp[0][i]=1;
            else dp[0][i]=dp[1][i];

        }
        if(dp[0][1]==1)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}


