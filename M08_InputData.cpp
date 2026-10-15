#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct CharacterRecord {
    int x;
    string symbol;
    int y;
};

int main() {
    ifstream inputFile("M08_InputData_CPP.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open M08_InputData_CPP.txt" << endl;
        return 1;
    }

    vector<CharacterRecord> records;
    int x, y;
    string symbol;
    int maxX = -1;
    int maxY = -1;

    // Read coordinates and find the grid dimensions.
    while (inputFile >> x >> symbol >> y) {
        if (x < 0 || y < 0) {
            cerr << "Error: Negative coordinate found." << endl;
            return 1;
        }
        records.push_back({x, symbol, y});
        if (x > maxX) maxX = x;
        if (y > maxY) maxY = y;
    }
    inputFile.close();

    if (records.empty()) {
        cerr << "Error: Input file is empty." << endl;
        return 1;
    }

    // Create a 2D array
    vector<vector<string>> grid(maxY + 1, vector<string>(maxX + 1, " "));

    for (const CharacterRecord& record : records) {
        grid[record.y][record.x] = record.symbol;
    }

    for (const vector<string>& row : grid) {
        for (const string& cell : row) {
            cout << cell;
        }
        cout << '\n';
    }

    return 0;
}
