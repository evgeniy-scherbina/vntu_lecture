#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n, k;
    cin >> n >> k;
    int state[2*k+1], nextState[2*k+1];
    for (int i=0; i<=2*k; i++) {
        state[i] = nextState[i] = 0;
    }
    state[k] = 1;

    for (int step = 1; step <= k; step++) {
        for (int i = 0; i <= 2 * k; i++) {
            if (i - 1 >= 0 && !(i - 1 == k + n && step != k)) {
                nextState[i-1] += state[i];
            }
            if (i + 1 <= 2 * k && !(i + 1 == k + n && step != k)) {
                nextState[i+1] += state[i];
            }
        }

        for (int i = 0; i <= 2 * k; i++) {
            state[i] = nextState[i];
            nextState[i] = 0;
        }
    }
//    for (int i=k-3; i<=k+3; i++) {
//        cout << state[i] << " ";
//    }
//    cout << "\n";
    cout << state[k+n];
	return 0;
}