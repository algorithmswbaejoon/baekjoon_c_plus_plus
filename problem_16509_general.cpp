#include <iostream>
#include <queue>
#include <cstring>
//problem 16509 General
using namespace std;

int change_row[8] = {2, 3, 3, 2, -2, -3, -3, -2};
int change_col[8] = {3, 2, -2, -3, -3, -2, 2, 3};

pair<int, int> input_point() {
    int point_of_row;
    int point_of_col;
    scanf("%d %d", &point_of_row, &point_of_col);
    return make_pair(point_of_row, point_of_col);
}

int **go_to(int index_of_way) {
    int **way = new int *[2];
    for (int index = 0; index < 2; index++) {
        way[index] = new int[2];
        memset(way[index], 0, sizeof(int) * 2);
    }
    switch (index_of_way) {
        case 0:
            way[0][0] = 0;
            way[0][1] = 1;
            way[1][0] = 1;
            way[1][1] = 2;
            break;
        case 1:
            way[0][0] = 1;
            way[0][1] = 0;
            way[1][0] = 2;
            way[1][1] = 1;
            break;
        case 2:
            way[0][0] = 1;
            way[0][1] = 0;
            way[1][0] = 2;
            way[1][1] = -1;
            break;
        case 3:
            way[0][0] = 0;
            way[0][1] = -1;
            way[1][0] = 1;
            way[1][1] = -2;
            break;
        case 4:
            way[0][0] = 0;
            way[0][1] = -1;
            way[1][0] = -1;
            way[1][1] = -2;
            break;
        case 5:
            way[0][0] = -1;
            way[0][1] = 0;
            way[1][0] = -2;
            way[1][1] = -1;
            break;
        case 6:
            way[0][0] = -1;
            way[0][1] = 0;
            way[1][0] = -2;
            way[1][1] = 1;
            break;
        case 7:
            way[0][0] = 0;
            way[0][1] = 1;
            way[1][0] = -1;
            way[1][1] = 2;
            break;
    }

    return way;
}

void delete_array(int **array, int length) {
    for (int index = 0; index < length; index++) {
        delete[] array[index];
    }
}

int main() {
    int chess_board[10][9] = {0,};

    pair<int, int> icon_point = input_point();
    pair<int, int> king_point = input_point();

    queue<pair<int, int>> queue;
    chess_board[icon_point.first][icon_point.second] = -1;
    queue.push(icon_point);

    bool is_can = false;
    while (!queue.empty()) {
        if (is_can) {
            break;
        }
        pair<int, int> now_point = queue.front();
        queue.pop();

        for (int index = 0; index < 8; index++) {
            int get_changed_row = now_point.first + change_row[index];
            int get_changed_col = now_point.second + change_col[index];
            bool is_changed = false;
            bool is_there_king = false;
            if (0 <= get_changed_row && get_changed_row < 10 && 0 <= get_changed_col && get_changed_col < 9 &&
                chess_board[get_changed_row][get_changed_col] != -1) {
                int **way_change = go_to(index);
                for (int way_change_index = 0; way_change_index < 2; way_change_index++) {
                    if (king_point.first == now_point.first + way_change[way_change_index][0] &&
                        king_point.second == now_point.second + way_change[way_change_index][1]) {
                        is_there_king = true;
                        break;
                    }
                }
                delete_array(way_change, 2);
                if (chess_board[get_changed_row][get_changed_col] == 0) {
                    is_changed = true;
                } else if (chess_board[now_point.first][now_point.second] + 1 <=
                           chess_board[get_changed_row][get_changed_col]) {
                    is_changed = true;
                }
                if (is_changed && !is_there_king) {
                    if (chess_board[now_point.first][now_point.second] == -1) {
                        chess_board[get_changed_row][get_changed_col] = 1;
                    } else {
                        chess_board[get_changed_row][get_changed_col] =
                                chess_board[now_point.first][now_point.second] + 1;
                    }
                    queue.push(make_pair(get_changed_row, get_changed_col));
                    if (get_changed_row == king_point.first && get_changed_col == king_point.second) {
                        cout << chess_board[get_changed_row][get_changed_col];
                        is_can = true;
                        break;
                    }//출력 부분
                }
            }
        }
    }

    return 0;
}
