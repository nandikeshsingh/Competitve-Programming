#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>vec(n+1);
    for(int i=1;i<=n;i++)cin>>vec[i];
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int now=i;
        bool ok=1;
        int last=now%10;
        while(now>0)
        {
            if((now%10)!=last)
            {
                ok=0;
                break;
            }
            else now/=10;
        }
        if(!ok)continue;
        else {
            int cur=i%10;
            int dig=cur;
            while(cur<=vec[i])
            {
                cnt++;
                cur*=10;
                cur+=dig;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}


