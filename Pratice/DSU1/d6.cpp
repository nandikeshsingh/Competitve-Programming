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
    cout<<"? "<<1<<" "<<n<<endl;
    int p;cin>>p;
    int lo,hi;
    if(p==1)
    {   
        lo=p+1;hi=n;
        while(lo<hi)
        {
            int mid=(lo+hi)>>1;
            int now=-1;
            cout<<"? "<<p<<" "<<mid<<endl;
            cin>>now;
            if(now==p)hi=mid;
            else lo=mid+1;
        }
        cout<<"! "<<lo<<endl;
    }
    else 
    {
        int cur;
        cout<<"? "<<1<<" "<<p<<endl;
        cin>>cur;
        if(cur==p)
        {
            lo=1;hi=p-1;
            while(lo<hi)
            {
                int mid=(lo+hi+1)>>1;
                // cout<<"lo= "<<lo<<" hi="<<hi<<" mid="<<mid<<endl;
                cout<<"? "<<mid<<" "<<p<<endl;
                int now;cin>>now;
                if(now==p)lo=mid;
                else hi=mid-1;
            }
            cout<<"! "<<lo<<endl;
        }
        else 
        {
            lo=p+1,hi=n;
            while(lo<hi)
            {
                int mid=(lo+hi)>>1;
                int now;
                cout<<"? "<<p<<" "<<mid<<endl;
                cin>>now;
                if(now==p)hi=mid;
                else lo=mid+1;
            }
            cout<<"! "<<lo<<endl;
        }
    }
    return 0;
}
