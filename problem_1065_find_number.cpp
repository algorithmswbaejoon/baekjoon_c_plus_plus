
#include "pch.h"
#include <iostream>

using namespace std;

bool is_that(int now_number);

int main() {//1065
	int number;
	scanf("%d", &number);
	int count = 0;
	for (int now_number = 1; now_number <= number; now_number++) {
		if (is_that(now_number)) {
			count++;
		}
	}
	printf("%d\n", count);

	return 0;
}

bool is_that(int now_number) {//한수 판별 함수
	int temp = now_number;
	int first = temp % 10;
	temp /= 10;
	int second = temp % 10;
	int third = (temp % 100) / 10;
	if (third == 0 && !(now_number/1000)) {//처음부분
		return true;
	}
	else {
		if ((second - first) == (third - second) && !(now_number / 1000)) {
			return true;
		}
		else if((second - first) != (third - second)){
			return false;
		}
	}

	while (temp / 100) {//1000이 넘는수 확인
		first = temp % 10;
		temp /= 10;
		second = temp % 10;
		third = (temp % 100) / 10;
		if ((second - first) != (third - second)) {
			return false;
		}
	}
	return true;
}


