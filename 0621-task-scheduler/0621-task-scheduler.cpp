class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxi = INT_MIN;
        for(char &c : tasks){
            freq[c - 'A']++;
            maxi = max(maxi, freq[c - 'A']);
        }
        int max_freq_element = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(freq[i] == maxi) max_freq_element++;
        }
        int time = ((maxi - 1) * (n + 1)) + max_freq_element;
        int size = tasks.size();
        return max(time, size);
    }
};