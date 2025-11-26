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
        int arr[n][n-1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            cin>>arr[i][j];
        }
        vector<int>ans;
        vector<int>cnt(n+1);
        for(int i=0;i<n;i++)
        {
            cnt[arr[i][0]]++;
        }
        int best=0,mx=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt[i]>mx)
            {
                best=i;
                mx=cnt[i];
            }
        }
        ans.push_back(best);
        for(int i=1;i<=n;i++)
        {
            if(i==best)continue;
            else if(cnt[i]>0)ans.push_back(i);
        }
        for(int j=1;j<n-1;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(arr[i][j]!=ans.back())
                {
                    ans.push_back(arr[i][j]);
                    break;
                }
            }
        }
        for(auto& u : ans)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}


