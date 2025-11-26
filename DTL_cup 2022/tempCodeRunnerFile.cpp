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
        int l,r;
        cin>>l>>r;
        int x=sqrt(l);
        int y=sqrt(r);
        if(x==y)
        {
            cout<<(r/y)-((l-1)/x)<<endl;
        }
        else 
        {
            int ans=3*(y-x-1);
            int up=(x+1)*(x+1)-1;
            int down=l;
            ans+=((up/x)-((down-1)/x));
            up=r;
            down=y*y;
            ans+=((up/y)-((down)/y));
            cout<<ans<<endl;
        }
        

    }
    return 0;
}


