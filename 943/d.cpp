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
        int n,k,pb,ps;cin>>n>>k>>pb>>ps;
        vector<int>p(n+1),a(n+1);
        rep(i,1,n)
        {
            cin>>p[i];
        }
        rep(i,1,n)cin>>a[i];
        int bs=0,ss=0;
        //calc bs;
        vector<int>pos;
        pos.pb(pb);
        int cur=p[pb];
        while(cur!=pb)
        {
            pos.pb(cur);
            cur=p[cur];
        }
        int sum=0;
        for(int i=0;i<sz(pos);i++)
        {   
            if(i>=k)break;
            int cur_score=sum+(k-i)*a[pos[i]];
            sum+=a[pos[i]];
            bs=max(bs,cur_score);
        }
        //calc ss;
        pos.clear();
        pos.pb(ps);
        cur=p[ps];
        while(cur!=ps)
        {
            pos.pb(cur);
            cur=p[cur];
        }
        
        sum=0;
        for(int i=0;i<sz(pos);i++)
        {   
            if(i>=k)break;
            int cur_score=sum+(k-i)*a[pos[i]];
            sum+=a[pos[i]];
            ss=max(ss,cur_score);
        }
        if(bs>ss)cout<<"Bodya"<<endl;
        else if(ss>bs)cout<<"Sasha"<<endl;
        else cout<<"Draw"<<endl;
    }
    return 0;
}


