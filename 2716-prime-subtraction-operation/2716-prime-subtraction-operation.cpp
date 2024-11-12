class Solution {
public:
    void sieveOfEratothenes(vector<bool> &isPrime){
        isPrime[0] = isPrime[1] = false;
        for(int i = 2 ; i * i <= 1000 ; i++){
            if(isPrime[i]){
                int j = i * i;
                while(j <= 1000){
                    isPrime[j] = false;
                    j += i;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        bool isSorted = true;
        for(int i = 0 ; i < n - 1 ; i++){
            if(nums[i] >= nums[i + 1]) {
                isSorted = false;
                break;
            }
        }
        if(isSorted) return true;
        vector<bool> isPrime(1001, true);
        sieveOfEratothenes(isPrime);
        for(int i = n - 2 ; i >= 0 ; i--){
            if(nums[i] >= nums[i + 1]){
                for(int j = 2 ; j < nums[i] ; j++){
                    if(isPrime[j] && nums[i] - j < nums[i + 1]){
                        nums[i] -= j;
                        break;
                    }
                }
            }
        }
        for(int i = 0 ; i < n - 1 ; i++){
            if(nums[i] >= nums[i + 1]) return false;
        }
        return true;
    }
};
