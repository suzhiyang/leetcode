class Solution {
public:
    string count1k(int n)
    {
        string a[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string aa[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string r;
        if (n <= 19) r = a[n];
        else if (n >= 20 && n < 100)
        {
            r = aa[n / 10];
            if (n % 10 != 0) r += " " + a[n % 10];
        }
        else if (n >= 100)
        {
            r = a[n / 100] + " Hundred";
            if (n % 100 != 0) r += " " + count1k(n % 100);
        }
        return r;
    }
    
    string numberToWords(int num) {
        string r;
        if (num == 0) return "Zero";
        if (num >= 1000000000) r = count1k(num / 1000000000) + " Billion";
        num %= 1000000000;
        if (num >= 1000000)
        {
            if (r != "") r += " ";
            r += count1k(num / 1000000) + " Million";
        }
        num %= 1000000;
        if (num >= 1000)
        {
            if (r != "") r += " ";
            r += count1k(num / 1000) + " Thousand";
        }
        num %= 1000;
        if (num > 0)
        {
            if (r != "") r += " ";
            r += count1k(num);
        }
        return r;
    }
};
