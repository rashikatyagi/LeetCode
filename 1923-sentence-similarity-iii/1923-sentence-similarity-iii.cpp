class Solution {
public:
    vector<string> splitwords(string sen){
        vector<string> words;
        string temp = "";
        for(char ch : sen){
            if(ch == ' '){
                words.push_back(temp);
                temp = "";
            }
            else temp += ch;
        }
        words.push_back(temp);
        return words;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1 == sentence2) return true;
        vector<string> s1, s2;
        s1 = splitwords(sentence1);
        s2 = splitwords(sentence2);
        int size1 = s1.size();
        int size2 = s2.size();
        if(size2 > size1){
            swap(s1, s2);
            swap(size1, size2);
        }
        int start = 0;
        int end = size2 - 1;
        int index = 0;
        while(start < size2 && s1[index++] == s2[start]){
            start++;
        }
        index = size1 - 1;
        while(end >= 0 && s1[index--] == s2[end]){
            end--;
        }
        return start > end;
    }
};