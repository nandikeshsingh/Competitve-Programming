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
    int n;cin>>n;
    vector<pair<int,pair<int,int>>>vec;
    rep(i,1,n)
    {
        int a,c;cin>>a>>c;
        vec.pb({c,{a,i}});
    }
    sort(all(vec));
    vector<bool>ok(n+1,1);
    ok[0]=0;
    int mxa=0;
    int cnt=n;
    rep(i,0,n-1)
    {
        if(vec[i].S.F<mxa)
        {
            ok[vec[i].S.S]=0;
            cnt--;
        }
        else mxa=max(mxa,vec[i].S.F);

    }
    cout<<cnt<<endl;
    rep(i,1,n)
    {
        if(ok[i])cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}


