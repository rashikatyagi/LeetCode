class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        st.push(INT_MAX);
        for(int i = nums2.size() - 1 ; i >= 0 ; i--){
            while(st.top() < nums2[i]) st.pop();
            if(st.top() == INT_MAX) mp[nums2[i]] = -1;
            else mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        for(int i = 0 ; i < nums1.size() ; i++){
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};