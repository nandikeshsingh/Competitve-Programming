#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n),ans(n,-1),f((1LL<<22)-1,0);
    for(int i=0;i<n;i++)cin>>a[i],f[a[i]^((1LL<<22)-1)]=a[i];
    for(int i=0;i<=21;i++)
    {
        for(int mask=0;mask<(1<<22);mask++)
        {
            if(f[mask|(1LL<<i)])f[mask]=f[mask|(1LL<<i)];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(f[a[i]])cout<<f[a[i]]<<" ";
        else cout<<-1<<" ";
    }
    cout<<endl;
    return 0;
}


