#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    // int t;
    // cin>>t;
    // while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int z=0,o=0;
        for(auto& u : s)
        {
            if(u=='1')o++;
            else z++;
        }
        vector<int>ans;
        for(int i=1;i<=(1<<n);i++)
        {
            if(s[n-1]=='1')
            {   
                if((1<<o)<=i && (1<<z)<=(1<<n)-i)
                ans.push_back(i);
            }
            else 
            {
                if((1<<z)<=(i) && (1<<0)<=(1<<n)-i)
                ans.push_back(i);
            }
        }   
        for(auto& u : ans)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}


