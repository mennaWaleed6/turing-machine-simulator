#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
void takingAction(const char descriptionLine[], char action,std::string& tape,int headerPosition,char currentInput,char currentState,bool terminate){
}
int main()
{
    //setting head position zero by not adding left mark in tape and not adding it in machine symbols
    int headerPosition =0;
    char stateNumber;
    int machineSymbolNumber;
    char currentState;
    string tape;

    cout << "Enter state number: ";
    cin >> stateNumber;

    cout << "Enter machine symbol number: ";
    cin >> machineSymbolNumber;

    vector<char> machineSymbols(machineSymbolNumber);
    cout << "Enter machine symbols: ";
    for (int i = 0; i < machineSymbolNumber; ++i) {
        cin >> machineSymbols[i];
    }

    cin.ignore();

    cout << "Enter initial state: ";
    cin >> currentState;

    cin.ignore();
    cout << "Enter tape: ";
    cin >> tape;

    cin.ignore();

    int matrixSize =((int) stateNumber )* machineSymbolNumber;
    vector<vector<string>> turingDescriptionMatrix(matrixSize, vector<string>(5));

    cout << "Enter machine description each line separately like format '0,a,1,b,R' :" << endl;
    for (int i = 0; i < matrixSize; ++i) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        string token;
        int tokenIndex = 0;

        while (getline(ss, token, ',') && tokenIndex < 5) {
            turingDescriptionMatrix[i][tokenIndex++] = token;
        }
    }

    // Display the matrix to verify input
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << turingDescriptionMatrix[i][j] << " ";
        }
        cout << endl;
    }
    char currentInput=tape[headerPosition];
    bool terminate=false;
    while(!terminate){

        for (int i = 0; i < matrixSize; ++i) {
        if (turingDescriptionMatrix[i][0] == currentState && turingDescriptionMatrix[i][1] == currentInput) {
             takingAction(turingDescriptionMatrix[i],turingDescriptionMatrix[i][4],tape,headerPosition,currentInput,currentState,terminate);

            break;
        }
    }
    }

    return 0;
}
