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
        int n,k;
        cin>>n>>k;
        vector<int>vec(n);
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
        }
        int cnt=0;
        for(int i=1;i<n-1;i++)
        {
            if(vec[i-1]+vec[i+1]<vec[i])cnt++;
        }
        if(k>1)cout<<cnt<<endl;
        else 
        {
            n-=1;
            cout<<(n/2)<<endl;
        }
    }
    return 0;
}

