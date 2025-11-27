#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>vec(n);
    int tot=0;
    int ans=1e18;
    for(int i=0;i<n;i++)cin>>vec[i],tot+=vec[i];
    for(int mask=0;mask<(1<<n);mask++)
    {
        int cur=0;
        for(int bit=19;bit>=0;bit--)
        {
            if((mask>>bit)&1)cur+=vec[bit];
        }
        ans=min(ans,abs(tot-2*cur));
    }
    cout<<ans<<endl;
    return 0;
}


