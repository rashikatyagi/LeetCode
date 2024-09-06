class Solution {
public:
    string removeDuplicates(string s, int k) {
        for(int i = 1 ; i < s.length() ; i++){
            if(s[i] == s[i - 1]){
                int count = 1;
                while(s[i] == s[i - 1]){
                    count++;
                    i++;
                    if(count == k){
                        s.erase(i - k, k);
                        i = 0;
                        break;
                    }
                } 
            }
        }
        return s;
    }
};