#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,n)   for(int i=0;i<(n);++i)
#define rep(i,a,b)   for(int i=(a);i<=(b);++i)
#define per(i,b,a)   for(int i=(b);i>=(a);--i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define pb push_back
#define F first
#define S second
using namespace std;
int n;
vector<int>a,b;
int dp[(1LL<<19)];
bool get(vector<int>&c)
{
    if(sz(c)<=1)return 0;
    int hash=0LL;
    for(int i=1;i<=n;i++)
    {
        if(c[i]==1)
        {
            int bit=i-1;
            hash+=(1LL<<bit);
        }
    }
    if(dp[hash]!=-1)return dp[hash];
    bool ans=1;
    int n=sz(c);
    bool f=0;
    bool ret=0;
    for(int i=1;i<=n;i++)
    {
        if(c[i]==0)continue;
        for(int j=i+1;j<=n;j++)
        {   
            if(c[j]==0)continue;
            if(a[i]==a[j] || b[i]==b[j])
            {
                f=1;
                c[i]=0;c[j]=0;
                ans&=get(c);
                c[i]=1;c[j]=1;
            }
        }
    }
    if(f==0)ret=0;
    else 
    {
        if(ans==0)ret=1;
        else ret=0;
    }
    return dp[hash]=ret;
}
signed main()
{
    speed;
    rep(i,0,(1LL<<19)-1)dp[i]=-1;
    cin>>n;
    a.resize(n+1);
    b.resize(n+1);
    vector<int>c(n+1,1);
    c[0]=0;
    rep(i,1,n)cin>>a[i]>>b[i];
    if(get(c))cout<<"Takahashi"<<endl;
    else cout<<"Aoki"<<endl;
    return 0;
}


