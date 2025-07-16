// Given a string s, return the longest palindromic substring in s.
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        while(i<j) {
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int longest = 0;
        string ans = "";
        if(s.size() == 1) return s;
        if(s.size() == 2 && s[0] != s[1]) {
            ans = s[0];
            return ans;
        }
        
        for(int i=0; i<s.size(); i++){
            int j=s.size()-1;
            while(j>=i) {
                int len = j - i + 1;
                if(len <= longest) break;
                string temp = s.substr(i, len);
                if(isPalindrome(temp)) {
                    if(temp.size() > longest) {
                        longest = temp.size();
                        ans = temp;
                        break;
                    }
                }
                j--;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string s = "uwqrvqslistiezghcxaocjbhtktayupazvowjrgexqobeymperyxtfkchujjkeefmdngfabycqzlslocjqipkszmihaarekosdkwvsirzxpauzqgnftcuflzyqwftwdeizwjhloqwkhevfovqwyvwcrosexhflkcudycvuelvvqlbzxoajisqgwgzhioomucfmkmyaqufqggimzpvggdohgxheielsqucemxrkmmagozxhvxlwvtbbcegkvvdrgkqszgajebbobxnossfrafglxvryhvyfcibfkgpbsorqprfujfgbmbctsenvbzcvypcjubsnjrjvyznbswqawodghmigdwgijfytxbgpxreyevuprpztmjejkaqyhppchuuytkdsteroptkouuvmkvejfunmawyuezxvxlrjulzdikvhgxajohpzrshrnngesarimyopgqydcmsaciegqlpqnclpwcjqmhtmtwwtbkmtnntdllqbyyhfxsjyhugnjbebtxeljytoxvqvrxygmtogndrhlcmbmgiueliyfkkcuypvvzkomjrfhuhhnfbxeuvssvvllgukdolffukzwqaimxkngnjnmsbvwkajyxqntsqjkjqvwxnlxwjfiaofejtjcveqstqhdzgqistxwsgrovvwgorjaoosremqbzllgbgrwtqdggxnyvkivlcvnv";
    string result = solution.longestPalindrome(s);
    cout<< "Longest palindromic substring: " << result << endl;
    return 0;
}