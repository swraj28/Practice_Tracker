#include<bits/stdc++.h>
using namespace std;
#define ll long long

int r;
int c;

char mat[1000][1000];

void dfs_helper(int i, int j, char ch, char color) {

	//matrix Boundary condition
	if (i < 0 or j < 0 or i >= r or j >= c) {
		return;
	}

	if (mat[i][j] != ch) {
		return;
	}

	//Recursion
	mat[i][j] = color;

	dfs_helper(i + 1, j, ch, color);
	dfs_helper(i, j + 1, ch, color);
	dfs_helper(i - 1, j, ch, color);
	dfs_helper(i, j - 1, ch, color);
}

void dfs(char ch, char color) {

	int cnt = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (mat[i][j] == ch) {
				dfs_helper(i, j, ch, color);
				cnt++;
			}
		}
	}

	cout << cnt << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> mat[i][j];
		}
	}

	dfs('.', '#');

	return 0;
}