class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int extra_days = n % 7;
        int week_diff = max(0, weeks - 1);
        int money = (28 * weeks) + (7 * ((week_diff) * (week_diff + 1)) / 2);
        money += (weeks * extra_days) + ((extra_days * (extra_days + 1)) / 2);
        return money;
    }
};