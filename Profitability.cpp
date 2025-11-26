#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,n)   for(int i=0;i<(n);++i)
#define rep(i,a,b)   for(int i=(a);i<=(b);++i)
#define per(i,b,a)   for(int i=(b);i>=(a);--i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define pb push_back
#define F first
#define S second
using namespace std;
using ii = pair<int,int>;
using vii = vector<ii>;
using vi = vector<int>;
signed main()
{
    speed;
    double total=0.0;
    while(1)
    {
        double a=0.99967;
        double b=1.00011;
        double c=47.2;
        double p1=0,p2=0,x=0;
        cout<<"Enter buy price(p1)"<<endl;
        cin>>p1;
        cout<<"Enter sell price(p2)"<<endl;
        cin>>p2;
        cout<<"Enter quantity"<<endl;
        cin>>x;
        double ans=x*((a*p2)-(b*p1));
        ans-=c;
        cout<<setprecision(10)<<"Net profit = "<<ans<<endl;
        total+=ans;
        cout<<setprecision(10)<<"total so far : "<<total<<endl;
    }
    return 0;
}


