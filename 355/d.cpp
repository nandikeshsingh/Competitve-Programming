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
    int n;
    cin>>n;
    vector<pair<int,int>>vec;
    rep(i,0,n-1)
    {
        int l,r;cin>>l>>r;
        vec.pb({r,l});
    }
    sort(all(vec));
    vector<int>a;
    rep(i,0,n-1)a.pb(vec[i].F);
    int cnt=0;
    rep(i,1,n-1)
    {
        auto itr=lower_bound(all(a),vec[i].S)-a.begin();
        cnt+=i-itr;
    }
    cout<<cnt<<endl;
    return 0;
}


