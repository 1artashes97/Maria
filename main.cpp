#include <math.h>
#include <iostream>
#include <iomanip>


const double epsilon = 0.001;

double zoom_in(double value);

double get_minimum_point(double x);


int main() {
    double x;
    std::cin >> x;
    std::cout << std::fixed;
    std::cout << std::setprecision(4);
    try {
        std::cout << zoom_in(get_minimum_point(x)) << std::endl;
    }
    catch (const char* msg) {
	std::cout << msg << std::endl;
    }
    return 0;
}


double zoom_in(double value) {
    value *= 1000000;
    int tmp = (int) value;
    if (tmp % 100 != 0) {
        tmp -= (tmp% 100);
	tmp /= 100;
	tmp += 1;
	value = (double) tmp;
	value /= 10000;
    }
    return value;
}

double get_minimum_point(double x) {
    if (x - 1 <= 0) {
        throw ("Ilegal value X!");
    }

    double r = 1;
    double previous_formul = (4 + r) / (2 + r);

    while (true) {
	r *= 10;
        double current_formul = (4 + r) / (2 + r);
        if ((previous_formul - current_formul) < epsilon) {
            return current_formul;
        }
        previous_formul = current_formul;
    }
}

