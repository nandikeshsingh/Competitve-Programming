#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
signed main()
{
    speed;
   int n,q;
   cin>>n>>q;
   vector<int>vec(n);
   for(int i=0;i<n;i++)cin>>vec[i];
   sort(vec.begin(),vec.end());
   reverse(vec.begin(),vec.end());
   for(int i=1;i<n;i++)vec[i]+=vec[i-1];
   reverse(vec.begin(),vec.end());
   vec.push_back(0);
   reverse(vec.begin(),vec.end());
 
   while(q--)
   {
       int x,y;
       cin>>x>>y;
       cout<<vec[x]-vec[x-y]<<endl;
   }
    return 0;
}

