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
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        bool ok=1;
        for(int i=1;i<n;i++)
        {
            if(vec[i]%vec[0]!=0)
            {
                ok=0;
                break;
            }
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

