#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,a,b;
    cin>>n>>a>>b;
    if(a>b+b)a=b+b;
    string s;cin>>s;
    int l=0,r=0;
    vector<int>pos;
    for(int i=0;i<2*n;i++)
    {
        char u=s[i];
        if(u=='(')l++,pos.push_back(i);
        else r++;
    }
    // cout<<"done"<<endl;
    int el=0,er=0;
    int ans=0;
    if(l>n)el=l-n,ans=el*b;
    else if(r>n) er=r-n,ans=er*b;
    int cur=0;
    for(auto& u : s)
    {
        if(u=='(')cur++;
        else cur--;
        if(cur<0)
        {
            assert(u==')');
            if(er>0)
            {
                er--;
                cur+=2;
                u='(';
            }
            else 
            {
                u='(';
                cur+=2;
                assert(sz(pos)>0);
                s[pos.back()]=')';
                pos.pop_back();
                ans+=a;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}


