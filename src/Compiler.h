#ifndef SIMPLEDB_COMPILER_H
#define SIMPLEDB_COMPILER_H

#include "Enums.h"
#include "InputBuffer.h"
#include "Statement.h"

PrepareResult prepareStatement(InputBuffer &inputBuffer, Statement &statement);

#endif //SIMPLEDB_COMPILER_H
