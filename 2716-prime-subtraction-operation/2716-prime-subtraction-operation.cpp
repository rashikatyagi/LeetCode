// class Solution {
// public:
//     bool isPrime[1000];
//     void sieveOfEratothenes(){
//         isPrime[0] = isPrime[1] = false;
//         for(int i = 2 ; i * i <= 1000 ; i++){
//             if(isPrime[i]){
//                 int j = i * i;
//                 while(j <= 1000){
//                     isPrime[j] = false;
//                     j += i;
//                 }
//             }
//         }
//     }
//     bool primeSubOperation(vector<int>& nums) {
//         int n = nums.size();
//         for(int i = n - 2 ; i >= 0 ; i--){
//             if(nums[i] > nums[i + 1]){
//                 for(int j = 2 ; j < nums[i] ; j++){
//                     if(isPrime[j] && nums[i] - j < nums[i + 1]){
//                         nums[i] -= j;
//                         break;
//                     }
//                 }
//             }
//         }
//         for(int i = 0 ; i < n - 1 ; i++){
//             if(nums[i] > nums[i + 1]) return false;
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        
        // Sieve of Atkin
        vector<bool> sieve(maxElement + 1, false);
        if (maxElement > 2) sieve[2] = true;
        if (maxElement > 3) sieve[3] = true;
        
        for (int x = 1; x * x <= maxElement; x++) {
            for (int y = 1; y * y <= maxElement; y++) {
                int n = (4 * x * x) + (y * y);
                if (n <= maxElement && (n % 12 == 1 || n % 12 == 5)) {
                    sieve[n] = !sieve[n];
                }
                
                n = (3 * x * x) + (y * y);
                if (n <= maxElement && n % 12 == 7) {
                    sieve[n] = !sieve[n];
                }
                
                n = (3 * x * x) - (y * y);
                if (x > y && n <= maxElement && n % 12 == 11) {
                    sieve[n] = !sieve[n];
                }
            }
        }
        
        for (int i = 5; i * i <= maxElement; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= maxElement; j += i * i) {
                    sieve[j] = false;
                }
            }
        }
        
        int currValue = 1;
        int i = 0;
        while (i < nums.size()) {
            int difference = nums[i] - currValue;
            
            if (difference < 0) {
                return false;
            }
            
            if (sieve[difference] == true || difference == 0) {
                i++;
                currValue++;
            } else {
                currValue++;
            }
        }
        return true;
    }
};
