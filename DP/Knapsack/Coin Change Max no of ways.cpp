
/*
https://leetcode.com/problems/coin-change-2/submissions/

COIN CHange
*/

#include <iostream>
#include<bits/stdc++.h>
#include<map>
#include<iterator>
using namespace std;
    int solve(int sum, vector<int>& coins) 
    {
        
        int n=coins.size();
        int dp[n+1][sum+1];
        for(int i=0;i<n+1;i++)
            dp[i][0]=1;
        for(int i=0;i<sum+1;i++)
            dp[0][i]=0;
        dp[0][0]=1;
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(coins[i-1]<=j)
                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }


int main()
{
    int T;
    cin>>T;
    int n;
    while(T>0)
    {
    	int n,k;
    	cin>>n>>k;
    	vector<int> a(n);
    	for(int i=0;i<n;i++)
    		cin>>a[i];   	
        
        cout<<solve(k,a)<<endl;
        T--;
    }
    return 0;
}




/*
int main()
{
    int t;
    cin>>t;
    map<int,int> m;
    map<int,int> :: iterator itr;   

    while(t>0)
    {
       
        int temp=0;
        int n,b;

        cin>>n>>b;
        int a[n];
         // cout<<" +++ 00 ";
        for(int i=0;i<n;i++)
        {        
            cin>>a[i];

            m[a[i]]++;
            // cout<<" +++1 ";
        }

        // cout<<" +++2 ";

        // for(itr!=m.begin();itr!=m.end();itr++)
        //         cout<<itr->first<<" "<< itr->second;


            int cnt=0,sum=0,flag=0;
            for(itr!=m.begin();itr!=m.end();itr++)
            {
                if(itr->first<=sum)
                {
                    while(itr->second!=0)
                    {
                        if(itr->first+sum<=b)
                        {
                            sum+=itr->first;
                            itr->second--;
                            cnt++;   
                       }
                       else
                       { 
                            flag=1;
                            break;
                        }
                    }            
                }
                if(flag=1)
                        break;
                cnt++;
            }

            cout<<cnt;
            t--;
        }



  
    return 0;
}
*/















/*
int xorArray(int arr[], int n) 
{ 
    int res = 0; 
    for (int i = 0; i < n; i++) 
        res = res ^ arr[i]; 
  
    return res; 
} 
  
// Function to return the count of ways 
// to play the first move optimally 
long getTotalWays(int arr[], int n) 
{ 
  
    // XOR of all the array elements 
    long xorArr = xorArray(arr, n); 

  
    // The player making the first move 
    // can't win the game no matter 
    // how optimally he plays 
    if (xorArr == 0) 
        return 0; 
  
    // Initialised with zero 
    long numberOfWays = 0,cnt=0; 
    for (int i = 0; i < n; i++) 
    {
        long requiredCoins = xorArr ^ arr[i];   
        if (requiredCoins < arr[i]) 
            numberOfWays++; 
    } 
   

  
    return (numberOfWays%998244353); 
} 
  


int main() 
{
    int T,n,l,r,q;
    cin>>T;
    
    map <int,int> ::iterator itr;
   

   while(T>0)
    {       
        cin>>n;
        int flag=1;
        
        vector <int> a(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        cin>>q;
        for(int k=0;k<q;k++)
        {
            map <int,int> m;
            cin>>l>>r;
            if(l==r)
            {
                cout<<"1\n";
                continue;
            }
            int b[n],p=0;

            for(int j=l;j<=r;j++)
            {
                b[p++]=a[j];
                m[a[j]]++;
                itr=m.find(a[j]);
                if(itr->first==a[j] && itr->second>1)
                {
                    flag=0;
                }
            }
            if(flag==0)
            {
                cout << getTotalWays(b, r-l+1)<<endl;
            }
            else if(flag==1)
            {
                if((r-l+1)%2==0)
                {
                    cout<<"0\n";
                }
                else
                    cout<<"1\n";
            } 
            flag=1;
        }

        T--;
        
    }   
    return 0;
}
*/
