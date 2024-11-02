class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        if(sentence[0] != sentence[n - 1]) return false;
        for(int index = 1 ; index < n -1 ; index++){
            if(sentence[index] == ' '){
                if(sentence[index - 1] != sentence[index + 1]) return false;
            }
        }
        return true;
    }
};