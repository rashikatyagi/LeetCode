class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        int i = 0, start = 0, end = 0;
        while(i < n && end < n){
            if(target[i] != arr[end]) end++;
            else{
                if(end - start > 0){
                    reverse(arr.begin() + start, arr.begin() + end + 1);
                    start++;
                    i++;
                    end = start;
                }
                else{
                    i++;
                    start++;
                    end++;
                }
            }
        }
        return target == arr;
    }
};