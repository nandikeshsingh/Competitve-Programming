#include<bits/stdc++.h>
#define int long long
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
        vector<vector<int>>idx(2,vector<int>(0));
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            idx[a[i]%2].push_back(i);
        }
        vector<pair<int,int>>ans;
        if(a[0]%2)
        {
            for(int i=(int)idx[1].size()-2;i>=0;i--)
            {
                ans.push_back({idx[1][i],idx[1][i+1]});
            }
            for(int i=0;i<(int)idx[0].size();i++)
            {
                if(i==0)ans.push_back({0,idx[0][i]});
                else ans.push_back({idx[0][i-1],idx[0][i]});
            }
        }
        else 
        {
             for(int i=(int)idx[0].size()-2;i>=0;i--)
            {
                ans.push_back({idx[0][i],idx[0][i+1]});
            }
            for(int i=0;i<(int)idx[1].size();i++)
            {
                if(i==0)ans.push_back({0,idx[1][i]});
                else ans.push_back({idx[1][i-1],idx[1][i]});
            }           
        }
        assert((int)ans.size()<=n);
        cout<<(int)ans.size()<<endl;
        for(auto& u : ans)cout<<u.first+1<<" "<<u.second+1<<endl;
    }
    return 0;
}


