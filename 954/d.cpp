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
        string s;cin>>s;
        bool f=0;
        rep(i,0,n-1)
        {
            if(s[i]=='0')f=1;
        }
        if(f && n>3)
        {
            cout<<0<<endl;
            continue;
        }
        int ans=1e18;
        rep(i,1,n-1)
        {
            //i and i-1 are stiched
            vector<int>a;
            rep(j,0,i-2)
            {
                a.pb(s[j]-'0');
            }
            int cur=s[i-1]-'0';
            cur*=10;
            cur+=(s[i]-'0');
            a.pb(cur);
            rep(j,i+1,n-1)
            {
                a.pb(s[j]-'0');
            }
            // cout<<"Printing a"<<endl;
            // for(auto& u : a)cout<<u<<" ";
            // cout<<endl;
            int val=a[0];
            int len=a.size();
            vector<int>final;
            rep(j,1,len-1)
            {
                if(a[j]==1 || val==1 || a[j]==0 || val==0)
                {
                    val*=a[j];
                }
                else 
                {
                    final.pb(val);
                    val=a[j];
                }
            }
            final.pb(val);
            // cout<<"Printing final"<<endl;
            // for(auto& u : final)cout<<u<<" ";
            // cout<<endl;
            int tot=0;
            for(auto& u : final)
            tot+=u;
            // cout<<"i="<<i<<" tot="<<tot<<endl;
            ans=min(ans,tot);
        }
        cout<<ans<<endl;
    }
    return 0;
}


