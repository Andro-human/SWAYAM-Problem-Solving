// DP SOLUTION

class Solution
{
private:
    int mod = 1000000007;
public:
    int countFriendsPairings(int n) 
    { 
        vector<long long> dp (n+1, 0);
        dp[0] = 1;
        dp[1] = 1;  
        
        for (int i=2; i<=n; i++) {
            dp[i] = (dp[i-1] + ((i-1)*dp[i-2])%mod)%mod;
        }
        
        return dp[n];
    }
};    
 

// DP SOLUTION WITH SPACE OPTIMSATION

class Solution
{
private:
    int mod = 1000000007;
public:
    int countFriendsPairings(int n) 
    { 
        vector<long long> dp (n+1, 0);
        long long secondPrev = 1;
        long long prev = 1;  
        
        for (int i=2; i<=n; i++) {
            long long temp = (prev + ((i-1)*secondPrev)%mod)%mod;
            secondPrev = prev;
            prev = temp;
        }
        
        return prev;
    }
};    

