#include <iostream>

int main() {
    long long number;
    scanf("%lld", &number);

    if (number == 0) {
        printf("0");
    } else if (number == 1 || number == 2) {
        printf("1");
    } else {
        number = number % 1500000;
        int pre = 1;
        int next = 1;
        long long index = 3;
        int result;
        while (index <= number) {
            result = pre + next;
            result = result % 1000000;

            pre = next;
            next = result;
            index++;
        }
        printf("%d", result);
    }

    return 0;
}