#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<int>k;
bool ok(int mid,int t)
{
    int can=0;
    for(int u: k)
    {
        can+=(mid/u);
        if(can>=t)return 1;
    }
    return 0;
}
signed main()
{
    speed;
    int n,t;
    cin>>n>>t;
    k.resize(n);
    for(int i=0;i<n;i++)cin>>k[i];
    int lo=0LL,hi=1e18;
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        if(ok(mid,t))hi=mid;
        else lo=mid+1;
    }
    cout<<hi<<endl;
    return 0;
}


