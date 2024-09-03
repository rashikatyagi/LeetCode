class Solution {
public:
    int totalMoney(int n) {
        int day = 0;
        int start = 1;
        int money = 0;
        int bank = 0;
        while(day < n){
            if(day != 0 && day % 7 == 0){
                bank += (++start);
                money = start;
            }
            else{
                bank += (++money);
            }
            day++;
        }
        return bank;
    }
};