#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
multimap<int,int>mmp;
unordered_map<int,int>ump;
void print()
{
    cout<<"Printing map"<<endl;
    for(auto& u : mp)cout<<u.first<<" "<<u.second<<endl;
    cout<<"Printing multimap"<<endl;
    for(auto& u : mmp)cout<<u.first<<" "<<u.second<<endl;
    cout<<"Printing unordered_map"<<endl;
    for(auto& u : ump)cout<<u.first<<" "<<u.second<<endl;
}
int main()
{

    for(int i=0;i<5;i++)
    {
        mp[i]=i+5;
        mmp[i]=i+5
        ump[i]=i+5;
    }
    print();
}