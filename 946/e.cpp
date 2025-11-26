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
        int m,x;cin>>m>>x;
        vector<int>c(m+1,0),h(m+1,0);
        for(int i=1;i<=m;i++)cin>>c[i]>>h[i];
        vector<pair<double,int>>vec;
        for(int i=1;i<=m;i++)
        {
            if(i==1 && c[i]>0)continue;
            // if(c[i]==0)vec.pb({1e18,i});
            // else 
            {
                double d=(double)c[i]/(double)h[i];
                vec.pb({d,i});
            }
        }
        sort(all(vec));
        // reverse(all(vec));
        
        int ans=0;
        set<int>st;
        for(int i=0;i<sz(vec);i++)
        {
            st.insert(vec[i].S);
            bool ok=1;
            int money=0;
            int cur_happy=0;
            for(int j=1;j<=m;j++)
            {
                if(st.count(j))
                {
                    if(money>=c[j])
                    {
                        money-=c[j];
                        cur_happy+=h[j];
                    }
                    else ok=0;
                }
                money+=x;
            }
            if(ok)ans=max(ans,cur_happy);
        }
        cout<<ans<<endl;
    }   
    return 0;
}
