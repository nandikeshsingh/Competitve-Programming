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
        vector<int>ans;
        int f=1,l=n;
        while(f<=l)
        {
            if(f!=l)
            {
                ans.push_back(f++);
                ans.push_back(l--);
            }
            else ans.push_back(f++);
        }
        for(auto&u  : ans)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}


