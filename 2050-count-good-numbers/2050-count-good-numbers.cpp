class Solution {
public:
    long long int MOD = 1000000007;
    int powerExponentiation(int x, long long n){
        if(n == 0) return 1;
        if(n & 1) return ((x % MOD) * powerExponentiation(((x % MOD) * (x % MOD)) % MOD, n / 2) % MOD);
        else return (powerExponentiation(((x % MOD) * (x % MOD)) % MOD, n / 2) % MOD);

    }
    int countGoodNumbers(long long n) {
        // if(n == 1) return 5;
        // if(n == 2) return 20;
        if(n & 1) return (5 * (powerExponentiation(20, (n - 1) / 2) % MOD)) % MOD;
        else return (powerExponentiation(20, n / 2) % MOD);
    }
};