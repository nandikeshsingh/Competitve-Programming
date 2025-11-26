#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
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
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int k;cin>>k;
        vector<int>b(k);
        for(int i=0;i<k;i++)cin>>b[i];
        vector<pair<int,int>>mp1,mp2;
        for(int i=0;i<n;i++)
        {
            int cur=1;
            while(a[i]%m==0)
            {
                cur*=m;
                a[i]/=m;
            }
            if(mp1.size()>0 && mp1.back().first==a[i])
            {
                mp1.back().second+=cur;
            }
            else mp1.push_back({a[i],cur});
        }
        for(int i=0;i<k;i++)
        {
            int cur=1;
            while(b[i]%m==0)
            {
                cur*=m;
                b[i]/=m;
            }
            if(mp2.size()>0 && mp2.back().first==b[i])
            {
                mp2.back().second+=cur;
            }
            else mp2.push_back({b[i],cur});
        }
        if(mp1==mp2)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

        // bool ok=1;
        // for(auto& u : mp1)
        // {
        //     if(mp2.find(u.first)==mp2.end())
        //     {
        //         ok=0;
        //         break;
        //     }
        //     else 
        //     {
        //         if(mp2[u.first]!=u.second)
        //         {
        //             ok=0;
        //             break;
        //         }
        //     }
        // }
        // if(ok)cout<<"Yes"<<endl;
        // else cout<<"No"<<endl;
      
    }
    return 0;
}

