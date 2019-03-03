#include "pch.h"
#include <iostream>
#include <queue>

using namespace std;

int main() {//7576
	int row, col;
	scanf("%d %d", &col, &row);

	int **tomatos = new int*[row];
	for (int index_of_row = 0; index_of_row < row; ++index_of_row) {
		tomatos[index_of_row] = new int[col];
	}
	queue<pair<int, int>> ripe_tomato;

	int number_of_zero = 0;

	for (int index_of_row = 0; index_of_row < row; ++index_of_row) {
		for (int index_of_col = 0; index_of_col < col; ++index_of_col) {
			scanf("%d", tomatos[index_of_row] + index_of_col);
			if (tomatos[index_of_row][index_of_col] == 1) {
				ripe_tomato.push({ index_of_row, index_of_col });
			}
			else if (!tomatos[index_of_row][index_of_col]) {
				++number_of_zero;
			}
		}
	}

	int max_days = 1; // 최소 날짜를 저장하는 변수
	int array_x[4] = { 0,0,1,-1 };
	int array_y[4] = { 1,-1,0,0 };
	while (!ripe_tomato.empty()) {
		pair<int, int> now_position = ripe_tomato.front();
		ripe_tomato.pop();
		for (int index_of_array = 0; index_of_array < 4; ++index_of_array) {
			int now_x = now_position.first + array_x[index_of_array];
			int now_y = now_position.second + array_y[index_of_array];
			if (now_x >= 0 && now_y >= 0 && now_x < row && now_y < col && !tomatos[now_x][now_y]) {
				ripe_tomato.push({ now_x, now_y });
				tomatos[now_x][now_y] = tomatos[now_position.first][now_position.second] + 1;
				if (max_days < tomatos[now_x][now_y]) {
					max_days = tomatos[now_x][now_y];
				}
				--number_of_zero;
			}
		}
	}

	if (number_of_zero > 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", max_days - 1);
	}
	for (int index_of_row = 0; index_of_row < row; ++index_of_row) {
		delete[] tomatos[index_of_row];
	}
	delete[] tomatos;

	return 0;
}