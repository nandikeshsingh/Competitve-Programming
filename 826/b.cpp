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
        if(n==3)
        {
            cout<<-1<<endl;
            continue;
        }
        vector<int>a(n);
        for(int i=0;i<n;i++)a[i]=i+1;
        reverse(all(a));
        if(n%2)
        {
            int m=n/2;
            int l=m,r=n-1;
            while(l<r)
            {
                swap(a[l],a[r]);
                r--,l++;
            }
        }
        for(auto& u : a)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}


