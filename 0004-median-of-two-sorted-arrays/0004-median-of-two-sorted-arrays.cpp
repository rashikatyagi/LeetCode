class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        vector<int> arr;
        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                arr.push_back(nums1[i++]);
            }
            else{
                arr.push_back(nums2[j++]);
            }
        }
        while(i < n){
            arr.push_back(nums1[i++]);
        }
        while(j < m){
            arr.push_back(nums2[j++]);
        }
        int final_size = arr.size();
        double ans;
        if(final_size & 1){
            ans = arr[final_size / 2];
        }
        else{
            int index1 = (final_size - 1) / 2;
            int index2 = final_size / 2;
            ans = (arr[index1] + arr[index2]) / (double)2;
        }
        return ans;
    }
};