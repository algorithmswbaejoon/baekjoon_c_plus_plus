#include "pch.h"
#include <iostream>
#include<vector>
#include <string>

using namespace std;

int main() {//1158
	vector<int> vector;
	int numbers;
	int how_far;
	cin >> numbers >> how_far;
	for (int index = 1; index <= numbers; index++) {
		vector.push_back(index);
	}
	string str = "<";
	int now_position = 0;
	while (vector.size()) {
		now_position = (now_position + how_far - 1) % vector.size();
		if (vector.size() == 1) {
			str += (to_string(vector.at(now_position)) + ">");
		}
		else {
			str += (to_string(vector.at(now_position)) + ", ");
		}
		vector.erase(vector.begin() + now_position);
	}

	cout << str << endl;
	return 0;
}