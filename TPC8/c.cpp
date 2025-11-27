#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int p=1;
    vector<int>vec;
    vec.push_back(1);
    for(int i=2;i<=12;i++)
    {
        p*=10;
        p++;
        vec.push_back(p);
    }
    set<int>st;
    for(int i=0;i<vec.size();i++)
    for(int j=0;j<vec.size();j++)
    for(int k=0;k<vec.size();k++)
    st.insert(vec[i]+vec[j]+vec[k]);
    int n;
    cin>>n;
    for(int i=1;i<n;i++)st.erase(st.begin());
    cout<<*st.begin()<<endl;
    return 0;
}


