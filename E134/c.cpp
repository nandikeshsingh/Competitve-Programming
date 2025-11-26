#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
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
        multiset<int>b;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            b.insert(x);
        }
        vector<int>dmn(n),dmx(n);
        for(int i=0;i<n;i++)
        {
            auto it=b.lower_bound(a[i]);
            dmn[i]=(*it-a[i]);
            
        }
        // cout<<"out1"<<endl;
        for(int i=n-1;i>=0;i--)
        {
            auto it=b.lower_bound(a[i]);
            // if(it==prev(b.end()))
            // {
            //     dmx[i]=*it-a[i];
            //     b.erase(it);
            // }
            // else 
            {
                
                dmx[i]=*prev(b.end())-a[i];
                b.erase(it);
            }
            // cout<<"i="<<i<<" val="<<dmx[i]<<endl;
        }
        // cout<<"out"<<endl;
        for(auto& u :dmn)cout<<u<<" ";
        cout<<endl;
        for(auto& u : dmx)cout<<u<<" ";
        // cout<<"done"<<endl;
    }
    return 0;
}


