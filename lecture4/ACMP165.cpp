#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000000;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n, m;
    cin >> n >> m;
    int a[n+1][m+1], dp[n+1][m+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            dp[i][j] = 0;
        }
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int step = a[i][j];
            if (step == 0) {
                continue;
            }
            if (j + step <= m) {
                dp[i][j+step] += dp[i][j];
            }
            if (i + step <= n) {
                dp[i+step][j] += dp[i][j];
            }
        }
    }

//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << "\n";
//    }
    cout << dp[n][m] << "\n";
	return 0;
}