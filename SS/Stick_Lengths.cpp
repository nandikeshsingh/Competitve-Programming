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
    vector<int>p(n);
    for(int i=0;i<n;i++)cin>>p[i];
    sort(all(p));
    int ans=0;
    for(int i=0;i<n;i++)
    ans+=abs(p[i]-p[n/2]);
    cout<<ans<<endl;
    return 0;
}
