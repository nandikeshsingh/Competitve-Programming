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
        vector<int>a(n);
        int mx=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mx=max(mx,a[i]);
        }
        if(n>=4)
        {
            cout<<n*mx<<endl;
        }
        else if(n==2)
        {
            cout<<max(a[0]+a[1],2LL*abs(a[1]-a[0]))<<endl;
        }
        else 
        {
            if(a[2]==mx || a[0]==mx)cout<<3*mx<<endl;
            else
            {
                int x=abs(a[0]-a[1])*3;
                int ll=abs(a[0]-a[1]);
                x=max(x,3*a[2]);
                x=max(x,3*abs(ll-a[2]));
                x=max(3*ll,x);
                int rr=abs(a[2]-a[1]);
                x=max(x,3*a[0]);
                x=max(x,3*abs(a[0]-rr));
                x=max(x,3*rr);
                x=max(x,a[0]+a[1]+a[2]);
                cout<<x<<endl;
            }
        }
    }
    return 0;
}


