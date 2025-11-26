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
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int>a(n+1,0);
        rep(i,1,n)cin>>a[i];
        vector<int>xr(n+1,0);
        rep(i,1,n)
        {
            xr[i]=xr[i-1]^a[i];
        }
        map<int,vector<int>>mp;
        rep(i,1,n)mp[xr[i]].pb(i);
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            int val=xr[r]^xr[l-1];
            if(val==0)
            {
                cout<<"YES"<<endl;
            }
            else 
            {
                int s=xr[l-1]^val;
                auto itr=upper_bound(all(mp[s]),l-1);
                int idx=itr-mp[s].begin();
                int left=mp[s][idx];
                if(left<r)
                {
                    int ss=s^val;
                    auto it=upper_bound(all(mp[ss]),left);
                    if(it==mp[ss].end())
                        cout<<"NO"<<endl;
                    else 
                    {
                        int right=mp[ss][it-mp[ss].begin()];
                        if(right<r)
                            cout<<"YES"<<endl;
                        else cout<<"NO"<<endl;
                    }
                }
                else cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}


