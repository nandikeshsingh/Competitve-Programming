#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>p1)
{

}
signed main()
{
    set<pair<int,int>>st;
    st.insert({1,2});
    st.insert({3,2});
    st.insert({5,4});
    st.insert({9,8});
    st.insert({0,4});
    st.insert({5,7});
    st.insert({9,6});
    st.insert({3,3});
    auto it = std::find_if(st.begin(), st.end(), [](const pair<int,int>& p ){ return p.first == 3; });
    if(  it !=st.end())
    {
        cout<<"found"<<endl;
        cout<<it->first<<" "<<it->second<<endl;
    }
    else 
    {
        cout<<"Not found"<<endl;
    }

}