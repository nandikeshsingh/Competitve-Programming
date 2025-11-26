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
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vi a(n),b(n);
        multiset<int>diff,all;
        rep(i,0,n-1)cin>>a[i];
        rep(i,0,n-1)
        {
            cin>>b[i];
            all.insert(b[i]);
            if(a[i]!=b[i])
            diff.insert(b[i]);
        }
        int m;cin>>m;
        vi d(m);
        rep(i,0,m-1)cin>>d[i];
        bool ok=0;
        int last=-1;
        rep(i,0,m-1)
        {
            if(diff.find(d[i])!=diff.end())
            {
                diff.erase(diff.find(d[i]));
                last=i;
            }
        }
        if(sz(diff)!=0)cout<<"NO"<<endl;
        else 
        {
            if(all.find(d[m-1])==all.end())cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}


