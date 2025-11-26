#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,x;
    cin>>n>>x;
    vector<int>cnt(x+1);
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        cnt[a]++;
    }
    bool ok=1;
    for(int i=1;i<x;i++)
    {
        {
            int tot=cnt[i]/(i+1);
            cnt[i]-=tot*(i+1);
            cnt[i+1]+=tot;
            if(cnt[i]>0)
            {
                ok=0;
                break;
            }
        }
    }
    cout<<(ok?"Yes":"No")<<endl;
    return 0;
}


