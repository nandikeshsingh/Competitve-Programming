#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
bool ok(int n)
{
    vector<int>vec;
    while(n)
    {
        vec.push_back(n%10);
        n/=10;
    }
    bool f=1;
    int i=0;int j=sz(vec)-1;
    while(i<j)
    {
        if(vec[i]==vec[j])i++,j--;
        else {
            f=0;
            break;
        }
    }
    return f;
}
signed main()
{
    speed;
    int n;
    cin>>n;
    int best=1;
    for(int i=1;i<=1e6;i++)
    {
        if(i*i*i>n)break;
        else 
        {
            if(ok(i*i*i))
            {
                best=i*i*i;
            }
        }
    }
    cout<<best<<endl;
    return 0;
}


