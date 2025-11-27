#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<bool>vec(n+1);
    for(int i=1;i<n;i++)
    {
        int x;cin>>x;
        vec[x]=1;
    }
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        if(vec[i]==0)
        {
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;

    return 0;
}

