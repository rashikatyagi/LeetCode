class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;
        int index1 = (total / 2) - 1;
        int index2 = (total / 2);
        int ele1 = -1, ele2 = -1;
        int i = 0, j = 0;
        int count = 0;
        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                if(count == index1) ele1 = nums1[i];
                if(count == index2) ele2 = nums1[i];
                i++;
                count++;
            }
            else{
                if(count == index1) ele1 = nums2[j];
                if(count == index2) ele2 = nums2[j];
                j++;
                count++;
            }
            if(ele1 != -1 && ele2 != -1) break;
        } 
        while(i < n){
            if(count == index1) ele1 = nums1[i];
            if(count == index2) ele2 = nums1[i];
            i++;
            count++;
            if(ele1 != -1 && ele2 != -1) break;
        }
        while(j < m){
            if(count == index1) ele1 = nums2[j];
            if(count == index2) ele2 = nums2[j];
            j++;
            count++;
            if(ele1 != -1 && ele2 != -1) break;
        }
        if(total & 1) return ele2;
        return (double)(ele1 + ele2) / (double)2;
    }
};