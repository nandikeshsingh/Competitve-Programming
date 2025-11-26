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
        int tot=0;
        for(int i=0;i<n-1;i++)tot+=vec[i];
        int cur=0;
        while(vec[cur]==0)cur++;
        int cnt=0;
        for(int i=cur;i<n-1;i++)
        {
            if(vec[i]==0)cnt++;
        }
        cout<<cnt+tot<<endl;
    }
    return 0;
}

