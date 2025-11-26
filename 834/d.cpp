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
        int n,m;
        cin>>n>>m;
        int t=0,f=0;
        int cn=n;
        while(cn%5==0)
        {
            f++;
            cn/=5;
        }
        while(cn%2==0)
        {
            cn/=2;
            t++;
        }
        int k=1;
        
        if(t>f)
        {
            int need=t-f;
            while(k*5<=m)
            {
                k*=5;
                need--;
                t--;
                if(need==0)break;
            }
        }
        else if(f>t)
        {
            int need=f-t;
            while(k*2<=m)
            {
                k*=2;
                need--;
                f--;
                if(need==0)break;
            }           
        }
        // assert(t==f);
       while(k*10<=m)k*=10;
        int extra=m/k;
        k*=extra;
        cout<<n*k<<endl;
    }
    return 0;
}


