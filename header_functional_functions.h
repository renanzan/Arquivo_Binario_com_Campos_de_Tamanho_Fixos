#ifndef HEADER_FUNCTIONAL_FUNCTIONS_H_INCLUDED
#define HEADER_FUNCTIONAL_FUNCTIONS_H_INCLUDED

FILE* openFile(const char* fileMode);
void initializeEmptyFile(const unsigned int numberOfRecords);
void addCliente();
Cliente getCliente(const FILE* file, const int numeroConta);
void writeInSeekPosition(FILE* file, Cliente cliente);

#endif // HEADER_FUNCTIONAL_FUNCTIONS_H_INCLUDED
