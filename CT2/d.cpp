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
        int n,m;
        cin>>n>>m;
        int idx=-1;
        int mx=-1e18;
        int mn=1e18;
        for(int i=0;i<n;i++)
        {
            int cur=0;
            for(int j=0;j<m;j++)
            {
                int val;
                cin>>val;
                cur+=(j+1)*val;
            }
            if(cur>mx)
            {
                mx=cur;
                idx=i+1;
            }
            if(cur<mn)
            {
                mn=cur;
            }
        }
        cout<<idx<<" "<<mx-mn<<endl;
    }
    return 0;
}

