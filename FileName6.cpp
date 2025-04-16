#include <iostream>
using namespace std;

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int numbers[5] = { 12, 45, 7, 89, 23 };
    int maximum = findMax(numbers, 5);
    cout << maximum << endl;
    return 0;
}
