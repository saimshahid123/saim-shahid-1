#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countWordsInFile( string& filename) {
    ifstream file(filename);
    string word;
    int count = 0;
    while (file >> word) {
        count++;
    }
    file.close();
    return count;
}

int main() {
    string filename = "input.txt";
    int wordCount = countWordsInFile(filename);
    cout << wordCount << endl;
    return 0;
}
