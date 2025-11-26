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
        int n;
        cin>>n;
        vi a(n+1,0),b(n+1,0),ok(n+1,0),pre(n+1,1),suf(n+1,1);
        rep(i,1,n)cin>>a[i];
        rep(i,1,n-1)b[i]=__gcd(a[i],a[i+1]);
        rep(i,1,n-1)
        {
            if(b[i]>=b[i-1])pre[i]=1&pre[i-1];
            else pre[i]=0;
        }
        per(i,n-2,0)
        {
            if(b[i]<=b[i+1])suf[i]=suf[i+1]&1;
            else suf[i]=0;
        }
        b[n]=1e18;
        ok[1]=1;
        rep(i,2,n-1)
        {
            int gcd=__gcd(a[i-1],a[i+1]);
            if(gcd<=b[i+1] && gcd>=b[i-2])ok[i]=1;
            else ok[i]=0;
        }
        bool ans=0;
        int cnt=0;
        rep(i,1,n-1)
        {
            if(i==1)
            {
                if(ok[i]&&suf[i+1]&&pre[i-1])
                {
                    ans=1;
                    break;
                }
            }
            else 
            {
                if(ok[i] && suf[i+1] && pre[i-2])
                {
                    ans=1;
                    break;
                }
            }
        }
        if(pre[n-2])ans=1;
        if(!ans)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}


