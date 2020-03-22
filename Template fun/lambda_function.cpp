
#include <bits/stdc++.h>
#include <functional>
using namespace std;

void test(std::function<void()> inc)
{
    inc();
}

int main()
{
    vector<int> a = {1, 12, 34, 10, 23, 45, 67, 34, 23, 32}, b;

    int u = 10;

    auto increment = [&]() {
        u += 5;
    };

    test(increment);
    cout << u;
    return 0;
}


// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// int main()
// {
//     vector<int> a = {1, 12, 34, 10, 23, 45, 67, 34, 23, 32}, b;

//     int i = 8;
//     int u = 98;

//     auto sumGet = [i, u](int x, int y) {
//         // i and u are only in read mode in this scope
//         // for read and write mode u have to use reference
//         return x + y + i + u;
//     };

//     auto sumGet1 = [&i, &u](int x, int y) {
//         i = 30;
//         u = 50;
//         return x + y + i + u;
//     };

//     auto sumGet2 = [&](int x, int y) {
//         i = 30;
//         u = 50;
//         return x + y + i + u;
//     };

//     cout << sumGet(123, 109) << endl;
//     cout << i << " " << u << endl;
//     cout << sumGet1(123, 109) << endl;
//     cout << i << " " << u << endl;

//     return 0;
// }