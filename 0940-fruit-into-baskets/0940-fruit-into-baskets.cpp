class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int left = 0, right = 0;
        int len = 0;
        int maxLength = 0;
        while(right < fruits.size()){
            mp[fruits[right]]++;
            if(mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            else{
                len = right - left + 1;
                maxLength = max(maxLength, len);
            }
            right++;
        }
        return maxLength;
    }
};