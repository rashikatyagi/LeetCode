class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        for(int i = nums2.size() - 1 ; i >= 0 ; i--){
            int number = nums2[i];
            while(!st.empty() && st.top() < number) st.pop();
            if(st.empty()) mp[number] = -1;
            else mp[number] = st.top();
            st.push(number);
        }
        for(int i = 0 ; i < nums1.size() ; i++){
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};