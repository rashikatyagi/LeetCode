class Solution {
public:
    int gcd(int a, int b){
        if(a == 0) return b;
        if(b == 0) return a;
        if(a > b) return gcd(a % b, b);
        else return gcd(a, b % a);
    }
    string gcdOfStrings(string str1, string str2) {
        //check whether gcd exists or not
        int n1 = str1.length(), n2 = str2.length();
        if(str1 + str2 == str2 + str1){
            //exists
            return str1.substr(0, gcd(n1, n2));
        }
        return "";
    }
};