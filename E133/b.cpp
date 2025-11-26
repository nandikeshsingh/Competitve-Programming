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
        for(int i=0;i<n;i++)vec[i]=i+1;
        cout<<n<<endl;
        for(auto& u : vec)cout<<u<<" ";
        cout<<endl;
        for(int i=n-1;i>=1;i--)
        {
            swap(vec[i],vec[i-1]);
            for(auto& u : vec)cout<<u<<" ";
            cout<<endl;
        }
    }
    return 0;
}