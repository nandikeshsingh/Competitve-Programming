#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
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
        vector<int>vec(n+1,0);
        int cur=1;
        vector<int>ans;
        for(int i=1;i<=n;i++)
        {   
            for(int j=i;j<=n;)
            {
                if(vec[j]==0)
                {
                    ans.push_back(j);
                    vec[j]=1;
                }
                j=2*j;
            }
        }
        cout<<2<<endl;
        for(auto& u : ans)
        cout<<u<<" ";
        cout<<endl;
      
    }
    return 0;
}

