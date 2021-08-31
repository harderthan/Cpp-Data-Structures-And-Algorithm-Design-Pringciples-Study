#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

template<typename T> class dynamic_array
{
    T *data;
    size_t n;

public:
    dynamic_array(int n)
    {
        this->n = n;
        data = new T[n];
    }
    dynamic_array(const dynamic_array<t> &other)
    {
        n = other.n;
        data = new T[n];

        for (int i = 0; i < n; i++)
            data[i] = other[i];
    }
};

int main(int argc, char **argv)
{
    cout << "hello, world" << endl;
    return 0;
}