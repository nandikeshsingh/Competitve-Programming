#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    // for(int i=2;i<=25;i++)
    // {
    //     cout<<"? 1"<<" "<<i<<endl;
    //     int ret;cin>>ret;
    //     if(ret==-1)
    //     {
    //         cout<<"! "<<i-1<<endl;
    //         return 0;
    //     }
    //     cout<<"? "<<i<<" "<<1<<endl;
    //     int ter;cin>>ter;
    //     if(ret!=ter)cout<<"! "<<ret+ter<<endl;
    // }
    speed;
    int l=0,h=18;
    while(l<h)
    {
        int mid=(l+h+1)>>1;
        cout<<"? 1"<<" "<<(int)pow(10LL,mid)<<endl;
        int ret;cin>>ret;
        if(ret!=-1)l=mid;
        else h=mid-1;       
    }
    if(l==18)
    {
        cout<<"! "<<(int)1e18<<endl;
        return 0;
    }
    int lo=(int)pow(10LL,l),hi=(int)pow(10LL,l+1);
    while(lo<hi)
    {
        int mid=(lo+hi+1)>>1;
        cout<<"? "<<lo<<" "<<mid<<endl;
        int ret;cin>>ret;
        if(ret!=-1)lo=mid;
        else hi=mid-1;
    }
    cout<<"! "<<lo<<endl;
    return 0;
}

