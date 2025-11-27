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
    int n,t;
    cin>>n>>t;
    vector<int>a(t+1,0);
    rep(i,1,t)cin>>a[i];
    vector<int>row(n+1,0),col(n+1,0);
    int ld=0,rd=0;
    rep(i,1,t)
    {
        int r=(a[i]+n-1)/n;
        int c=a[i]%n;
        if(c==0)c=n;
        row[r]++;col[c]++;
        if(r==c)ld++;
        int ic=n-c+1;
        if(ic==r)rd++;
        if(row[r]==n || col[c]==n || ld==n || rd==n)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}


