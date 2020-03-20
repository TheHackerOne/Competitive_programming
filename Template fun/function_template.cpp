#include<iostream>
using namespace std;

template <typename T>

T great(T x, T y) // OR  T great(int x, int y)  OR  T great(T x, int y)
{
    return (x > y) ? x : y; 
}

int main()
{
    cout<<great<int>(3,6)<<endl;
    cout<<great<char>('A','r')<<endl;
    cout<<great<double>(3.39,3.40)<<endl;
    system("pause");
    return 0;
}