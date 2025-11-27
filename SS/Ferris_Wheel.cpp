#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n,x;
    cin>>n>>x;
    vector<int>p(n);
    for(int i=0;i<n;i++)cin>>p[i];
    sort(all(p));
    int ans=0;
    int l=0,r=n-1;
    while(l<r)
    {
        if(p[l]+p[r]<=x)ans++,l++,r--;
        else ans++,r--;
    }
    if(l==r)ans++;
    cout<<ans<<endl;
    return 0;
}


