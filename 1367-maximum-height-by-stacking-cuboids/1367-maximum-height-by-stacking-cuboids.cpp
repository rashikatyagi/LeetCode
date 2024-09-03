class Solution {
public:
    bool check(vector<int> &curr, vector<int> &prev){
        // curr--> base vala dabba. prev--> chote vala. As we are starting from the last index
        if(curr[0] >= prev[0] && curr[1] >= prev[1] && curr[2] >= prev[2]) {
            return true;
        }
        return false;
    }
    // function for longest increasing subsequence
    int solveTabSO(vector<vector<int>>& cuboids){
        int n = cuboids.size();
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for(int currIndex = n - 1 ; currIndex >= 0 ; currIndex--){
            for(int prevIndex = currIndex - 1 ; prevIndex >= -1 ; prevIndex--){
                int ans1 = 0;
                if(prevIndex == -1 || check(cuboids[currIndex], cuboids[prevIndex])){
                    //height is getting added as we have to return the maximum height
                    ans1 = cuboids[currIndex][2] + prev[currIndex + 1];
                }
                int ans2 = prev[prevIndex + 1];
                curr[prevIndex + 1] = max(ans1, ans2);
            }
            prev = curr;
        }
        return curr[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        //sort the dimensions inside the array to get the maximum dimension as height
        for(auto &cuboid : cuboids){
            sort(cuboid.begin(), cuboid.end());
        }
        //sort the array to get all the dimensions in sorted order
        sort(cuboids.begin(), cuboids.end());
        int ans = solveTabSO(cuboids);
        return ans;
    }
};