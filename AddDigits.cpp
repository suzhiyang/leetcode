class Solution {
public:
    int addDigits(int num) {
        if (num < 10) return num;
        int c = 0;
        while(num != 0)
        {
            c += num % 10;
            num /= 10;
        }
        return addDigits(c);
    }
};
