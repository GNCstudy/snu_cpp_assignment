// 참고 : https://www.codespeedy.com/solution-of-n-queen-problem-in-cpp/

#include "std_lib_facilities.h"
#include <time.h> 

// 11 Queens Problem 을 푸는 프로그램
// grid[][]는 0과 1이 놓일 수 있는 격자판(체스보드)를 의미한다.
// grid[11][11] 은 11 x 11 의 격자판이다.
// 8 Queens로 만들기 위해서는 grid를 [8][8]로 바꾸어주고 또한 main함수에서의 int할당을 8로만 바꾸어주면된다.

int grid[11][11];

// p를 0으로 할당한다.
int p = 0;



void print(int n) {
    for (int i = 0; i <= n - 1; i++) {
        for (int j = 0; j <= n - 1; j++) {

            cout << grid[i][j] << " ";

        }
        cout << endl;
    }
    cout << endl;
    
    if (p == 0) {
        clock_t endTime = clock(); // 종료 시간을 할당한다.
        cout << "EndTime: " << double(endTime) << " ms"<<endl; // 종료 시간을 출력한다.
        cout << "시간 측정 : " << double(endTime) <<" ms"<< endl; // 시작과 종료 사이의 시간 간격을 출력한다.
        exit(0); // 첫번째 해답이 출력되면 프로그램을 중지시킨다.
    }
    p = 1;
    
}
// 위치가 safe한가 아닌가 체크해주는 함수
// row는 몇 번째 퀸인가를 나타내며, column은 그 row상에서 퀸의 가능한 위치를 나타낸다.
bool isSafe(int col, int row, int n) {
    // 같은 칼럼을 체크
    for (int i = 0; i < row; i++) {
        if (grid[i][col]) {
            return false;
        }
    }
    // 왼쪽 대각선을 체크
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (grid[i][j]) {
            return false;
        }
    }
    // 오른쪽 대각선을 체크
    for (int i = row, j = col; i >= 0 && j < n; j++, i--) {
        if (grid[i][j]) {
            return false;
        }
    }
    return true;
}
// 각 퀸의 위치를 찾아 주는 함수
// row는 몇 번째 퀸인가를 나타내며, column은 그 row상에서 퀸의 가능한 위치를 나타낸다.
bool solve(int n, int row) {
    if (n == row) {
        print(n);
        return true;
    }
    // 변수 res의 할당은 backtracking을 이용하기 위함이다.
    bool res = false;
    for (int i = 0; i <= n - 1; i++) {
        if (isSafe(i, row, n)) {
            grid[row][i] = 1;
            // 다음 Queen을 위한 재귀
            res = solve(n, row + 1) || res;// res가 false면 backtracking이 발생한다.
            
            //grid[row][i]을 0으로 할당한다.
            grid[row][i] = 0;
        }
    }
    return res;
}
int main()
{
    clock_t startTime = clock(); // 시작 시간(0초)을 할당한다.
    cout <<"StartTime: "<< double(startTime) <<" ms"<< endl << endl; // 시작 시간을 출력한다.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=11; // 8 Queens에서는 n을 8로 바꾸어준다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = 0;
        }
    }
    
    bool res = solve(n, 0);
    return 0;
}