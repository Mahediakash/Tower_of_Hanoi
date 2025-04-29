#include <iostream>
#include <cmath>
using namespace std;

int moveCount = 0; // For Finding Total Move Count

// ----------- Using 3 Platform -----------
void TOH3(int n, char source, char destination, char helper) {
    if (n == 0) return;
    if (n == 1) {
        cout << "Move container " << n << " from " << source << " to " << destination << endl;
        moveCount++;
        return;
    }
    TOH3(n - 1, source, helper, destination);
    cout << "Move container " << n << " from " << source << " to " << destination << endl;
    moveCount++;
    TOH3(n - 1, helper, destination, source);
}

// ----------- Using 4 Platform -----------
void TOH4(int n, char source, char destination, char helper1, char helper2) {
    if (n == 0) return;
    if (n == 1) {
        cout << "Move container " << n << " from " << source << " to " << destination << endl;
        moveCount++;
        return;
    }

    int k = n - int(sqrt(2 * n + 1)) + 1;
    TOH4(k, source, helper1, helper2, destination);
    TOH3(n - k, source, destination, helper2);
    TOH4(k, helper1, destination, source, helper2);
}

// ----------- Main Section -----------
int main() {
    int N;
    cout << "Enter number of containers (N >= 5): ";
    cin >> N;

    // --- 3 Platform Output ---
    moveCount = 0;
    TOH3(N, 'A', 'C', 'B');
    cout << "Total Moves "<< moveCount << endl; // Total Move of 3 platform
    cout << "When platforms = 3 " << endl << endl;

    // --- 4 Platform Output ---
    moveCount = 0;
    TOH4(N, 'A', 'C', 'B', 'D');
    cout << "Total Moves "<< moveCount << endl; // Total Move of 4 platform
    cout << "When platforms = 4 " << endl;

    return 0;
}
