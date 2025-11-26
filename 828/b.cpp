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
        int n,q;
        cin>>n>>q;
        vector<int>a(n);
        int od=0,ev=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            ans+=a[i];
            if(a[i]%2)od++;
            else ev++;
        }
        while(q--)
        {
            int t,x;
            cin>>t>>x;
            if(t)
            {
                if(x%2)
                {
                    ans+=od*x;
                    ev+=od;
                    od=0;
                }
                else 
                {
                    ans+=od*x;
                }
            }
            else 
            {
                if(x%2)
                {
                    ans+=ev*x;
                    od+=ev;
                    ev=0;
                }
                else 
                {
                    ans+=ev*x;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}


