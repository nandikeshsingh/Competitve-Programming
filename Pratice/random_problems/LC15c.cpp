#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n,k;
vector<int>a;
const int maxn=7e6;
int dp[maxn][2];
int hsh(int a,int b)
{
    int x=31;
    return a+b*x;
}
int get(int cur,int o,int tot,int t)
{
    if(tot==k)return cur&1;
    if(dp[hsh(o,tot)][t]!=-1)return dp[hsh(o,tot)][t];
    int ans=0;
    if(tot-o==0)ans=get(1-cur,o-1,tot-1,1-t);
    else if(o==0)ans=get(cur,o,tot-1,1-t);
    else 
    {
        if(t==1)
        {
            if(cur&1)ans= get(1-cur,o-1,tot-1,1-t)|get(cur,o,tot-1,1-t);
            else ans= get(1-cur,o-1,tot-1,1-t)|get(cur,o,tot-1,1-t);
        }
        else 
        {
            if(cur&1)ans= get(1-cur,o-1,tot-1,1-t)&get(cur,o,tot-1,1-t);
            else ans= get(1-cur,o-1,tot-1,1-t)&get(cur,o,tot-1,1-t);
        }
    }
    return dp[hsh(o,tot)][t]=ans;
}
signed main()
{
    speed;
    cin>>n>>k;
    a.resize(n);
    for(int i=0;i<7e6;i++)
    {
        for(int j=0;j<2;j++)
        dp[i][j]=-1;
    }
    int o=0,cur=0;
    for(int i=0;i<n;i++)cin>>a[i],o+=(a[i]&1),cur+=a[i];
    if(get(cur&1,o,n,1))cout<<"Stannis"<<endl;
    else cout<<"Daenerys"<<endl;
    return 0;
}


