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
    vector<int>a(n),b(n);
    fo(i,n)cin>>a[i]>>b[i];
    int mx=0;
    int sum=0;
    fo(i,n)mx=max(mx,b[i]-a[i]),sum+=a[i];
    cout<<sum+mx<<endl;
    return 0;
}


