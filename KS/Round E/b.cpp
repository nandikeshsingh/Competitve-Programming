#include<bits/stdc++.h>
using namespace std;
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
signed main()
{
    speed;
    int tt;
    cin>>tt;
    for(int t=1;t<=tt;t++)
    {
        int n;
        cin>>n;
        vector<int>vec(n),ans(n);
        vector<pair<int,int>>has;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            has.push_back({vec[i],i});
        }
        sort(has.begin(),has.end());
        reverse(has.begin(),has.end());
        // cout<<"Printing has"<<endl;
        // for(auto& u : has)cout<<u.first<<" "<<u.second<<" ";
        // cout<<endl;
        int st=0;int ed=1;
        ans[has[0].second]=has[1].second;
        while(ed<n)
        {
            while(2*has[ed].first>=has[st].first && ed<n)
            {
                ans[has[ed].second]=has[st].second;
                ed++;
            }
            while(2*has[ed].first<has[st].first && ed<n)
            {
                st++;
            }
            if(st==ed)ans[has[st].second]=-1,ed++;
        }
        // cout<<"Printing ans"<<endl;
        // for(auto& u : ans)cout<<u<<" ";
        // cout<<endl;
        cout<<"Case #"<<t<<": ";
        for(auto& u : ans)
        {
            if(u>=0)
            cout<<vec[u]<<" ";
            else cout<<-1<<" ";
        }
        cout<<endl;
    }
}