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
    int a,b;cin>>a>>b;
    if(a==b)cout<<-1<<endl;
    else 
    {
        if(1!=a && 1!=b)cout<<1<<endl;
        else if(2!=a && 2!=b)cout<<2<<endl;
        else cout<<3<<endl;
    }
    return 0;
}


