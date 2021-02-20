#include <iostream>
#include "src/InputBuffer.h"
#include "src/Statement.h"
#include "src/Enums.h"
#include "src/Helper.h"
#include "src/Compiler.h"
#include "src/VirtualMachine.h"
using namespace std;

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