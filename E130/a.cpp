#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int sum=0;
        vector<int>vec(n);
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            sum+=vec[i];
        }
        if(m>=sum)cout<<0<<endl;
        else cout<<sum-m<<endl;
    }
    return 0;
}

