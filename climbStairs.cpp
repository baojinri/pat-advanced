#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 3)
            return n;
        int a = 1, b = 2;
        int temp;
        for (int i = 3; i <= n; i++)
        {
            temp = a + b;
            a = b;
            b = temp;
        }
        return temp;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution ans;
    cout << ans.climbStairs(n);
    return 0;
}