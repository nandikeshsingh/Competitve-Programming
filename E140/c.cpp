#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int mod=998244353;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1][n+1];
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            cin>>arr[i][j];
        }
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            if(arr[i][i]==2)ok=0;
        }
        vector<set<int>>vec(n+1);
        for(int j=1;j<=n;j++)
        {
            for(int i=1;i<=j;i++)
            {
                vec[j].insert(arr[i][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(vec[i].count(1)==1 && vec[i].count(2)==1)ok=0;
        }
        if(!ok)cout<<0<<endl;
        else 
        {
            
        }
    }
    return 0;
}


