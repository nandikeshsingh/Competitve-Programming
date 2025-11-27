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
    vector<int>a;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        a.push_back(x);
        while(sz(a)>1)
        {
            int l=a.back();
            a.pop_back();
            int ll=a.back();
            a.pop_back();
            if(l==ll)
            {
                a.push_back(l+1);
            }
            else 
            {
                a.push_back(ll);
                a.push_back(l);
                break;
            }
        }
    }
    cout<<sz(a)<<endl;
    return 0;
}


