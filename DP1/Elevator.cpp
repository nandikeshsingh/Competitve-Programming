#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<int>w;
void work(int x)
{
    int bst=0;
    int val=-1;
    int n=w.size();
    for(int i=0;i<(1<<n);i++)
    {
        int cur=0;
        for(int bit=n-1;bit>=0;bit--)
        {
            if(i&(1LL<<bit))cur+=w[n-1-bit];
        }
        if(cur<=x)
        {
            if(val<cur)
            {
                bst=i;
                val=cur;
            }
        }
    }
    vector<int>temp;
    for(int bit=n-1;bit>=0;bit--)
    {
        if((bst&(1LL<<bit))==0)temp.push_back(w[n-1-bit]);
    }
    w.clear();
    w=temp;
}
signed main()
{
    speed;
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++)
    {
        int ww;cin>>ww;
        w.push_back(ww);
    }
    int ans=0;
    while(w.size())
    {
        ans++;
        work(x);
        cout<<"Printing w"<<endl;
        for(auto& u : w)cout<<u<<" ";
        cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}


