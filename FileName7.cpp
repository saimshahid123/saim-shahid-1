#include <iostream>
using namespace std;

void reverseString( char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    for (int i = length - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << endl;
}

int main() {
    char input[100];
    cin.getline(input, 100);
    reverseString(input);
    return 0;
}
