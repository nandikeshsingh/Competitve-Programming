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
        int a,b,r;
        cin>>a>>b>>r;
        for(int i=60;i>=0;i--)
        {
            if(((1LL<<i)&a)>0 && ((1LL<<i)&b)>0)
            {
                a^=(1LL<<i);
                b^=(1LL<<i);
            }
        }
 
        if(a>b)
        {
            bool f=0;
            for(int i=60;i>=0;i--)
            {
                if(((1LL<<i)&a)>0)
                {
                    if(f==0)f=1;
                    else 
                    {
                        if((1LL<<i)<=r)
                        {
                            a^=(1LL<<i);
                            b^=(1LL<<i);
                            r-=(1LL<<i);
                        }
                    }
                }
            }
        }
        else if(b>a)
        {
            bool f=0;
            for(int i=60;i>=0;i--)
            {
                if(((1LL<<i)&b)>0)
                {
                    if(f==0)f=1;
                    else 
                    {
                        if((1LL<<i)<=r)
                        {
                            a^=(1LL<<i);
                            b^=(1LL<<i);
                            r-=(1LL<<i);
                        }
                    }
                }
            }
        }
        // cout<<"a="<<a<<" b="<<b<<endl;
        cout<<abs(a-b)<<endl;

    }
    return 0;
}


