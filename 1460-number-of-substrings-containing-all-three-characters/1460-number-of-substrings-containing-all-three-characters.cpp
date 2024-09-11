class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.length();
        int i = 0;
        vector<int> hash(3, -1);
        while(i < n){
            hash[s[i] - 'a'] = i;
            if(hash[0] != -1 && hash[1] != -1 && hash[2] != -1){
                count += (1 + min(hash[0], min(hash[1], hash[2])));
            }
            i++;
        }
        return count;
    }
};