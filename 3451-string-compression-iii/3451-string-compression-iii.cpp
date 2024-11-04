class Solution {
public:
    string compressedString(string word) {
        int n = word.length();
        vector<int> fre(n, 1);
        for(int i = 1 ; i < n ; i++){
            if(word[i] == word[i - 1]){
                if(fre[i - 1] == 9) continue;
                fre[i] += fre[i - 1];
                fre[i - 1] = 0;
            }
        }
        string comp = "";
        for(int i = 0 ; i < n ; i++){
            if(fre[i] != 0){
                comp += to_string(fre[i]);
                comp.push_back(word[i]);
            }
        }
        return comp;
    }
};