#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
 
    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
 
    return false;
}
 
// Function for find difference of larger numbers
string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++) {
        // Do school mathematics, compute difference of
        // current digits
 
        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);
 
        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
 
        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}
string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
 
        // Calculate carry for next step
        carry = sum/10;
    }
 
    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string num;
        cin>>num;
        if(num[0]!='9')
        {
            string ans;
            for(int i=0;i<n;i++)
            {
                int cur=num[i]-48;
                cur=9-cur;
                ans+=(cur+48);
            }
            reverse(ans.begin(),ans.end());
            while(ans.back()=='0')ans.pop_back();
            reverse(ans.begin(),ans.end());
            cout<<ans<<endl;
        }
        else 
        {
            string cur;
            for(int i=0;i<=n;i++)
            {
                if(i==0)cur+='1';
                else cur+='0';
            }
            string now=findDiff(cur,num);
            string has;
            for(int i=0;i<n;i++)
            has+='1';
            string ans=findSum(has,now);
                        reverse(ans.begin(),ans.end());
            while(ans.back()=='0')ans.pop_back();
            reverse(ans.begin(),ans.end());
            cout<<ans<<endl;
        }







        // int cur=0;
        // for(int i=0;i<=n;i++)
        // {
        //     cur*=10;
        //     cur+=1;
        // }
        // int div=1;
        // for(int i=1;i<n;i++);
        // {
        //     div*=10;
        // }
        // int first=num/div;
        // if(first==9)
        // cout<<cur-num<<endl;
        // else 
        // {
        //     int has=0;
        //     for(int i=0;i<n;i++)
        //     {
        //         has*=10;
        //         has+=9;
        //     }
        //     cout<<has-num<<endl;
        // }

    }
    return 0;
}

