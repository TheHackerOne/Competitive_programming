#include <iostream>
#include<cstring>
using namespace std;

int dp[100];

int main()
{
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    cout << "n'th catalan number = " << dp[n - 1];
    system("pause");
    return 0;
}