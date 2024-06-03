#include <iostream>
#include <vector>
using namespace std;

void printSolution(const vector<vector<int> >& board) {
    int N = board.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}


bool isSafe(const vector<vector<int> >& board, int row, int col) {
int N = board.size();
for (int i = 0; i < col; i++) {
if (board[row][i])
return false;
}

for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
if (board[i][j])
return false;
}

for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
if (board[i][j])
    return false;
    }
    return true;
}

bool solveNQUtil(vector<vector<int> >& board, int col) {
int N = board.size();
if (col >= N)
return true;
for (int i = 0; i < N; i++) {
if (isSafe(board, i, col)) {
    board[i][col] = 1;
if (solveNQUtil(board, col + 1))
return true;
board[i][col] = 0;
}
}
return false;
}

int main() {
int N;
cout << "Enter the value of N for N-Queens problem: ";
cin >> N;

vector<vector<int> > board(N, vector<int>(N, 0));

if (!solveNQUtil(board, 0)) {
cout << "Solution does not exist" << endl;
return 0;
}
printSolution(board);
return 0;
}
