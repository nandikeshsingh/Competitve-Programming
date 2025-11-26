#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int mod=1e9+7;
signed main()
{
    speed;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>pos;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='F')pos.push_back(i);
        }
        int cnt=0;
        for(int i=1;i<(int)pos.size();i++)
        {
            if(s[pos[i]]!=s[pos[i-1]])
            {
                cnt+=((n-pos[i])*(pos[i-1]+1))%mod;
                cnt%=mod;
            }
        }
        cout<<"Case #"<<c<<": "<<cnt<<endl;
    }
    return 0;
}


