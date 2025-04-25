class Solution {
public:
    string addStrings(string num1, string num2) {
        string n = "";
        int i = ((num1.length() < num2.length()) ? num1.length() : num2.length()) - 1;
        int taille_min = (num1.length() < num2.length()) ? num1.length() : num2.length();
        int taille_max = (num2.length() < num1.length()) ? num1.length() : num2.length();
        string num_short = (num1.length() < num2.length()) ? num1 : num2;
        string num_big = (num2.length() <= num1.length()) ? num1 : num2;

        int r = 0;

        // Add common digits
        while (i >= 0) {
            int c = (num_big[i + taille_max - taille_min] - '0') + (num_short[i] - '0') + r;
            n = string(1, (c % 10) + '0') + n;
            r = c / 10;
            i--;
        }

        // Add remaining digits in longer number
        i = taille_max - taille_min - 1;
        while (i >= 0) {
            int c = (num_big[i] - '0') + r;
            n = string(1, (c % 10) + '0') + n;
            r = c / 10;
            i--;
        }

        // Add final carry
        if (r != 0) {
            n = string(1, r + '0') + n;
        }

        return n;
    }
};
