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
    vector<pair<string,int>>vec;
    int tot=0;
    rep(i,1,n)
    {
        string s;int c;
        cin>>s>>c;
        tot+=c;
        vec.pb({s,c});
    }
    sort(all(vec));
    cout<<vec[tot%n].first<<endl;
    return 0;
}


