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
        vector<int>a(n);
        map<int,int>mp;
        for(int i=0;i<n;i++)cin>>a[i],mp[a[i]]++;
        int ans=0;
        while(sz(mp))
        {
            int s=mp.begin()->first;
            s--;
            vector<int>del;
            for(auto& u : mp)
            {
                if(u.first==s+1)
                {
                    u.second--;
                    if(u.second==0)del.push_back(u.first);
                    s++;
                }
                else break;
            }
            ans++;
            for(auto& u : del)mp.erase(u);
        }
        cout<<ans<<endl;
    }
    return 0;
}


