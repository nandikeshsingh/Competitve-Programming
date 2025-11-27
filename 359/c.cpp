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
    int a,b;cin>>a>>b;
    a++,b++;
    int x,y;cin>>x>>y;
    x++,y++;
    int ans=abs(y-b);
    int d=abs(y-b);
    int fx=a;
    if(x>=a)
    {
        fx+=d;
        if(fx>=x)cout<<ans<<endl;
        else 
        {
            if(abs(y)%2!=0)
            {
                ans+=((x+1)/2)-((fx+1)/2);
            }
            else 
            {
                // cout<<"x="<<x<<" fx="<<fx<<endl;
                ans+=((x)/2)-((fx)/2);
            }
            cout<<ans<<endl;
        }
        
    }
    else 
    {
        fx-=d;
        if(fx<=x)cout<<ans<<endl;
        else 
        {
            if(abs(y)%2!=0)
            {
                ans+=((fx+1)/2)-((x+1)/2);
            }
            else 
            {
                ans+=((fx)/2)-((x)/2);
            }    
            cout<<ans<<endl;    
        }
        
    }
    return 0;
}


