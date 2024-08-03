class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for(int i : target){
            mp1[i]++;
        } 
        for(int i : arr){
            mp2[i]++;
        }
        if(mp1.size() != mp2.size()) return false;
        for(auto it : mp2){
            if(mp1[it.first] != it.second) return false;
        }
        return true;
    }
};