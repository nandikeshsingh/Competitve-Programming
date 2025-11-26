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
        vector<int>cnt(n);
        for(int i=0;i<n;i++)cin>>cnt[i];
        int pos=0;
        for(int i=0;i<n;i++)
        {
            if(cnt[pos]<cnt[i])
            pos=i;
        }
        cout<<pos+1<<endl;
        
    }
    return 0;
}


