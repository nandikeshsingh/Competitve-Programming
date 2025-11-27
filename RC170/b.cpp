#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n);
    vector<vector<int>>pos(11);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        pos[a[i]].push_back(i);
    }
    vector<int>bst(n,n);
    for(int i=0;i<n-1;i++)
    {
        for(int l=1;l<=10;l++)
        {
            int mid=(a[i]+l);
            if(mid%2)continue;
            mid/=2;
            auto itr=lower_bound(all(pos[mid]),i+1);
            if(itr==pos[mid].end())continue;
            auto it=lower_bound(all(pos[l]),*itr+1);
            if(it==pos[l].end())continue;
            bst[i]=min(bst[i],*it);
        }
    }
    int ans=0;
    for(int i=n-2;i>=0;i--)bst[i]=min(bst[i],bst[i+1]);
    for(int i=0;i<n;i++)ans+=(n-bst[i]);
    cout<<ans<<endl;
    return 0;
}