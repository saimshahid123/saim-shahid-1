#include <iostream>
#include <fstream>
#include <string>  
using namespace std;

void writeToFile(string text) {
    ofstream file("output.txt");
    file << text;
    file.close();
}

int main() {
    string input;
    getline(cin, input); 
    writeToFile(input);
    return 0;
}
