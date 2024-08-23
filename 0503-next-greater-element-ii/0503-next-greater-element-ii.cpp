class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(2 * n); 
        stack<int> st;
        for(int i = n - 1, j = 2 * n - 1 ; i >= 0 ; i--){
            arr[i] = arr[j--] = nums[i];
            st.push(arr[i]);
        }
       
        for(int i = n - 1 ; i >= 0 ; i--){
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            if(st.empty()){
                nums[i] = -1;
            }
            else nums[i] = st.top();
            st.push(arr[i]);
        }
        return nums;
    }
};