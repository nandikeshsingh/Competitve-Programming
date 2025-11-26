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
        int a1,a2,a3,a4;
        cin>>a1>>a2>>a3>>a4;
        if(a1==0)cout<<1<<endl;
        else 
        {
            int ans=a1;
            ans+=(2*min(a2,a3));
            int mn=min(a2,a3);
            a2-=mn;
            a3-=mn;
            if(a4>a1)ans+=(a1+1);
            else 
            {
                ans+=a4;
                a1-=a4;
                int rim=max(a2,a3);
                if(rim>a1)ans+=(a1+1);
                else ans+=rim;
            }
            cout<<ans<<endl;

        }
    }
    return 0;
}


