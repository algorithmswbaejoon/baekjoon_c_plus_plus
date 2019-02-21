#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int *height_of_dwarf = new int[9];
	int sum = 0;
	for (int index_of_dwarf = 0; index_of_dwarf < 9; index_of_dwarf++) {
		scanf("%d", (height_of_dwarf + index_of_dwarf));
		sum += height_of_dwarf[index_of_dwarf];
	}

	sort(height_of_dwarf, height_of_dwarf + 9);


	int delete_first = -1;
	int delete_second = -1;

	for (int index_of_dwarf = 0; index_of_dwarf < 9; index_of_dwarf++) {
		int temp = sum - height_of_dwarf[index_of_dwarf];
		for (int index_of_others = index_of_dwarf + 1; index_of_others < 9; index_of_others++) {
			int other_temp = temp - height_of_dwarf[index_of_others];
			if (other_temp == 100) {
				delete_first = index_of_dwarf;
				delete_second = index_of_others;
			}
		}
	}

	for (int index = 0; index < 9; index++) {
		if (index == delete_first || index == delete_second) {
			continue;
		}
		printf("%d\n", height_of_dwarf[index]);
	}

	return 0;
}