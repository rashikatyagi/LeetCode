class Solution {
public:
    string intToRoman(int num) {
        vector<string> roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1} ;
        int index = 0;
        string ans = "";
        while(index <= 12){
            while(values[index] <= num){
                ans += roman[index];
                num -= values[index];
            }
            if(num == 0) break;
            index++;
        }
        return ans;
    }
};