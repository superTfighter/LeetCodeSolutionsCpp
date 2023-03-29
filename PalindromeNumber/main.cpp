#include "string"
#include "iostream"
#include <algorithm> 

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


    bool solution = s.isPalindrome(input1);

    if(solution)
        cout << "True";
    else
        cout << "False";

    


    return 0;
}