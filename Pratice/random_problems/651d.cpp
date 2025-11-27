#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<int>a;
int n,k;
bool check(int x)
{
    bool ok1=1,ok2=1;
    int cnt=0;
    bool p=1;
    for(int i=0;i<n;i++)
    {
        if(p)
        {
            if(a[i]<=x)cnt++,p=0;
        }
        else cnt++,p=1;
    }
    if(cnt<k)ok1=0;
    p=1,cnt=0;
    for(int i=0;i<n;i++)
    {
        if(!p)
        {
            if(a[i]<=x)cnt++,p=1;
        }
        else cnt++,p=0;
    }
    if(cnt<k)ok2=0;
    return ok1|ok2;
}
signed main()
{
    speed;
    cin>>n>>k;
    a.resize(n);
    int mx=-1e18;
    for(int i=0;i<n;i++)cin>>a[i],mx=max(mx,a[i]);
    int lo=1,hi=mx;
    while(hi>lo)
    {
        int mid=(lo+hi)/2;
        if(check(mid))hi=mid;
        else lo=mid+1;
    }
    cout<<hi<<endl;
    return 0;
}


