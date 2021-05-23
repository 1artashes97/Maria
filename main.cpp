#include <math.h>
#include <iostream>
#include <iomanip>


const double epsilon = 0.001;

template <typename Value>
Value get_minimum_point(const Value& x, const Value& r);


int main() {
    double x, r;
    std::cin >> x >> r;
    std::cout << std::endl;
    std::cout << std::fixed;
    std::cout << std::setprecision(4);
    try {
        std::cout << get_minimum_point<double>(x, r) << std::endl;
    }
    catch (const char* msg) {
	std::cout << msg << std::endl;
    }
    return 0;
}


template <typename Value>
Value get_minimum_point(const Value& x, const Value& r) {
    if (x - 1 <= 0) {
        throw ("Ilegal value X!");
    }

    Value k = 0;
    Value previous_formul = (4 + pow(r, k))/(2 + pow(r, k));

    while (true) {
        Value current_formul = (4 + pow(r, (k + 1)) / (2 + pow(r, k + 1)));
        if ((previous_formul - current_formul) < epsilon) {
            return current_formul;
        }
        previous_formul = current_formul;
        k++;
    }
}

