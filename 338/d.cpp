#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    vector<int>x(m+1);
    for(int i=1;i<=m;i++)cin>>x[i];
    vector<int>cnt(n+2,0);
    for(int i=1;i<m;i++)
    {
        int s=x[i],e=x[i+1];
        if(s<e)
        {
            int ac=e-s;
            int cc=n-ac;
            if(ac<=cc)
            {
                cnt[e]-=ac;
                cnt[s]+=ac;
            }
            else 
            {
                cnt[e]+=cc;
                cnt[n+1]-=cc;
                cnt[1]+=cc;
                cnt[s]-=cc;
            }
        }
        else 
        {
            int cc=s-e;
            int ac=n-cc;
            if(ac<=cc)
            {
                cnt[s]+=ac;
                cnt[n+1]-=ac;
                cnt[1]+=ac;
                cnt[e]-=ac;
            }
            else 
            {
                cnt[e]+=cc;
                cnt[s]-=cc;
            }
        }
    }
    for(int i=1;i<=n+1;i++)cnt[i]+=cnt[i-1];
    int bd=-1;
    int mn=1e18;
    for(int i=1;i<=n;i++)
    {
        if(mn>cnt[i])
        {
            mn=cnt[i];
            bd=i;
        }
    }
    cout<<"mn="<<mn<<endl;
    assert(bd!=-1);
    int ans=0;
    for(int i=1;i<m;i++)
    {
        int s=x[i],e=x[i+1];
        if(s<e)
        {
            if(bd>=s && bd<e)
            {
                ans+=(n-e)+(s-1);
                ans+=1;
            }
            else ans+=(e-s);
        }
        else 
        {
            if(bd>=e && bd<s)
            {
                ans+=(n-s)+(e-1);
                ans+=1;
            }
            else ans+=(s-e);
        }
    }
    cout<<ans<<endl;
    return 0;
}


