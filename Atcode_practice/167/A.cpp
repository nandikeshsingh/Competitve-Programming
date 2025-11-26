#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(all(a));
    reverse(all(a));
    vector<int>b(m,0);
    int i=0;
    for(auto& u : a)
    {
        b[i]+=u;
        i++;
        if(i>=m)break;
    }
    for(int j=m;j<n;j++)
    {
        i--;
        b[i]+=a[j];
    }
    int ans=0;
    for(auto& u : b)ans+=(u*u);
    cout<<ans<<endl;
    return 0;
}


