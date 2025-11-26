#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int power(int x, unsigned int y)
{
    int temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}
int get(int n)
{
    // cout<<"n="<<n<<endl;
   if (n < 4)
      return 0;
   int d = log10(n);
    vector<int>a(d+1);
   a[0] = 0, a[1] = 1;
   for (int i=2; i<=d; i++)
      a[i] = a[i-1]*9 + ceil(power(10,i-1));
   int p = ceil(power(10, d));
   int msd = n/p;
   if (msd == 4)
      return (msd)*a[d] + (n%p) + 1;
   if (msd > 4)
      return (msd-1)*a[d] + p + get(n%p);
   return (msd)*a[d] + get(n%p);
}
signed main()
{
    // cout<<get(328)<<endl;
    speed;
    // int cur=1e12;
    // while(1)
    // {   
    //     if(cur-get(cur)>=1e12)
    //     {
    //         cout<<"found "<<cur<<endl;
    //         break;
    //     }
    //     else cur*=10;
    //     cout<<"cur="<<cur<<endl;
    // }
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        int lo=1,hi=1e13;
        int cnt=0;
        while(lo<hi)
        {
            int mid=(lo+hi)>>1;
            // cout<<"lo="<<lo<<" hi="<<hi<<" mid="<<mid<<endl;
            int tot=get(mid);
            // cout<<"tot="<<tot<<endl;
            if(mid-tot>=k)hi=mid;
            else lo=mid+1;
            cnt++;
            assert(cnt<70);
        }
        cout<<lo<<endl;
    }
    return 0;
}


