/**
 * Created by Hunter Damron
 * Copyright 2018
 */

/**
 * Application accepts one positive or negative integer from stdin without
 * prompt and outputs the sum of its digits with the same sign as the input.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char** argv) {
    int num = 0;
    cin >> num;

    bool negative = num < 0;
    if (negative)
        num = -num;

    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    if (negative)
        sum = -sum;

    cout << sum << endl;

    return 0;
}
