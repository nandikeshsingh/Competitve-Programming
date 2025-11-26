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
        int n,q;
        cin>>n>>q;
        vector<int>vec(n);
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            s+='0';
        }
        int cur=0;
        for(int i=n-1;i>=0;i--)
        {
            if(vec[i]<=cur)s[i]='1';
            else 
            {
                if(vec[i]>cur && cur<q)
                {
                    cur++;
                    s[i]='1';
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
