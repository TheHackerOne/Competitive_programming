
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

void sieve(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int i = 2; i * i <= n; i++)
    {
        if (prime)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    sieve(n);
    system("pause");
    return 0;
}