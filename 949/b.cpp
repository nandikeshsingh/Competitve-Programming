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
        int n,m;
        cin>>n>>m;
        int x=max(n-m,0LL);
        int y=n+m;
        int ans=x|y;
        per(bit,29,0)
        {
            if(((1LL<<bit)&x)==0)
            {   
                int num=x|(1LL<<bit);
                int xr=(1LL<<bit)-1LL;
                xr=~xr;
                num&=xr;
                if(num>=x && num<=y)ans|=(1LL<<bit);
            }
            if(((1LL<<bit)&y)==0)
            {
                int num=y|(1LL<<bit);
                int cur=bit+1;
                while(((1LL<<cur)&y)==0 && cur<=29)cur++;
                num^=(1LL<<cur);
                if(num>=x && num<=y)ans|=(1LL<<bit);
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}


