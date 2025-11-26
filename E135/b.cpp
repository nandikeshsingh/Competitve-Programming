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
        if(n%2==0)
        {
            for(int i=n-2;i>=1;i--)ans.push_back(i);
            ans.push_back(n-1);
            ans.push_back(n);
        }
        else 
        {
            ans.push_back(1);
            ans.push_back(2);
            ans.push_back(3);
            for(int i=4;i<=n-2;i++)
            {
                if(i%2==0)ans.push_back(i+1);
                else ans.push_back(i-1);
            }
            ans.push_back(n-1);
            ans.push_back(n);
        }
        for(auto& u: ans)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}


