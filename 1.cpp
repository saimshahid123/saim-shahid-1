#include <iostream>
using namespace std;

void printArray(int arr[5]) {
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    int numbers[5] = { 10, 20, 30, 40, 50 };
    printArray(numbers);
    return 0;
}
