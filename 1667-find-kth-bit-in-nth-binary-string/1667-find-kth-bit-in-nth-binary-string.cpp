class Solution {
public:
    char findKthBit(int n, int k) {
        string temp = "";
        if(k == 1) return '0';
        while(temp.length() * 2 + 1 <= k && (n--) >= 0){
            if(temp == "") temp = "0";
            else{
                temp.push_back('1');
                for(int i = temp.length() - 2 ; i >= 0 ; i--){
                    if(temp[i] == '1') temp.push_back('0');
                    else temp.push_back('1');
                }
            }
        }
        int len = temp.length();
        
        if(k == len + 1) return '1';
        if(temp[(2 * len + 1) - k] == '1') return '0';
        return '1';
    }
};