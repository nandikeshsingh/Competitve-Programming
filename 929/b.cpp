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
        vector<int>a(n);
        vector<int>r(3,0);
        int tot=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            tot+=a[i];
            r[a[i]%3]++;
        }
        if(tot%3==0)cout<<0<<endl;
        else if(tot%3==1)
        {
            if(r[1]>0)cout<<1<<endl;
            else cout<<2<<endl;
        }
        else 
        {
            cout<<1<<endl;
        }
    }
    return 0;
}


