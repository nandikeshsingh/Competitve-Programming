#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,q;
    cin>>n>>q;
    vector<int>r(n);
    for(int i=0;i<n;i++)
    {
        cin>>r[i];
    }
    sort(all(r));
    for(int i=1;i<n;i++)r[i]+=r[i-1];
    while(q--)
    {
        int x;cin>>x;
        int ans=upper_bound(all(r),x)-r.begin();
        cout<<ans<<endl;
    }
    return 0;
}


