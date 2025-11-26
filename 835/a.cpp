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
        vector<int>vec(3);
        cin>>vec[0]>>vec[1]>>vec[2];
        sort(all(vec));
        cout<<vec[1]<<endl;
    }
    return 0;
}

