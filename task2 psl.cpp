#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;
const int MAX_LEN = 50;

char names[MAX][MAX_LEN];
char teams[MAX][MAX_LEN];
char roles[MAX][MAX_LEN];
int runs[MAX];
int wickets[MAX];
int totalPlayers = 0;

void saveToFile() {
    ofstream file("players.txt");
    for (int i = 0; i < totalPlayers; i++) {
        file << names[i] << "," << teams[i] << "," << roles[i] << "," << runs[i] << "," << wickets[i] << endl;
    }
    file.close();
}

void addPlayer() {
    if (totalPlayers >= MAX) {
        cout << "Player limit reached.\n";
        return;
    }

    cout << "Enter Player Name: ";
    cin.ignore();
    cin.getline(names[totalPlayers], MAX_LEN);

    cout << "Enter Team Name: ";
    cin.getline(teams[totalPlayers], MAX_LEN);

    cout << "Enter Role (batsman/bowler/all-rounder): ";
    cin.getline(roles[totalPlayers], MAX_LEN);

    cout << "Enter Total Runs: ";
    cin >> runs[totalPlayers];

    cout << "Enter Total Wickets: ";
    cin >> wickets[totalPlayers];

    totalPlayers++;
    saveToFile();
    cout << "Player added successfully.\n";
}

void viewAll() {
    for (int i = 0; i < totalPlayers; i++) {
        cout << "\nName: " << names[i];
        cout << "\nTeam: " << teams[i];
        cout << "\nRole: " << roles[i];
        cout << "\nRuns: " << runs[i];
        cout << "\nWickets: " << wickets[i] << "\n";
    }
}

bool isMatch(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;
        i++;
    }
    return a[i] == '\0' && b[i] == '\0';
}

void searchPlayer() {
    char input[MAX_LEN];
    cout << "Enter Player Name or Team: ";
    cin.ignore();
    cin.getline(input, MAX_LEN);

    bool found = false;
    for (int i = 0; i < totalPlayers; i++) {
        if (isMatch(input, names[i]) || isMatch(input, teams[i])) {
            cout << "Name: " << names[i] << endl;;
            cout << "Team: " << teams[i] << endl;
            cout << "Role: " << roles[i]<<endl;
            cout << "Runs: " << runs[i];
            cout << "Wickets: " << wickets[i] << "\n";
            found = true;
        }
    }
    if (!found) cout << "No record found.\n";
}

void updatePlayer() {
    char input[MAX_LEN];
    cout << "Enter Player Name to Update: ";
    cin.ignore();
    cin.getline(input, MAX_LEN);

    for (int i = 0; i < totalPlayers; i++) {
        if (isMatch(input, names[i])) {
            cout << "Enter New Runs: ";
            cin >> runs[i];
            cout << "Enter New Wickets: ";
            cin >> wickets[i];
            saveToFile();
            cout << "Player updated successfully.\n";
            return;
        }
    }
    cout << "Player not found.\n";
}

void deletePlayer() {
    char input[MAX_LEN];
    cout << "Enter Player Name to Delete: ";
    cin.ignore();
    cin.getline(input, MAX_LEN);

    for (int i = 0; i < totalPlayers; i++) {
        if (isMatch(input, names[i])) {
            for (int j = i; j < totalPlayers - 1; j++) {
                for (int k = 0; k < MAX_LEN; k++) {
                    names[j][k] = names[j + 1][k];
                    teams[j][k] = teams[j + 1][k];
                    roles[j][k] = roles[j + 1][k];
                }
                runs[j] = runs[j + 1];
                wickets[j] = wickets[j + 1];
            }
            totalPlayers--;
            saveToFile();
            cout << "Player deleted successfully.\n";
            return;
        }
    }
    cout << "Player not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- PSL Management System ---\n";
        cout << "1. Add Player\n";
        cout << "2. View All Players\n";
        cout << "3. Search Player\n";
        cout << "4. Update Player\n";
        cout << "5. Delete Player\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addPlayer(); break;
        case 2: viewAll(); break;
        case 3: searchPlayer(); break;
        case 4: updatePlayer(); break;
        case 5: deletePlayer(); break;
        case 6: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
