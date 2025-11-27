// #include<bits/stdc++.h>
// using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define int long long
// #define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
// #define all(v) v.begin(),v.end()
// #define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
// signed main()
// {
//     speed;
//     int n,k;
//     cin>>n>>k;
//     vector<int>x(n);
//     ordered_set st;
//     for(int i=0;i<n;i++)
//     {
//         cin>>x[i];
//         if(i<k)
//         st.insert({x[i],i});
//     }
//     for(int i=k-1;i<n;i++)
//     {
//         st.insert({x[i],i});
//         if(i>=k)
//         st.erase(st.find({x[i-k],i-k}));
//         cout<<st.find_by_order(((k-1)/2))->first<<" ";
//     }
//     // cout<<st.find_by_order(((k-1)/2))->first<<" ";
//     cout<<endl;
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
signed main()
{
    speed;
    int n,k;
    cin>>n>>k;
    vector<int>x(n);
    multiset<int>l,u;
    int suml=0,sumu=0;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        if(i>=k)
        {
            int val=x[i-k];
            if(val<=*prev(l.end()))
            {
                suml-=val;
                l.erase(l.find(val));
            }
            else 
            {
                sumu-=val;
                u.erase(u.find(val));
            }
        }
        cin>>x[i];
        l.insert(x[i]);
        suml+=x[i];
        if(l.size()>u.size()+1 || (u.size()>0 && *prev(l.end())>*u.begin()))
        {
            int mx=*prev(l.end());
            suml-=mx;
            l.erase(prev(l.end()));
            u.insert(mx);
            sumu+=mx;
        }
        if(u.size()>l.size())
        {
            int mn=*u.begin();
            sumu-=mn;
            suml+=mn;
            u.erase(u.begin());
            l.insert(mn);
        }
        if(i>=k-1)
        {
            int m=*prev(l.end());
            // int cost=m*l.size()-suml+sumu-m*u.size();
            ans.push_back(m);
        }
    }
    for(auto& u : ans)cout<<u<<" ";
    cout<<endl;
    return 0;
}
