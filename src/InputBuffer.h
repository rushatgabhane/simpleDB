#ifndef SIMPLEDB_INPUTBUFFER_H
#define SIMPLEDB_INPUTBUFFER_H

#include <string>

class InputBuffer {
public:
    std::string buffer;
    size_t inputLength = 0;
};

#endif //SIMPLEDB_INPUTBUFFER_H
