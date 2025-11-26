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
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        vector<int>p(n+m+2,0),t(n+m+2,0);
        rep(i,1,n+m+1)cin>>p[i];
        rep(i,1,n+m+1)cin>>t[i];
        vector<int>pp(n+m+2,0),sp(n+m+3,0),pt(n+m+2,0),st(n+m+3,0);
        vector<int>cntp(n+m+2,0),cntt(n+m+2,0);
        rep(i,1,n+m+1)
        {
            if(p[i]>t[i])
            {
                pp[i]=pp[i-1]+p[i];
                pt[i]=pt[i-1];
                cntp[i]=cntp[i-1]+1;
                cntt[i]=cntt[i-1];
            }
            else 
            {
                pp[i]=pp[i-1];
                pt[i]=pt[i-1]+t[i];
                cntp[i]=cntp[i-1];
                cntt[i]=cntt[i-1]+1;
            }
        }
        per(i,n+m+1,1)
        {
            sp[i]=sp[i+1]+p[i];
            st[i]=st[i+1]+t[i];
        }
        vector<int>ans(n+m+2,0);
        rep(i,1,n+m+1)
        {
            int itrp=0,itrt=0;
            if(cntp[i-1]>=n)
            itrp=lower_bound(all(cntp),n)-cntp.begin();
            else 
            {
                if(p[i]>t[i])
                itrp=lower_bound(all(cntp),n+1)-cntp.begin();
                else itrp=lower_bound(all(cntp),n)-cntp.begin();
            }
            if(cntt[i-1]>=m)
            itrt=lower_bound(all(cntt),m)-cntt.begin();
            else 
            {
                if(t[i]>p[i])
                itrt=lower_bound(all(cntt),m+1)-cntt.begin();
                else itrt=lower_bound(all(cntt),m)-cntt.begin();
            }

            int pos=min(itrp,itrt);
            assert(pos!=i);
            if(pos<i)
            {
                if(cntp[pos]==n)
                ans[i]=pp[pos]+pt[pos]+st[pos+1]-t[i];
                else ans[i]=pp[pos]+pt[pos]+sp[pos+1]-p[i];
            }
            else 
            {
                if(p[pos]>t[pos])
                    ans[i]=pp[pos]+pt[pos]+st[pos+1]-(p[i]>t[i]?p[i]:t[i]);
                else 
                    ans[i]=pp[pos]+pt[pos]+sp[pos+1]-(p[i]>t[i]?p[i]:t[i]);
            }
        }
        rep(i,1,n+m+1)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}


