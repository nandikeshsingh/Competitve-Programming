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
        int x,y,k;
        cin>>x>>y>>k;
        int d=x/y;
        int e=d*y+y;
        int last_x=x;
        int ans=-1;
        int cur=x;
        while(1)
        {
            if(cur+k<e)
            {
                ans=cur+k;
                break;
            }
            else 
            {
                int op=e-cur;
                k-=op;
                while(e%y==0)e/=y;
                cur=e;
                if(k==0)
                {
                    ans=cur;
                    break;
                }
                int d=cur/y;
                e=d*y+y;
                if(cur==last_x)
                {
                    int left=k%(e-cur);
                    ans=cur+left;
                    break;
                }
                else last_x=cur;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


