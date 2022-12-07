#include <bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define pb emplace_back
#define po pop_back
#define vi vector<ll>
#define vii vector<vector<ll>>
using namespace std;
void file(){    
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);}
ll M = 1e9 + 7;
int rem;
string longDivision(string number, int divisor)
{
    string ans;

    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor && number.length()>1)
        temp = temp * 10 + (number[++idx] - '0');

    while (number.size() > idx) {
        rem = temp % divisor;
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
   
    if (ans.length() == 0)
        return "0";
    if(rem==0)
    return ans;
    else return number;
}
int main(){
    string num;
    cout<<"Prime Factors:\n";
    cout<<"Enter Number : ";
    cin>>num;
    rem=0;
    
    unordered_map<int,int> mp;
    int len = num.size();
   
    string ans = longDivision(num,2);
    while(rem == 0){
        mp[2]++;
        num =  ans;
        ans = longDivision(num,2);
    }

      for (int i = 3; i <= 1000000; i = i + 2)
    {   string ans = longDivision(num,i);
        while (ans!="0" && rem==0)
        {   mp[i]++;
            num =  ans;
            ans = longDivision(num,i);
        }
    }

    cout<<"\n";
    cout<<"Prime Factor"<<" - "<<"Power"<<"\n";
    for(auto x:mp) cout<<x.first<<" - "<<x.second<<"\n";
}

