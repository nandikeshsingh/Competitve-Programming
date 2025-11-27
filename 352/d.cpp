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
    int n,k;
    cin>>n>>k;
    vector<int>p(n+1);
    rep(i,1,n)cin>>p[i];
    set<int>st;
    vector<int>pos(n+1);
    rep(i,1,n)pos[p[i]]=i;
    rep(i,1,k)st.insert(pos[i]);
    int ans=1e18;
    ans=min(ans,*prev(st.end())-*st.begin());
    int l=1,r=k;
    while(r+1<=n)
    {
        st.erase(st.find(pos[l]));
        l++;
        r++;
        st.insert(pos[r]);
        ans=min(ans,*prev(st.end())-*st.begin());
    }
    cout<<ans<<endl;
    return 0;
}


