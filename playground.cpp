#include <iostream>

using namespace std;

void printArray(int n) {
    if (n == 0) {
        cout << n;
        return;
    }
    printArray(n - 1);
    cout << ", " << n;
}

void printBackward(int n) {
    if (n <= 0) {
        cout << n;
        return;
    }
    cout << n << " ";
    printBackward(n - 5);
}

void printForward(int n ) {
    if (n <= 0)
        return;
    
    printForward(n - 5);
    cout << " " << n;
}

void printPattern(int n) {
    printBackward(n);
    printForward(n);
}
int main() {
    printPattern(14);
    return 0;
}