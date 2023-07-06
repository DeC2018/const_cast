#include <iostream>
using namespace std;

class ArrayInt
{
    int* data_;
    size_t size_;

public:
    explicit ArrayInt(size_t size) : data_(new int[size]), size_(size)
    {

    }

    ~ArrayInt()
    {
        delete[] data_;
    }

    size_t size() const
    {
        return size_;
    }

    const int& operator[] (size_t i) const
    {
        return data_[i];
    }

    int& operator[] (size_t i)
    {
        return const_cast<int&>(static_cast<const ArrayInt&>(*this)[i]);
    }
};


int main() {

    ArrayInt a(10);
    const ArrayInt b(10);

    a[0] = 200;

    std::cout << a[0] << std::endl;
    std::cout << b[0] << std::endl;

    return 0;
}

