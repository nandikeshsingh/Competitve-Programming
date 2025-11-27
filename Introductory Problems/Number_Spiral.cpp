#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;cin>>x>>y;
        int mx=max(x,y);
        int ans=(mx-1)*(mx-1);
        if(x>y)
        {
            if(x%2)ans+=y;
            else ans+=(x+mx-y);
        }
        else 
        {
            if(y%2==0)ans+=x;
            else ans+=(y+mx-x);
        }
        cout<<ans<<endl;
    }
    return 0;
}

