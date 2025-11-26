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
        int n;
        cin>>n;
        vector<int>vec(n);
        multiset<int>ms;
        for(int i=0;i<n;i++)cin>>vec[i],ms.insert(vec[i]);
        for(int i=0;i<n;i++)
        {
            ms.erase(ms.find(vec[i]));
            cout<<vec[i]-*prev(ms.end())<<" ";
            ms.insert(vec[i]);
        }
        cout<<endl;
    }
    return 0;
}


