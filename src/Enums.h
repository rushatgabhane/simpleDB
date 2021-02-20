//
// Created by rushat on 19/02/21.
//

#ifndef SIMPLEDB_ENUMS_H
#define SIMPLEDB_ENUMS_H
typedef enum {
    metaCommandSuccess,
    metaCommandUnrecognizedCommand
} MetaCommandResult;

typedef enum {
    statementSelect,
    statementInsert
} StatementType;

typedef enum {
    prepareSuccess,
    prepareUnrecognizedStatement
} PrepareResult;
#endif //SIMPLEDB_ENUMS_H
