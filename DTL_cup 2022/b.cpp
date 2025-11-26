#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int find(int x)
{
    int lo=1,hi=1e9;
    while(lo<hi)
    {
        int mid=(lo+hi)>>1;
        if(mid*mid<x)lo=mid+1;
        else hi=mid;
    }
    if(lo*lo>x)lo--;
    return lo;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        int x=find(l);
        int y=find(r);
        if(x==y)
        {
            cout<<(r/y)-((l-1)/x)<<endl;
        }
        else 
        {
            int ans=3*(y-x-1);
            int up=(x+1)*(x+1)-1;
            int down=l;
            ans+=((up/x)-((down-1)/x));
            up=r;
            down=(y)*(y);
            ans+=((up/y)-((down-1)/y));
            cout<<ans<<endl;
        }
    }
    return 0;
}

