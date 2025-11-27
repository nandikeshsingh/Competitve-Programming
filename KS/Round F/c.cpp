#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define int long long
signed main()
{
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int d,n,x;
        cin>>d>>n>>x;
        vector<pair<int,pair<int,int>>>vec;
        for(int i=0;i<n;i++)
        {
            int q,l,v;
            cin>>q>>l>>v;
            vec.push_back({d-l,{v,q}});
        }
        sort(all(vec));
        multiset<pair<int,int>>ms;
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)ms.insert({vec[i].second.first,vec[i].second.second});
            else 
            {
                int s=vec[i].first;
                int e=vec[i+1].first;
                // if(e<s)continue;
                int tot=(e-s)*x;
                while(tot>0 && (int)ms.size()>0)
                {
                    pair<int,int>p=*prev(ms.end());
                    int v=p.first;
                    int q=p.second;
                    ms.erase(prev(ms.end()));
                    if(tot<=q)
                    {
                        ans+=tot*v;
                        if(q-tot>0)
                        ms.insert({v,q-tot});
                        tot=0;
                    }
                    else 
                    {
                        ans+=q*v;
                        tot-=q;
                    }
                }
                ms.insert({vec[i].second.first,vec[i].second.second}); 
            }
        }
        int s=0;
        int e=vec[0].first;
        // if(e>=s)
        {
            int tot=(e-s)*x;
            while(tot>0 && (int)ms.size()>0)
            {
                pair<int,int>p=*prev(ms.end());
                int v=p.first;
                int q=p.second;
                ms.erase(prev(ms.end()));
                if(tot<=q)
                {
                    ans+=tot*v;
                    if(q-tot>0)
                    ms.insert({v,q-tot});
                    tot=0;
                }
                else 
                {
                    ans+=q*v;
                    tot-=q;
                }
            }
        }
        cout<<"Case #"<<c<<": "<<ans<<endl;
    }
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// #define all(v) v.begin(),v.end()
// #define int long long
// signed main()
// {
//     int t;
//     cin>>t;
//     for(int c=1;c<=t;c++)
//     {
//         int d,n,x;
//         cin>>d>>n>>x;
//         // vector<pair<int,pair<int,int>>>vec;
//         vector<vector<pair<int,int>>>time(d+1,vector<pair<int,int>>(0));
//         for(int i=0;i<n;i++)
//         {
//             int q,l,v;
//             cin>>q>>l>>v;
//             // vec.push_back({d-l,{v,q}});
//             time[d-l].push_back({v,q});
//         }
//         // sort(all(vec));
//         // multiset<pair<int,int>>ms;
//         multiset<pair<int,int>>ms;
//         int ans=0;
//         for(int tt=d;tt>=0;tt--)
//         {
//             if((int)ms.size()>0)
//             {
//                 int xx=x;
//                 while(xx>0 && (int)ms.size()>0)
//                 {
//                     pair<int,int>p=*prev(ms.end());
//                     ms.erase(prev(ms.end()));
//                     if(p.second>=xx)
//                     {
//                         ans+=(p.first*xx);
//                         p.second-=xx;
//                         if(p.second)
//                         ms.insert({p.first,p.second});
//                         xx=0;
//                     }
//                     else 
//                     {
//                         ans+=(p.first*p.second);
//                         xx-=p.second;
//                     }
//                 }
//             }
//             if((int)time[tt].size()>0)
//             {
//                 for(auto& u : time[tt])
//                 ms.insert(u);
//             }
//         }
//         cout<<"Case #"<<c<<": "<<ans<<endl;
//     }
//     return 0;
// }