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
        vector<int>a(6,0),p(6,0);
        for(int i=1;i<=5;i++)cin>>a[i];
        for(int i=1;i<=5;i++)cin>>p[i];
        int get=a[2]+2*a[1]-a[4]-2*a[5];
        if(get<=0)cout<<0<<endl;
        else 
        {
            if(2*p[4]<=p[5])cout<<get*p[4]<<endl;
            else if(p[5]<=p[4])cout<<((get+1)/2)*p[5]<<endl;
            else 
            {
                int cost_0=((get+1)/2)*p[5];
                int cost_1=(((get)/2)*p[5])+p[4];
                cout<<min(cost_0,cost_1)<<endl;
            }
        }
    }
    return 0;
}


