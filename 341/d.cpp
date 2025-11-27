#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n,m,k,g,l;
int check(int cur)
{
    return cur/n + cur/m  - 2*(cur/l);
}
signed main()
{
    speed;
    
    cin>>n>>m>>k;
    g=__gcd(n,m);
    l=(n*m)/g;
    int lo=1,hi=1e18;
    int ans=-1;
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        // cout<<"lo="<<lo<<" hi="<<hi<<" mid="<<mid<<endl;
        int calc=check(mid);
        if(calc>=k)hi=mid;
        else if(calc<k)lo=mid+1;
    }
    cout<<lo<<endl;
    return 0;
}


