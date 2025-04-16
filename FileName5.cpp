#include <iostream>
using namespace std;

void printCharacters(const char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        cout << str[i] << endl;
    }
}

int main() {
    char input[100];
    cin.getline(input, 100);
    printCharacters(input);
    return 0;
}
