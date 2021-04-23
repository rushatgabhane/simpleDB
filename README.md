## SimpleDB
Learning project. Database based on SQLite architecture.

# Project structure
A query goes through a chain of components in order to retrieve or modify data.
## Frontend
The input to the front-end is a SQL query.
- Tokenizer
- Parser
- Code generator

Output is sqlite virtual machine bytecode.

## Backend
- Virtual machine
- B-tree
- Pager
- OS interface

## Build the project
 - #### Create build directory `mkdir build && cd build`
 - #### Then run cmake and point to the parent directory `cmake ..`
 - #### Finally run make `make`

## Run simpleDB
`./simpleDB`

