class Solution {
public:
    bool isvowel(char c)
    {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    
    string reverseVowels(string s) {
        if (s.size() == 0) return s;
        int i = 0, j = s.size() - 1;
        while(i < j)
        {
            while(i < j && !isvowel(s[i])) ++i;
            while(i < j && !isvowel(s[j])) --j;
            if (i < j) swap(s[i++], s[j--]);
        }
        return s;
    }
};
