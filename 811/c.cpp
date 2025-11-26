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
        int s;
        cin>>s;
        int ans=0;
        int cur=9;
        while(s>0)
        {
            if(cur<=s)
            {
                ans*=10;
                ans+=cur;
                s-=cur;
                cur--;
            }
            else cur--;
        }
        int p=0;
        while(ans>0)
        {
            p*=10;
            p+=(ans%10);
            ans/=10;
        }
        cout<<p<<endl;
    }
    return 0;
}