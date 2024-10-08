class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0){
            x = 1 / x;
        }
        long num = labs(n);
        if(x == 1 || num == 0) return 1;
        if(x == -1 && !(num & 1)) return 1;
        if(x == -1 && (num & 1)) return -1;
        double ans = 1;
        while(num){
            if(num & 1){
                ans *= x;
            }
            x *= x;
            num >>= 1;
        }
        return ans;
    }
};