#include <iostream>
using namespace std;

void copyArray(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

int main() {
    int original[5] = { 10, 20, 30, 40, 50 };
    int copied[5];

    copyArray(original, copied, 5);

    for (int i = 0; i < 5; i++) {
        cout << copied[i] << " ";
    }
    cout << endl;

    return 0;
}
