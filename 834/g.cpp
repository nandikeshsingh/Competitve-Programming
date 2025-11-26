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
        vector<int>b(n/2);
        set<int>has,st;
        for(int i=1;i<=n;i++)has.insert(i);
        for(int i=0;i<n/2;i++)cin>>b[i],st.insert(b[i]);
        if(sz(st)!=n/2)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=0;i<n/2;i++)has.erase(has.find(b[i]));
        vector<int>bc;
        vector<pair<int,int>>vec;
        for(int i=0;i<n/2;i++)
        {
            vec.push_back({b[i],i});
        }
        sort(all(vec));
        cout<<"Printing vec"<<endl;
        for(auto& u : vec)cout<<u.first<<" "<<u.second<<endl;
        bool ok=1;
        for(int i=0;i<n/2;i++)
        {
            auto itr=has.upper_bound(vec[i].first);
            if(itr==has.begin())
            {
                ok=0;
                break;
            }
            else 
            {
                itr=prev(itr);
                bc.push_back(*itr);
                has.erase(itr);
            }
        }
        if(!ok)cout<<-1<<endl;
        else 
        {
            cout<<"Printing bc"<<endl;
            for(auto& u : bc)cout<<u<<" ";
            cout<<endl;
            vector<pair<int,pair<int,int>>>ans;
            for(int i=0;i<n/2;i++)
            {
                ans.push_back({vec[i].second,{bc[i],vec[i].first}});
            }
            sort(all(ans));
            for(int i=0;i<n/2;i++)cout<<min(ans[i].second.first,ans[i].second.second)<<" "<<max(ans[i].second.first,ans[i].second.second)<<" ";
            cout<<endl;
        }
    }
    return 0;
}


