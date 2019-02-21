#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int first_contest_price(int what_rank);
int second_contest_price(int what_rank);

int main() {
	vector<int> store;
	int how_many_times;
	scanf("%d", &how_many_times);
	for (int index_of_how_many = 0; index_of_how_many < how_many_times; index_of_how_many++) {
		int first_contest;
		int second_contest;
		scanf("%d %d", &first_contest, &second_contest);
		store.push_back(first_contest_price(first_contest) + second_contest_price(second_contest));
	}

	vector<int>::iterator iter;
	for (iter = store.begin(); iter != store.end(); ++iter) {
		cout << *iter << endl;
	}

	
	return 0;
}

int first_contest_price(int what_rank) {
	if (what_rank == 0) {
		return 0;
	}
	int first_reward[6] = { 500,300,200,50,30,10 };
	int people_of_reward[6] = { 1,2,3,4,5,6 };
	int sum_of_people = 0;
	for (int index_of_rank_people = 0; index_of_rank_people < 6; index_of_rank_people++) {
		sum_of_people += people_of_reward[index_of_rank_people];
		if (sum_of_people >= what_rank) {
			return first_reward[index_of_rank_people] * 10000;
		}
	}
	return 0;
}

int second_contest_price(int what_rank) {
	if (what_rank == 0) {
		return 0;
	}
	int second_reward[5] = { 512,256,128,64,32 };
	int people_of_reward[5] = { 1,2,4,8,16 };
	int sum_of_people = 0;
	for (int index_of_rank_people = 0; index_of_rank_people < 5; index_of_rank_people++) {
		sum_of_people += people_of_reward[index_of_rank_people];
		if (sum_of_people >= what_rank) {
			return second_reward[index_of_rank_people] * 10000;
		}
	}
	return 0;
}