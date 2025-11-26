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
        int n;cin>>n;
        char t;cin>>t;
        map<char,multiset<char>>mp;
        for(int i=0;i<2*n;i++)
        {
            string s;cin>>s;
            mp[s[1]].insert(s[0]);
        }
        int cnt=0;
        for(auto& u : mp)
        {
            if(u.first!=t)cnt+=(sz(u.second)%2);
        }
        if(sz(mp[t])<cnt)cout<<"IMPOSSIBLE"<<endl;
        else 
        {
            vector<pair<string,string>>ans;
            for(auto& u : mp)
            {
                if(u.first!=t)
                {
                    while(sz(u.second)>1)
                    {
                        string l;
                        l+=*u.second.begin();
                        l+=u.first;
                        string r;
                        r+=*prev(u.second.end());
                        r+=u.first;
                        ans.push_back({l,r});
                        u.second.erase(u.second.find(*u.second.begin()));
                        u.second.erase(u.second.find(*prev(u.second.end())));
                    }
                    if(sz(u.second)>0)
                    {
                        string l;
                        l+=*u.second.begin();
                        l+=u.first;
                        string r;
                        r+=*mp[t].begin();
                        r+=t;
                        ans.push_back({l,r});
                        mp[u.first].clear();
                        mp[t].erase(mp[t].find(*mp[t].begin()));
                    }
                }
            }
            while(sz(mp[t])>0)
            {
                string l;
                l+=*mp[t].begin();
                l+=t;
                string r;
                r+=*prev(mp[t].end());
                r+=t;
                ans.push_back({l,r});
                mp[t].erase(mp[t].find(*mp[t].begin()));
                mp[t].erase(mp[t].find(*prev(mp[t].end())));
            }
            for(auto& u : ans)cout<<u.first<<" "<<u.second<<endl;
        }
    }
    return 0;
}


