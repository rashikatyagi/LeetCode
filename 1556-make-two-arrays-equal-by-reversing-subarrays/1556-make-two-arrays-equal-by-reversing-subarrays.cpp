class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        // int i = 0, start = 0, end = 0;
        // while(i < n && end < n){
        //     if(target[i] != arr[end]) end++;
        //     else{
        //         if(end - start > 0){
        //             reverse(arr.begin() + start, arr.begin() + end + 1);
        //             start++;
        //             i++;
        //         }
        //         else{
        //             i++;
        //             start++;
        //             end++;
        //         }
        //     }
        // }
        // return target == arr;
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for(int i : target){
            mp1[i]++;
        } 
        for(int i : arr){
            mp2[i]++;
        }
        bool ans = true;
        for(auto it : mp1){
            if(mp2.find(it.first) == mp2.end()) ans = false;
            else{
                if(mp2.find(it.first)->second != it.second) ans = false;
            }
        }
        return ans;
    }
};