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
        for(int i=0;i<n;i++)cin>>vec[i];
        bool ok=1;
        for(int i=1;i<n-1;i++)
        {
            vec[i]-=(2*vec[i-1]);
            vec[i+1]-=vec[i-1];
            vec[i-1]=0;
            if(vec[i]<0 || vec[i+1]<0)break;
        }
        for(int i=0;i<n;i++)
        {
            if(vec[i]!=0)ok=0;
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
    return 0;
}


