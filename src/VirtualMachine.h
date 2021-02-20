
#ifndef SIMPLEDB_VIRTUALMACHINE_H
#define SIMPLEDB_VIRTUALMACHINE_H

#include "iostream"
#include "Statement.h"
#include "InputBuffer.h"
using namespace std;

void executeStatement(Statement &statement);
MetaCommandResult executeMetaCommand(InputBuffer inputBuffer);

#endif //SIMPLEDB_VIRTUALMACHINE_H
