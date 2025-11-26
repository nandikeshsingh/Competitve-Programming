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
        int md=(n+1)/2;
        int mx=n-((n+1)/2);
        vector<int>ans;
        if(n%2==0)
        {
            for(int i=md;i>=1;i--)
            {
                ans.push_back(i);
                ans.push_back(i+mx);
            }
        }
        else 
        {
            for(int i=md;i>=2;i--)
            {
                ans.push_back(i);
                ans.push_back(i+mx);
            } 
            ans.push_back(1);
        }
        for(auto& u : ans)cout<<u<<" ";
        cout<<endl; 
    }
    return 0;
}


