// problem_1267.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main() {
	int how_many_times_call;
	cin >> how_many_times_call;
	int fee_of_y = 0;
	int fee_of_m = 0;
	for (int index_of_input_fee = 0; index_of_input_fee < how_many_times_call; ++index_of_input_fee) {
		int fee;
		scanf("%d", &fee);
		fee_of_y += fee / 30 * 10;
		fee_of_m += fee / 60 * 15;
		if (fee_of_y % 30 >= 0) {
			fee_of_y += 10;
		}
		if (fee_of_m % 60 >= 0) {
			fee_of_m += 15;
		}
	}

	if (fee_of_m > fee_of_y) {
		printf("Y %d\n", fee_of_y);
	}
	else if (fee_of_m < fee_of_y) {
		printf("M %d\n", fee_of_m);
	}
	else {
		printf("Y M %d\n", fee_of_m);
	}

	return 0;
}