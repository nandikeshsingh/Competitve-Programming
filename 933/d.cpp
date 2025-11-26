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
        int n,m,x;
        cin>>n>>m>>x;
        set<int>st;
        st.insert(x);
        while(m--)
        {
            int r;char c;
            cin>>r>>c;
            set<int>cur;
            if(c=='0')
            {
                for(auto& u : st)
                {
                    int nw=u+r;
                    if(nw>n)nw-=n;
                    cur.insert(nw);
                }
            }
            else if(c=='1')
            {
                for(auto& u : st)
                {
                    int nw=(u-r);
                    if(nw<=0)nw+=n;
                    cur.insert(nw);
                }
            }
            else 
            {
                for(auto& u : st)
                {
                    int nw=u+r;
                    if(nw>n)nw-=n;
                    cur.insert(nw);
                    nw=(u-r);
                    if(nw<=0)nw+=n;
                    cur.insert(nw);
                }
            }
            st.clear();
            st=cur;
        }
        cout<<sz(st)<<endl;
        for(auto& u :st)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}


