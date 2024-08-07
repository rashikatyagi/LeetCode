class Solution {
public:
    vector<string> ones = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    vector<string> tens = {"", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    vector<string> thousands = {"", " Thousand", " Million", " Billion"};
    string solve(int num){
        //base case
        if(num == 0) return "";
        //CASE 1 : If number less than 20 (Direct 2 digit number)
        if(num < 20) return ones[num];

        //CASE : 2 Number less than 100 (2 digit number but greater than 19 so no direct answer)
        if(num < 100) return tens[num / 10] + ones[num % 10];   //first digit in 10s and second digit in ones

        //CASE 3 : 3 digit number (less then 1000)
        if(num < 1000) return ones[num / 100] + " Hundred" + solve(num % 100);

        //CASE 4 : Numbers equal to 1000 or in the powers of it (eg. 1000000 -> million (10^2) and 1000000000 -> billion (10^3))
        //for this we have to check for powers
        for(int i = 3 ; i >= 0 ; i--){
            if (num >= pow(1000, i)) {
                return solve(num / pow(1000, i)) + thousands[i] + solve(num % (int)pow(1000, i));
            }
        }  
        return "";
    }
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        return solve(num).substr(1);
    }
};