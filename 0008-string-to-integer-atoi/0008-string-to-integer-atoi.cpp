class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int n = s.length();
        bool isNegative = false;

        // remove leading whitespaces
        while(index < n && s[index] == ' ') index++;

        //checking for sign
        if(index < n && s[index] == '-' || s[index] == '+'){
            isNegative = (s[index] == '-') ? true : false;
            index++;
        }

        //remove leading zeros
        while(index < n && s[index] == '0') index++;

        //create the number
        int number = 0;
        while((index) < n && s[index] >= '0' && s[index] <= '9'){
            int digit = s[index] - '0';
            if(number > INT_MAX / 10 || (number == INT_MAX / 10 && digit > 7)){
                return (isNegative) ? INT_MIN : INT_MAX;
            }
            number = number * 10 + digit;
            index++;
        }
        if(isNegative) return -1 * number;
        return number;
    }
};