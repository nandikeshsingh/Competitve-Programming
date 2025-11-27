#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    vector<string>vec;
    vec.push_back("nidhin");
    vec.push_back("nandikesh");
    vec.push_back("ananth");
    vec.push_back("alex");
    vec.push_back("tibor");
    vec.push_back("lakshmi");
    vec.push_back("prien");
    vec.push_back("guy");
    vec.push_back("abdullah");
    sort(all(vec));
    int len=vec.size();
    int i=0;
    while(i<len)
    {
        cout<<vec[(i++)]<<endl;
        
    }
    return 0;
}