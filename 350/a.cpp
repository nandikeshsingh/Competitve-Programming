#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    string s;cin>>s;
    string b=s.substr(3,3);
    if(b=="316" || b>"349" || b<"001")cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}


