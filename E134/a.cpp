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
        map<char,int>mp;
        string a,b;
        cin>>a>>b;
        mp[a[0]]++;
        mp[a[1]]++;
        mp[b[0]]++;
        mp[b[1]]++;
        cout<<(int)mp.size()-1<<endl;

    }   
    return 0;
}


