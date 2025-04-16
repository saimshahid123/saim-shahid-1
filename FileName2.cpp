#include <iostream>
using namespace std;

int sumArray(int arr[5]) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int numbers[5] = { 1, 2, 3, 4, 5 };
    int result = sumArray(numbers);
    cout << result << endl;
    return 0;
}
