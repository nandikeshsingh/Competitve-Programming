#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,l;
        cin>>a>>b>>l;
        set<int>st;
        for(int x=0;x<20;x++)
        {
            int xx=pow(a,x);
            if(xx>l)break;
            for(int y=0;y<20;y++)
            {
                int yy=pow(b,y);
                if(yy>l)break;
                int f=xx*yy;
                if(l%f==0)
                {
                    int ll=l;
                    ll/=xx;ll/=yy;
                    // cout<<"x="<<x<<" y="<<y<<endl;
                    // cout<<"xx="<<xx<<" yy="<<yy<<endl;
                    st.insert(ll);
                }
            }
        }
        cout<<sz(st)<<endl;
    }
    return 0;
}


