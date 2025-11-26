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
        int n;
        cin>>n;
        vector<int>a(n);
        fo(i,n)cin>>a[i];
        int ans=0;
        rep(bit,0,29)
        {
            vector<int>temp;
            rep(i,0,n-1)
            {
                if((1LL<<bit)&a[i])temp.pb(1);
                else temp.pb(0);
            }
            int cur=0;
            int best=0;
            rep(i,0,n-1)
            {
                if(temp[i]==0)
                {
                    cur++;
                }
                else 
                {
                    best=max(best,cur);
                    cur=0;
                }
            }
            best=max(best,cur);
            best++;
            if(best>n)best=1;
            ans=max(ans,best);
        }
        cout<<ans<<endl;
    }
    return 0;
}


