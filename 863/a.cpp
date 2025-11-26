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
        int n,d;
        cin>>n>>d;
        string s;
        cin>>s;
        string ans;
        bool done=0;
        for(auto& u : s)
        {
            if(u-'0'<d && !done)
            {
                done=1;
                ans+=char(d+'0');
                ans+=u;
            }
            else ans+=u;
        }
        if(!done)ans+=char(d+'0');
        cout<<ans<<endl;
    }
    return 0;
}


