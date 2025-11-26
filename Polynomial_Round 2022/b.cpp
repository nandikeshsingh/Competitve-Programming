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
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>a(m);
        for(int i=0;i<m;i++)cin>>a[i];
        if(k>m)cout<<"NO"<<endl;
        else 
        {
            vector<int>vec;
            int d=n/k;
            int rim=n%k;
            for(int i=0;i<m;i++)
            {
                if(a[i]>d)vec.push_back(a[i]);
            }
            sort(all(vec));
            if(sz(vec)>0 && (vec.back()>d+1 || sz(vec)>rim))cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}


