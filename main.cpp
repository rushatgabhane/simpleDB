#include <iostream>
#include "src/helpers/Enums.h"
#include "src/helpers/Util.h"

using namespace std;

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255
#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

class InputBuffer {
public:
    string buffer;
    size_t inputLength;
};

class Statement {
public:
    StatementType type;
    Row rowToInsert; 
};


class Row {
    unsigned int id;
    string username(COLUMN_USERNAME_SIZE);
    string email(COLUMN_EMAIL_SIZE);
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

MetaCommandResult executeMetaCommand(InputBuffer &inputBuffer) {
    if (inputBuffer.buffer == ".exit") {
        cout << "Bye! 👋" << endl;
        exit(EXIT_SUCCESS);
    } else {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}

PrepareResult prepareStatement(InputBuffer &inputBuffer, Statement &statement) {
    if (getFirstWord(inputBuffer.buffer) == "insert") {
        statement.type = STATEMENT_INSERT;
        string token;
        istringstream iss(inputBuffer.buffer);
        iss >> token; // skip first word

        iss >> token;
        statement.rowToInsert.id = token;

        iss >> token;
        statement.rowToInsert.username = token;

        iss >> token;
        statement.rowToInsert.email = token;

        if (args_assigned < 3) {
            return PREPARE_SYNTAX_ERROR;
        }
        return PREPARE_SUCCESS;
    }
    if (inputBuffer.buffer == "select") {
        statement.type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }
    return PREPARE_UNRECOGNIZED_STATEMENT;
}

void executeStatement(Statement &statement) {
  switch (statement.type) {
    case (STATEMENT_INSERT):
        printf("This is where we would do an insert.\n");
        break;
    case (STATEMENT_SELECT):
        printf("This is where we would do a select.\n");
        break;
  }
}


int main() {
    InputBuffer inputBuffer;
    while (true) {
        printPrompt();
        readInput(inputBuffer);
        if(inputBuffer.buffer[0] == '.') {
            switch (executeMetaCommand(inputBuffer)) {
                case (META_COMMAND_SUCCESS):
                    continue;
                case (META_COMMAND_UNRECOGNIZED_COMMAND):
                    cout << "Unrecognized command " << inputBuffer.buffer << endl;
                    continue;
            }

        }
        Statement statement;
        switch (prepareStatement(inputBuffer, statement)) {
            case PREPARE_SUCCESS:
                break;
            case PREPARE_UNRECOGNIZED_STATEMENT:
                cout << "Unrecognized keyword: " << getFirstWord(inputBuffer.buffer) << endl;
                continue;
        }
        executeStatement(statement);
    }
}