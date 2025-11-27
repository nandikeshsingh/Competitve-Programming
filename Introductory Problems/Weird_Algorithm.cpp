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
    vector<int>ans;
    while(n!=1)
    {
        ans.push_back(n);
        if(n%2)n=3*n+1;
        else n/=2; 
    }
    ans.push_back(n);
    for(auto& u : ans)cout<<u<<" ";
    cout<<endl;
    return 0;
}


