#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int k,g,m;
    cin>>k>>g>>m;
    int cur_g=0,cur_m=0;
    int j=0;
    while(k)
    {   

        if(cur_g==g)
        {
            cur_g=0;
            k--;
        }
        else if(cur_m==0)
        {
            cur_m=m;
            k--;
        }
        else 
        {
            int have=cur_m;
            int need=g-cur_g;
            if(have>=need)
            {
                cur_g=g;
                cur_m-=need;
            }
            else 
            {
                cur_g+=have;
                cur_m-=have;
            }  
            k--;          
        }
    }
    cout<<cur_g<<" "<<cur_m<<endl;
    return 0;
}


