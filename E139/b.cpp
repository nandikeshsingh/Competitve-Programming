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
        string s;
        cin>>s;
        map<string,vector<pair<int,int>>>mp;
        for(int i=1;i<n;i++)
        {
            string str=s.substr(i-1,2);
            mp[str].push_back({i-1,i});
        }
        bool ok=0;
        for(auto& u : mp)
        {
            pair<int,int>p1=u.second[0];
            pair<int,int>p2=u.second[sz(u.second)-1];
            if(p1.second<p2.first)
            {
                ok=1;
                break;
            }
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}


