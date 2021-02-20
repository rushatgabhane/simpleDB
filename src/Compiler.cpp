#include "Compiler.h"

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