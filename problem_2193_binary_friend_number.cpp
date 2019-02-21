// problem_2193.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main() {
	int number_of_number_length;

	cin >> number_of_number_length;

	long long int **binary_number_cost = new long long int*[2];
	binary_number_cost[0] = new long long int[number_of_number_length];
	binary_number_cost[1] = new long long int[number_of_number_length];
	
	binary_number_cost[0][0] = 0;
	binary_number_cost[1][0] = 1;
	for (int index_of_col = 1; index_of_col < number_of_number_length; index_of_col++) {//모든 index dfs해 준다
		binary_number_cost[0][index_of_col] = binary_number_cost[0][index_of_col - 1] + binary_number_cost[1][index_of_col - 1];//0이 연속으로 나올경우, 1에서 0으로 갈경우
		binary_number_cost[1][index_of_col] = binary_number_cost[0][index_of_col - 1];//0에서만 1이 될 수 있다
	}
	
	cout << binary_number_cost[0][number_of_number_length - 1] + binary_number_cost[1][number_of_number_length - 1] << endl;

	return 0;
}
