class Solution {
public:
    double power(double x, int n){
        if(n == 0) return 1;
        if(n & 1){
            return x * power(x * x, n / 2);
        }
        else return power(x * x, n / 2);
    }
    double myPow(double x, int n) {
        if(x == 1 || n == 0) return 1;
        if(x == -1){
            if(n & 1) return -1;
            return 1;
        }
        if(n < 0) x = 1 / x;
        return power(x, n);
    }
};