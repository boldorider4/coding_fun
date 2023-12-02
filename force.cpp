#include <iostream>

using namespace std;

void func(int& a, int b = 0)
{
    int other = 8;
    a = 4;
    cout << "a: " << a << " (before)" << endl;
    cout << "address of a: " << &a << " (before)" << endl;
    *((int**) &b - 1) = &other;
    cout << "a: " << a << " (after)" << endl;
    cout << "address of a: " << &a << " (after)" << endl;
    a = 12;
    cout << "other: " << other << endl;
}

int main()
{
    int i = 10;

    cout << "i: " << i << " (before)" << endl;
    func(i);
    cout << "i: " << i << " (after)" << endl;

    return 0;
}
