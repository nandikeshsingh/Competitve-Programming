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
        vector<double>q(n),w(n);
        for(int i=0;i<n;i++)cin>>q[i];
        for(int i=0;i<n;i++)cin>>w[i];
        vector<double>t;
        for(int i=0;i<n;i++)
        {
            t.push_back(q[i]-w[i]);
            t.push_back(q[i]+w[i]);
        }
        assert(sz(t)==2*n);
        sort(all(t));
        double ans=(double)(t[0]+t[n+n-1])/(double)2.0;
        cout<<fixed<<setprecision(8)<<ans<<endl;
        // vector<pair<double,double>>x;
        // for(int i=0;i<n;i++)
        // {
        //     x.push_back({q[i],w[i]});
        // }
        // sort(all(x));
        // double pos=(x[0].first+x[n-1].first)/double(2);
        // // cout<<"pos="<<pos<<endl;
        // vector<double>t;
        // for(int i=0;i<n;i++)
        // {
        //     if(x[i].first==pos)
        //     {
        //         t.push_back(x[i].first-x[i].second);
        //         t.push_back(x[i].first+x[i].second);
        //     }
        //     else if(x[i].first<pos)
        //     {
        //         t.push_back(x[i].first-x[i].second);
        //         // x[0].first-=x[0].second;
        //     }
        //     else t.push_back(x[i].first+x[i].second);
        // }
        // sort(all(t));
        // cout<<"t"<<endl;
        // for(auto& u : t)cout<<u<<" ";
        // cout<<endl;
       
        // double ans=(t[0]+t[n-1])/double(2);
        // // cout<<"ans="<<ans<<endl;
        // cout<<ans<<endl;
    }
    return 0;
}

