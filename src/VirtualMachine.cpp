#include "VirtualMachine.h"

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

MetaCommandResult executeMetaCommand(InputBuffer inputBuffer) {
    if (true) {
        return metaCommandSuccess;
    }
    return metaCommandUnrecognizedCommand;
}