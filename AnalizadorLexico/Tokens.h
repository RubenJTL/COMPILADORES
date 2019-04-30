#ifndef TOKENS_H // include guard
#define TOKENS_H
#include "Utils.h"


bool Identificador(string palabra);
bool Numero(string palabra);
bool Numero_Real(string palabra);
void Get_Token(BufferSS &buffer,Tabla &Simbol_Table);

string Tokenize(string palabra,bool &encontro,Tabla & Simbol_Table);

void Get_Token(BufferSS &buffer,Tabla &Simbol_Table){
  bool encontro;
  for (size_t iterator = 0; iterator < buffer.size(); iterator++) {
  //  cout<<buffer[iterator].valor<<" "<<Tokenize(buffer[iterator].valor,encontro,Simbol_Table)<<endl;
    string token=Tokenize(buffer[iterator].valor,encontro,Simbol_Table);
    buffer[iterator].token=token;
    if ((int)token[0]!=64) {
      insertTable(buffer[iterator],encontro,Simbol_Table);
    }else{
      ErrorLexico tmpErr;
      tmpErr.lexema=buffer[iterator].valor;
      tmpErr.posicion.x=buffer[iterator].posicion.x;
      tmpErr.posicion.y=buffer[iterator].posicion.y;
      ErroresLex.push_back(tmpErr);
    }

    //insertTable(buffer[iterator],encontro,Simbol_Table);

  }
}

string Tokenize(string palabra,bool &encontro,Tabla & Simbol_Table){
  string token="";
  encontro=false;
  if (InSimbolTable(palabra,token,Simbol_Table)) {
    encontro=true;
    return token;
  }
  if (Identificador(palabra)) {
    return "Id";
  } else if (Numero(palabra)){
    return "Num";
  }else if (Numero_Real(palabra)){
    return "Num_Real";
  }else{
    return "@otra_cosa";
  }
}



bool Identificador(string palabra){
  if ((int)palabra[0]==95 or ((int)palabra[0]>=65 && (int)palabra[0]<=90) or ((int)palabra[0]>=97 && (int)palabra[0]<=122)){
    for (size_t caracter = 1; caracter < palabra.length(); caracter++) {
      if ((int)palabra[caracter]==95 or ((int)palabra[caracter]>=65 && (int)palabra[caracter]<=90) or ((int)palabra[caracter]>=97 && (int)palabra[caracter]<=122) or ((int)palabra[caracter]>=48 && (int)palabra[caracter]<=57)) {
      }else{
        return false;
      }
    }
    return true;
  }
  return false;
}

bool Numero(string palabra){
  if((int)palabra[0]>=48 && (int)palabra[0]<=57){
    for (size_t caracter = 1; caracter <  palabra.length(); caracter++) {
      if((int)palabra[caracter]>=48 && (int)palabra[caracter]<=57){
      }else{
        return false;
      }
    }
    return true;
  }
  return false;
}

bool Numero_Real(string palabra){
  bool punto=false;
  if((int)palabra[0]>=48 && (int)palabra[0]<=57){
    for (size_t caracter = 1; caracter <  palabra.length(); caracter++) {
      if (punto==false) {
        if((int)palabra[caracter]>=48 && (int)palabra[caracter]<=57){

        }else if ((int)palabra[caracter]==46){
          punto=true;
        }else{
          return false;
        }
      }else if(punto==true){
        if((int)palabra[caracter]>=48 && (int)palabra[caracter]<=57){

        }else{
          return false;
        }
      }
    }
    return true;
  }
  return false;
}
#endif
