#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>a(n),last(n);
        vector<int>cnt(n+m+1);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int j=1;j<=m;j++)
        {
            int p,v;
            cin>>p>>v;
            p--;
            cnt[a[p]]+=(j-last[p]);
            last[p]=j;
            a[p]=v;
        }
        for(int i=0;i<n;i++)
        cnt[a[i]]+=(m+1-last[i]);
        int ans=(m*(m+1))*n;
        for(int i=1;i<=n+m;i++)
        ans-=(cnt[i]*(cnt[i]-1))/2;
        cout<<ans<<endl;
    }
    return 0;
}

Successfully completed all the training courses(100+ hours) as recommended by my colleagues and some on my own. All the certificates are attached in the attachment section. 

Have successfully adapted to the agile culture by participating in the agile ceremonies every week. Also facilitated morning stand-ups during my turn for our squad.

I have shown integrity by completing the recommended training courses outside of my work as there was no one tracking my progress on this anywhere which has immensely helped me in my growth.



1. Added 12+ Functional TRM requirements, GUI TRM requirements, Functional test case in XRAY and GUI test case in XRAY.
2. Worked on authoring / revising 5+ specifications files . Specification drafts sent to suppliers for review and then released.
3. Worked on supporting description of VAL interface, .proto file release, code reviews, adhoc bug fixes etc.

The entire work history in details can be found here : https://jira.devops.jlr-apps.com/browse/DIN-3074?jql=assignee%20in%20(currentUser())
