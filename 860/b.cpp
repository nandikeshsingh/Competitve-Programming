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
        int m;
        cin>>m;
        vector<vector<int>>a;
        multiset<int>ms;
        for(int i=0;i<m;i++)
        {
            int n;cin>>n;
            vector<int>temp;
            for(int i=0;i<n;i++)
            {
                int x;cin>>x;
                ms.insert(x);
                temp.push_back(x);
            }
            a.push_back(temp);
        }
        vector<int>ans;
        bool f=1;
        for(int i=0;i<m;i++)
        {
            for(auto& u : a[i])
            {
                ms.erase(ms.find(u));
            }
            bool ok=0;
            for(auto& u : a[i])
            {
                if(ms.count(u)==0)
                {
                    ans.push_back(u);
                    ok=1;
                    break;
                }
            }
            if(!ok)
            {
                f=0;
                break;
            }
        }
        if(!f)cout<<-1<<endl;
        else 
        {
            for(auto& u : ans)cout<<u<<" ";
            cout<<endl;
        }
    }
    return 0;
}


