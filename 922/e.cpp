#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int cnt;
char ask(int i)
{
    cnt++;
    char ch;
    cout<<"? "<<i<<endl;
    cin>>ch;
    return ch;
}
vector<int>get(vector<int>&a)
{
    if(sz(a)<=1)return a;
    random_device seeder;
    mt19937 engine(seeder());
    uniform_int_distribution<int> dist(0, sz(a)-1);
    int mid = dist(engine);
    while(1)
    {
        if(ask(a[mid])=='=')
        {
            break;
        }
    }
    vector<int>l,r;
    for(int i=0;i<sz(a);i++)
    {
        if(i==mid)continue;
        char ch=ask(a[i]);
        if(ch=='>')r.push_back(a[i]),ask(a[mid]);
        else if(ch=='<')l.push_back(a[i]),ask(a[mid]);
    }
    l=get(l);
    r=get(r);
    vector<int>ans;
    for(auto& u : l)ans.push_back(u);
    ans.push_back(a[mid]);
    for(auto& u : r)ans.push_back(u);
    return ans;
}
signed main()
{
    // speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int>vec;
        for(int i=0;i<n;i++)vec.push_back(i+1);
        vector<int>ans=get(vec);
        vector<pair<int,int>>has;
        for(int i=0;i<n;i++)
        {
            has.push_back({ans[i],i+1});
        }
        sort(all(has));
        cout<<"! ";
        for(int i=0;i<n;i++)cout<<has[i].second<<" ";
        cout<<endl;
    }
    return 0;
}


