class Solution {
public:
    int countVowelPermutation(int n) 
    {
        long int mod = 1e9+7;
        long int prevA = 1, prevE = 1, prevI = 1, prevO = 1, prevU = 1;
        long int currA = 0, currE = 0, currI = 0, currO = 0, currU = 0;
        
        
        for (long int i=2; i<=n; i++)
        {
            currA = (prevE%mod + prevI%mod + prevU%mod) % mod;
            currE = (prevA%mod + prevI%mod) % mod;
            currI = (prevE%mod + prevO%mod) % mod;
            currO = (prevI%mod);
            currU = (prevI%mod + prevO%mod)%mod;
            
            prevA=currA;
            prevE=currE;
            prevI=currI;
            prevO=currO;
            prevU=currU;
        }
        
        return (prevA+prevE+prevI+prevO+prevU)%mod;
        
        
    }
};