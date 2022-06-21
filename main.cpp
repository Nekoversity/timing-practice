#include <iostream>
#include <chrono>
#include <array>
#include <numeric>
#include <algorithm>

using std::array;
using std::iota;
using std::cout;
using std::endl;
using std::sort;

class Timer {
private:
    using clock_type = std::chrono::steady_clock;
    using second_type = std::chrono::duration<double, std::ratio<1> >;
    std::chrono::time_point<clock_type> m_beg{ clock_type::now() };
public:
    void reset() {
        m_beg = clock_type::now();
    }

    double elapsed() const {
        return std::chrono::duration_cast<second_type>(clock_type::now() - m_beg).count();
    }
};

struct Sample {
    int x;
    int y;
};

struct BiggestSample {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
};

int main() {
    const int array_length = 10000;

    Timer t1;
    array<int, array_length> arr1;
    iota(arr1.rbegin(), arr1.rend(), 1); // fill the array with values 10000 to 1
    cout << "Creation time for array<int, 10000> >> " << t1.elapsed() << endl;

    Timer t2;
    array<int, array_length * 10> arr2;
    iota(arr2.rbegin(), arr2.rend(), 1);
    sort(arr2.begin(), arr2.end());
    cout << "Creation and sort time for array<int, 100000> >> " << t2.elapsed() << endl << endl;

    Timer t3;
    Sample arr3[array_length];
    for (Sample &s : arr3) {s = {1, 2};}
    cout << "Creation time for array<Sample, 10000> >> " << t3.elapsed() << endl;

    Timer t4;
    BiggestSample arr4[array_length*5];
    for (BiggestSample &a : arr4) {a = {1, 2, 3, 4, 5, 7};}
    cout << "Creation time for array<BiggestSample, 50000> >> " << t4.elapsed() << endl;
    
    return 0;
}
