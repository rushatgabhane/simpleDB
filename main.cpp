#include <iostream>
#include "src/InputBuffer.h"
#include "src/Statement.h"
#include "src/Enums.h"
using namespace std;

PrepareResult prepareStatement(InputBuffer &inputBuffer, Statement &statement) {
    if(inputBuffer.buffer == "select") {
        statement.type = statementSelect;
        return prepareSuccess;
    }
    if(inputBuffer.buffer == "insert") {
        statement.type = statementInsert;
        return prepareSuccess;
    }
    return prepareUnrecognizedStatement;
}

string getFirstWord(string &buffer) {
    string firstWord;
    for(int i=0; i<buffer.size() && buffer[i] != ' '; i++) {
        firstWord += buffer[i];
    }
    return firstWord;
}

void executeStatement(Statement &statement) {
    switch (statement.type){
        case statementSelect:
            cout << "select" << endl;
            break;
        case statementInsert:
            cout << "insert" << endl;
            break;
    }
}

void printPrompt() {
    cout << "db> ";
}

void readInput(InputBuffer &inputBuffer) {
    getline(cin, inputBuffer.buffer);
    if(inputBuffer.buffer.size() == 0) {
        printPrompt();
        readInput(inputBuffer);
    }
}

MetaCommandResult executeMetaCommand(InputBuffer inputBuffer) {
    if (true) {
        return metaCommandSuccess;
    }
    return metaCommandUnrecognizedCommand;
}

int main() {
    InputBuffer inputBuffer;
    while(true) {
        printPrompt();
        readInput(inputBuffer);

        if(inputBuffer.buffer == ".exit") {
            cout << "Bye!";
            return 0;
        }
        if(inputBuffer.buffer[0] == '.') {
            switch (executeMetaCommand(inputBuffer)) {
                case (metaCommandSuccess):
                    continue;
                case (metaCommandUnrecognizedCommand):
                    cout << "Unrecognized command " << inputBuffer.buffer << endl;
                    continue;
            }

        }
        Statement statement;
        switch (prepareStatement(inputBuffer, statement)) {
            case prepareSuccess:
                break;
            case prepareUnrecognizedStatement:
                cout << "Unrecognized keyword: " << getFirstWord(inputBuffer.buffer) << endl;
                continue;
        }
        executeStatement(statement);
    }
    return 0;
}