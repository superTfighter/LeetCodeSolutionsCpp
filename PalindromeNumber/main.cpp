#include "string"

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0 || (x % 10 == 0 && x > 9)) {
            return false;
        }

        string s = std::to_string(x);

        string p = s;

        reverse(p.begin(), p.end());

        if(s == p)
            return true;

        return false;

    }
};


int main()
{
    Solution s;

    int input1 = 10001;


    s.isPalindrome(input1);


    return 0;
}