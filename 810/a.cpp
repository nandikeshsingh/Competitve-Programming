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
        vector<int>ans;
        for(int i=1;i<=n;i++)
        {
            if(i%2)
            {
                ans.push_back(i+1);
            }
            else ans.push_back(i-1);
        }
        if(n%2)
        {
            ans[ans.size()-1]--;
            int len=ans.size();
            if(n>2)
            {
                swap(ans[len-1],ans[len-2]);
            }
        }
        for(auto& u : ans)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}