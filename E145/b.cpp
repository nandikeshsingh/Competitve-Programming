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
        int n;
        cin>>n;
        if(n==1)cout<<0<<endl;
        else if(n>=2 && n<=4)cout<<1<<endl;
        else if(n==5)cout<<2<<endl;
        else 
        {
            n-=5;
            int lo=0,hi=1e9;
            while(lo<hi)
            {
                int k=(lo+hi+1)>>1;
                if(k*(12+4*k)<=n)
                lo=k;
                else hi=k-1;
            }
            int rim=n-(lo*(12+4*lo));
            // cout<<"rim="<<rim<<endl;
            int up=(lo*2)+2;
            cout<<"up="<<up<<endl;
            int nxt=up+2;
            if(rim==0)cout<<2*up<<endl;
            else if(rim<=nxt*2)
            {
                int div=rim/4;
                int y=0;
                if(div>0)
                y=(div-1)*2;
                int rr=rim%4;
                if(rr==0)
                cout<<up+1+y<<endl;
                else cout<<up+1+y+2<<endl;
                cout<<"in"<<endl;
            }
            else 
            {
                int div=rim/4;
                int y=0;
                if(div>0)
                y=(div-1)*2;
                int rr=rim%4;
                if(rr==0)
                cout<<up+2+y<<endl;
                else cout<<up+2+y+2<<endl;               
            }
        }
    }
    return 0;
}

