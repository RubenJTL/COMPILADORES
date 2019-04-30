#include "Utils.h"
#include "tokens.h"
#include <iostream>

using namespace std;


int main(int argc, char **argv){
  if (argc!=2) {
    printf("Falta <Archivo de Lectura>\n");
    return 0;
  }

  Tabla Simbol_Table;
  BufferSS bufferS;
  GenerarTable(Simbol_Table);
  leerFile(argv[1],bufferS);
  //preprocesar(bufferS);
  //string token;
  //bool encontro;
  /*for (size_t i = 0; i < buffer.size(); i++) {
    Get_Token(buffer[i],encontro);
    insertTable(buffer[i],encontro);
  }*/
  mostrarTable(Simbol_Table);
  mostrarBuffer(bufferS);
  Get_Token(bufferS,Simbol_Table);
  mostrarBuffer(bufferS);
  mostrarTable(Simbol_Table);
  mostrarErroresLexicos();
  return 0;
}
