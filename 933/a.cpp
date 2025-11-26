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
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>b(n),c(m);
        for(int i=0;i<n;i++)cin>>b[i];   
        for(int i=0;i<m;i++)cin>>c[i];
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(b[i]+c[j]<=k)cnt++;
            }
        }   
        cout<<cnt<<endl;
    }
    return 0;
}


