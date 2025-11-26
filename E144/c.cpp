#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int mod=998244353;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        int k=0;
        int cur=r/l;
        while((1<<k)<=cur)k++;
        int p=k-1;
        int ans=(r>>p)-l+1;
        if(p)
        {
            r>>=p-1;
            r/=3;
            if(r>=l)ans+=p*(r-l+1);
        }
        cout<<k<<" "<<ans<<endl;
    }
    return 0;
}




