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
        vi a(n);
        rep(i,0,n-1)cin>>a[i];

    //         int tot=n;
    // vi vec;
    // while(tot<=100000)
    // {
    //     int left=0;
    //     rep(i,0,n-1)
    //     {
    //         int x=tot/a[i];
    //         left+=(x+1);
    //     }
    //     // cout<<"left="<<left<<" right="<<tot<<endl;
    //     if(left<=tot)vec.pb(1);
    //     else vec.pb(0);
    //     tot++;
    // }
    // for(auto& u :vec)cout<<u<<" ";
    // cout<<endl;


        int lo=n,hi=((1e9)+1);
        int ans=-1;
        while(lo<hi)
        {
            int tot=(lo+hi)>>1;
            // cout<<"lo="<<lo<<" hi="<<hi<<" tot="<<tot<<endl;
            int all=0;
            rep(i,0,n-1)
            {
                int x=(tot/a[i]);
                if(x+1>1e9)
                {
                    all=tot+1;
                    break;
                }
                all+=(x+1);
            }
            if(all>tot)
            {
                lo=tot+1;
            }
            else 
            {
                ans=tot;
                break;
            }
        }
        if(ans==-1 || ans>(n*(1e9)))cout<<-1<<endl;
        else 
        {
            rep(i,0,n-1)
            {
                int x=(ans/a[i]);
                assert(x+1>=1 && x+1<=1e9);
                cout<<x+1<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}


