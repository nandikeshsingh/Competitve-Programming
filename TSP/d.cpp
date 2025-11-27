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
    vector<string>vec;
    vector<int>cntc(n,0),cntr(n,0);
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        vec.push_back(s);
        for(int j=0;j<n;j++)cntc[j]+=(vec[i][j]=='o'),cntr[i]+=(vec[i][j]=='o');
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(vec[i][j]=='o')
            {
                ans+=(cntr[i]-1)*(cntc[j]-1);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}


