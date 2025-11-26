#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,p,l,t;
        cin>>n>>p>>l>>t;
        int tot=n/7;
        int days=0;
        if(n%7!=0)tot++;
        if(tot%2)
        {
            int d=tot/2;
            int cur=(2*t+l)*d;
            if(cur>=p)
            {
                days=ceil((double)p/(double)(2*t+l));
            }
            else 
            {
                days=d;
                int rim=p-cur;
                rim-=(t+l);
                days++;
                if(rim>0)
                {
                    int need=ceil((double)rim/(double)l);
                    days+=need;
                }
            }
        }
        else 
        {
            int d=tot/2;
            int cur=(2*t+l)*d;
            if(cur>=p)
            {
                days=ceil((double)p/(double)(2*t+l));
            }
            else 
            {
                days=d;
                int rim=p-cur;
                if(rim>0)
                {
                    int need=ceil((double)rim/(double)l);
                    days+=need;
                }
            }
        }
        cout<<n-days<<endl;
    }
    return 0;
}


