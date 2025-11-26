#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>cnt(5000001);
    vector<int>mul(5000001);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int g=1;g<=5000000;g++)
    {
        for(int j=g;j<=5000000;j+=g)
        {
            mul[g]+=cnt[j];
        }
    }
    int ans=-1e18;
    vector<int>tot(5000001);
    for(int g=5000000;g>=1;g--)
    {
        tot[g]=mul[g]*g;
        for(int j=g;j<=5000000;j+=g)
        {
            tot[g]=max(tot[g],tot[j]+(mul[g]-mul[j])*g);
        }
        ans=max(ans,tot[g]);
    }
    cout<<ans<<endl;
    return 0;
}


Seatbelt Indicator(DIN-8231),Auto main beam indicator(DIN-9490), Brake Fluid level message(DIN-10464), Brake ABS Message(DIN-10541), Stability Control Indication Messages(DIN-14570), Dipped Beam Fault Warning Message(DIN-12051),Language(DIN-13240),Air Suspension Warning messages(DIN-15313),Brake System Fault Warning message(DIN-17278),HV Charge message(DIN-17292), Start Auth Warning Message(DIN-17423),Added Service discovery to indExtLightsFlashing(DIN-18807), TJACIA messages(DIN-22599), Brakes Overheat Messages(DIN-23185), Dyno Mode Test message(DIN-23205), Driver Unresponsive messages(DIN-49194), Charging fault messages(DIN-15900) and multiple mtid update for messages.