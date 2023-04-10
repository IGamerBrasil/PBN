/*
Zera todos os bits: unsigned int clear
Seta um unico bit
Resseta um unico bit
Inverte o valor de um unico bit
Retorna o resultado determinado por um unico bit
*/

unsigned int clear(unsigned int);

//setbit
// x -> valor a ser modificado
// bit -> posicao do bit valor x a ser posto em 1
unsigned int setbit(unsigned int, int);

//resetbit
// x -> valor a ser modificado
// bit -> posicao do bit valor x a ser posto em 0
unsigned int resetBit(unsigned int, int);

unsigned int invertBit(unsigned int, int);

unsigned int testBit(unsigned int, int);