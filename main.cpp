// C++ Recursive program for Tower of Hanoi 
#include <iostream>
using namespace std;
int moveCount = 0;

// Recursive function to solve Tower of Hanoi puzzle
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

void TOH4(int n, char source, char destination, char helper1, char helper2) {
    if (n == 0)
        return;
    if (n == 1) {
        cout << "Move disk 1 from rod " << source << " to rod " << destination << endl;
        moveCount++;
        return;
    }

    // Move top n-2 disks to helper1
    TOH4(n - 2, source, helper1, helper2, destination);

    // Move disk n-1 to helper2
    cout << "Move disk " << n - 1 << " from rod " << source << " to rod " << helper2 << endl;
    moveCount++;

    // Move disk n to destination
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
    moveCount++;

    // Move disk n-1 from helper2 to destination
    cout << "Move disk " << n - 1 << " from rod " << helper2 << " to rod " << destination << endl;
    moveCount++;

    // Move n-2 disks from helper1 to destination
    TOH4(n - 2, helper1, destination, source, helper2);
}

// Driver program 
int main() 
{ 
    int n; // Number of disks
    cout << "\n Enter the number of disks (N ≥ 5): ";
    cin >> n;

    // --- 3 Platform Output ---
    moveCount = 0;
    TOH3(n, 'A', 'C', 'B');
    cout << "Total Moves "<< moveCount << endl; // Total Move of 3 platform
    cout << "When platforms = 3 " << endl << endl;

    // --- 4 Platform Output ---
    moveCount = 0;
    TOH4(n, 'A', 'C', 'B', 'D');
    cout << "Total Moves "<< moveCount << endl; // Total Move of 4 platform
    cout << "When platforms = 4 " << endl;
    return 0; 
} 
