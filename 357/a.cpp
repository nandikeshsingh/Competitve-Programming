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
using ii = pair<int,int>;
using vii = vector<ii>;
using vi = vector<int>;
signed main()
{
    speed;
    int n,m;cin>>n>>m;
    vi a(n);
    rep(i,0,n-1)cin>>a[i];
    int cnt=0,sum=0;
    rep(i,0,n-1)
    {
        sum+=a[i];
        if(sum<=m)cnt=i+1;
    }
    cout<<cnt<<endl;
    return 0;
}


