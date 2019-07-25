#include <iostream>

int main() {
    long number_first, number_second;
    scanf("%ld %ld", &number_first, &number_second);
    long middle_sum = number_second + number_first;
    long length = number_first - number_second;
    if (length < 0) {
        length = -length;
    }
    printf("%ld", (length + 1) * (middle_sum) / 2);

    return 0;
}