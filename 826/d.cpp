#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<int>p;
vector<pair<int,int>>t;
int ans;
int build(int node,int l,int r)
{
    if(l==r)
    {
        t[node].first=p[l];
        t[node].second=p[l];
        return 1;
    }
    else 
    {
        int mid=(l+r)>>1;
        int x=build(node<<1,l,mid);
        int y=build(node<<1|1,mid+1,r);

        if(x&y)
        {
            if(t[node<<1|1].second-t[node<<1].first==1)
            {
                t[node].first=max(t[node<<1].first,t[node<<1|1].first);
                t[node].second=min(t[node<<1].second,t[node<<1|1].second);
                return 1;
            }
            else if(t[node<<1].second-t[node<<1|1].first==1)
            {
                ans++;
                t[node].first=max(t[node<<1].first,t[node<<1|1].first);
                t[node].second=min(t[node<<1].second,t[node<<1|1].second);
                return 1;                
            }
            else 
            {
                return 0;
            }
        }
        else 
        {
            return 0;
        }
    }
}
signed main()
{
    speed;
    int tt;
    cin>>tt;
    while(tt--)
    {
        int m;
        cin>>m;
        p.resize(m);
        for(int i=0;i<=4*m;i++)
        {
            pair<int,int>p={-1e18,1e18};
            t.push_back(p);
        }
        for(int i=0;i<m;i++)cin>>p[i];
        ans=0;
        int ok=build(1,0,m-1);
        if(!ok)ans=-1;
        cout<<ans<<endl;
    }
    return 0;
}


