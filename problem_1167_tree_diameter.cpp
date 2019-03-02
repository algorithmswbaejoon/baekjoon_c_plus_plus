#include "pch.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>

using namespace std;

int max_rad = 0;
int fartest_vertex;

void dfs(vector<pair<int, int>> *edges_with_cost, int tail_vertex, int max_number, bool *visited, int number_of_vertices) {
	for (vector<pair<int, int>>::iterator iter = edges_with_cost[tail_vertex].begin(); iter < edges_with_cost[tail_vertex].end(); ++iter) {
		if (!visited[iter->first]) {
			visited[iter->first] = true;
			int now_max_number = max_number + iter->second;
			if (max_rad < now_max_number) {
				max_rad = now_max_number;
				fartest_vertex = iter->first;
			}
			dfs(edges_with_cost, iter->first, now_max_number, visited, number_of_vertices);
		}
	}
}

int main() {
	int number_of_vertices;
	scanf("%d", &number_of_vertices);
	vector<pair<int, int>> *edges_with_cost = new vector<pair<int, int>>[number_of_vertices];
	bool *visited = new bool[number_of_vertices];
	memset(visited, false, sizeof(bool)* number_of_vertices);

	for (int index_input = 0; index_input < number_of_vertices; ++index_input) {
		int tail_vertex;
		scanf("%d", &tail_vertex);
		while (1) {
			int head_vertex;
			int cost_of_edges;
			scanf("%d", &head_vertex);
			if (head_vertex != -1) {
				scanf("%d", &cost_of_edges);
				edges_with_cost[tail_vertex - 1].push_back({ head_vertex - 1, cost_of_edges });
			}
			else {
				break;
			}
		}
	}

	visited[0] = true;
	dfs(edges_with_cost, 0, 0, visited, number_of_vertices);//1번 째 vertex부터 제일 먼 곳까지 가기위해 서정
	memset(visited, false, sizeof(bool)* number_of_vertices);//다시 visited 초기화

	max_rad = 0;//최대 반지름 다시 초기화

	visited[fartest_vertex] = true;//다시 dfs
	dfs(edges_with_cost, fartest_vertex, 0, visited, number_of_vertices);//최대 vertex 지점부터 최대 거리 구하는 공식-> 1이 마지막 vertex가 아닐 수 도 있음

	//모든 vertex를 다시 다 탐색하면 시간 복잡도가 커진다 따라서 1 vertex를 기준으로 하고 최대 거리에서 다시 구하는 방식을 사용

	printf("%d\n", max_rad);

	delete[] edges_with_cost;
	delete[] visited;

	return 0;
}