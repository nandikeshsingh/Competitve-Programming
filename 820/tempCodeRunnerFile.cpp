#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    // speed;
    int l=0,h=18;
    while(l<h)
    {
        int mid=(l+h+1)>>1;
        cout<<"? 1"<<" "<<(int)pow(10,mid)<<endl;
        int ret;cin>>ret;
        if(ret!=-1)l=mid;
        else h=mid-1;       
    }
    int lo=(int)pow(10,l),hi=1e18;
    while(lo<hi)
    {
        int mid=(lo+hi)>>1;
        cout<<"? "<<lo<<" "<<mid<<endl;
        int ret;cin>>ret;
        if(ret!=-1)lo=mid+1;
        else hi=mid;
    }
    cout<<"! "<<lo<<endl;
    return 0;
}


