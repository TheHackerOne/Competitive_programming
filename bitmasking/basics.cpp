#include <bits/stdc++.h>
using namespace std;

// to find the unique no in a set where each no occur twice except one no.
void unique_number()
{
    int y = 0;
    vector<int> g = {1, 2, 3, 4, 3, 2, 1};
    for (int c : g)
        y ^= c;
    cout << "unique element = " << y;
}

// to find how many bits to change in 'a' to make a number 'b'
void bit_change_count()
{
    int a = 10; // 10 = 1010
    int b = 13; // 13 = 1101
    int ans = a ^ b;
    int count = 0;
    while (ans)
    {
        count += (ans & 1);
        ans = ans >> 1;
    }
    cout << "\ncount = " << count;
}

void bit_change_count_fast()
{
    int count = 0;
    int a = 10; // 10 = 1010
    int b = 13; // 13 = 1101
    int ans = a ^ b;
    while (ans)
    {
        count++;
        ans = ans & (ans - 1);
    }
    cout << "\ncount = " << count;
}

// find if ith bit of a number is '1' or '0'.
void get_ith_bit(int n, int i)
{ // n = 10 -> 1010
    n = (n >> i & 1) == 1 ? 1 : 0;
    cout << "\ni'th bit = " << n;
}

// to flip the i'th bit of a number
void flip_ith_bit(int n, int i)
{
    int mask = 1 << i;
    cout << "\nith bit flipped " << n; // 10 = 1010
    n = (n ^ mask);                    //        |
    cout << "\nith bit flipped " << n; // 8 = 1000
}

// print all subsets of a string
void all_subsets()
{
    string a;
    cin >> a;
    int len = a.length();
    for (int i = 0; i < pow(2, len); i++)
    {
        int current_bit = i;
        for (int j = 0; j < len; j++)
        {
            if (current_bit & 1)
            {
                cout << a[j] << " ";
            }
            current_bit = current_bit >> 1;
        }
        cout << "\n";
    }
}

// to find two unique numbers from a set containing duplicate no's except two numbers
void two_unique_numbers()
{
    int a[] = {1, 2, 3, 6, 5, 3, 2, 1}, bit_no = -1;
    vector<int> g1, g2;
    bool got_it = true;
    int total_xor, size = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < size; i++)
        total_xor ^= a[i];
    cout << "\ntotal xor = " << total_xor;
    while (got_it)
    {
        bit_no++;
        if (total_xor & 1)
        {
            for (int i = 0; i < size; i++)
            {
                int temp = a[i];
                a[i] = a[i] >> bit_no;
                if (a[i] & 1)
                    g1.push_back(temp);
                else
                    g2.push_back(temp);
            }
            break;
        }
        else
            total_xor = total_xor >> 1;
    }
    int g1_xor = 0, g2_xor = 0;
    for (int i : g1)
        g1_xor ^= i;
    for (int j : g2)
        g2_xor ^= j;
    cout << "\n1st number = " << g1_xor;
    cout << "\n2nd number = " << g2_xor;
}

int main()
{
    int a = 10, b = 10;
    a = a << 1; // left shift means multiplying 'a' by 2^bit .
    b = b >> 1; // left shift means dividing 'a' by 2^bit .
    cout << a << endl;
    cout << b << endl;

    unique_number();

    bit_change_count();

    bit_change_count_fast();

    get_ith_bit(10, 0);

    flip_ith_bit(10, 1);

    all_subsets();

    two_unique_numbers();

    return 0;
}
