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
        vector<int>vec(n);
        int cur=0;
        int tot=0;
        for(int i=0;i<n-3;i++)
        {
            vec[i]=cur++;
            tot^=vec[i];
        }
        vec[n-3]=(1LL<<30);
        vec[n-2]=(1LL<<29);
        vec[n-1]=(tot^vec[n-3]^vec[n-2]);
        for(auto& u : vec)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}           
