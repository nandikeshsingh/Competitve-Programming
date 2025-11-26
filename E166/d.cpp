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
        string s;cin>>s;
        int n=s.length();
        vector<int>a(n+1,0);
        rep(i,0,n-1)
        {
            if(s[i]=='(')a[i+1]=1;
            else a[i+1]=-1;
        }
        rep(i,1,n)a[i]+=a[i-1];
        vector<vector<int>>pos(4*n+5,vector<int>(0));
        int ans=0;
        rep(i,1,n)
        {
            // cout<<"i="<<i<<endl;
            // if(i>1)
            {
                if(sz(pos[a[i]+a[i]+1])>0)
                {
                    int p=pos[a[i]+a[i]+1].back();
                    auto itr=upper_bound(all(pos[a[i]]),p);
                    if(itr!=pos[a[i]].end())
                    {
                        int idx=itr-pos[a[i]].begin();
                        ans+=sz(pos[a[i]])-idx;
                    }
                }
                else 
                {
                    ans+=sz(pos[a[i]]);
                }

            }

            pos[a[i]].pb(i);
        }
        cout<<ans<<endl;
    }
    return 0;
}


