#ifndef UTILS_H // include guard
#define UTILS_H

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

/////ESTRUCTURAS////////
struct Pos{
  int x;
  int y;
};

struct StringString{
  string token="";
  string valor="";
  Pos posicion;
};

struct Atributos{
  string token="";
  string valor="";
  int repeticiones=0;
  vector<Pos>posicion;
};

struct ErrorLexico{
  string mensaje="Error en el lexema ";
  string lexema="";
  Pos posicion;
};

typedef map<string,Atributos> Tabla;
typedef vector<StringString> BufferSS;
typedef vector<ErrorLexico> ErroresLexicos;


ErroresLexicos ErroresLex;

/////ERROR LEXICO/////
int mostrarErroresLexicos(){
  for (size_t iter = 0; iter < ErroresLex.size(); iter++) {
    cout<<ErroresLex[iter].mensaje<< ErroresLex[iter].lexema<<" posicion ("<<ErroresLex[iter].posicion.x<<","<<ErroresLex[iter].posicion.y<<")\n";
  }
}


////////FUNCIONES TABLE//////////
int GenerarTable(Tabla & Simbol_Table);
int mostrarTable(Tabla & Simbol_Table);
int mostrarAtributos(Atributos & Atrib);
bool InSimbolTable(string palabra,string &token,Tabla &Simbol_Table);
int insertTable(StringString & atrib,bool &encontro,Tabla &Simbol_Table);

///////FUCIONES BUFFER/////////
bool Skip_or_Operator(int ascii);
int leerFile(string file, BufferSS & buffer);
int mostrarBuffer(BufferSS & buffer);



////////FUNCIONES TABLE//////////

int mostrarAtributos(Atributos & Atrib){
  if (Atrib.token.length()!=0) {
    cout<<Atrib.token<<"\t | ";
  }
  if (Atrib.valor.length()!=0) {
    cout<<Atrib.valor<<"\t | ";
  }
  if (Atrib.repeticiones!=0) {
    cout<<Atrib.repeticiones<<"\t | ";
  }
  if ((Atrib.posicion).size()!=0) {
    for (size_t iter = 0; iter < (Atrib.posicion).size(); iter++) {
      cout<<"("<<Atrib.posicion[iter].x<<","<<Atrib.posicion[iter].y<<") ";
    }
  }
}
int GenerarTable(Tabla & Simbol_Table){
  Atributos Atrib_tmp;
  string palabra_Reservada="";
  for (size_t iter = 38; iter < 46; iter++) {
    palabra_Reservada+=(char)iter;
    Atrib_tmp.token=palabra_Reservada;
    Atrib_tmp.valor=palabra_Reservada;
    Simbol_Table[palabra_Reservada]=Atrib_tmp;
    palabra_Reservada="";
  }
  for (size_t iter = 58; iter < 63; iter++) {
    palabra_Reservada+=(char)iter;
    Atrib_tmp.token=palabra_Reservada;
    Atrib_tmp.valor=palabra_Reservada;
    Simbol_Table[palabra_Reservada]=Atrib_tmp;
    palabra_Reservada="";
  }
  palabra_Reservada+=(char)47;
  Atrib_tmp.token=palabra_Reservada;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;
  palabra_Reservada="";

  for (size_t iter = 123; iter < 126; iter++) {
    palabra_Reservada+=(char)iter;
    Atrib_tmp.token=palabra_Reservada;
    Atrib_tmp.valor=palabra_Reservada;
    Simbol_Table[palabra_Reservada]=Atrib_tmp;
    palabra_Reservada="";
  }

  Atrib_tmp.token=palabra_Reservada;
  palabra_Reservada=(char)93;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;
  palabra_Reservada=(char)91;
  Atrib_tmp.token=palabra_Reservada;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;

  palabra_Reservada="if";
  Atrib_tmp.token=palabra_Reservada;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;

  palabra_Reservada="else";
  Atrib_tmp.token=palabra_Reservada;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;

  palabra_Reservada="while";
  Atrib_tmp.token=palabra_Reservada;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;

  palabra_Reservada="for";
  Atrib_tmp.token=palabra_Reservada;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;

  palabra_Reservada="==";
  Atrib_tmp.token=palabra_Reservada;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;

  palabra_Reservada="<=";
  Atrib_tmp.token=palabra_Reservada;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;

  palabra_Reservada=">=";
  Atrib_tmp.token=palabra_Reservada;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;

  palabra_Reservada=(char)34;
  Atrib_tmp.token=palabra_Reservada;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;

  palabra_Reservada="and";
  Atrib_tmp.token=palabra_Reservada;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;

  palabra_Reservada="or";
  Atrib_tmp.token=palabra_Reservada;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;

  palabra_Reservada="int";
  Atrib_tmp.token=palabra_Reservada;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;

  palabra_Reservada="char";
  Atrib_tmp.token=palabra_Reservada;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;

  palabra_Reservada="float";
  Atrib_tmp.token=palabra_Reservada;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;

  palabra_Reservada="double";
  Atrib_tmp.token=palabra_Reservada;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;

  palabra_Reservada="bool";
  Atrib_tmp.token=palabra_Reservada;
  Atrib_tmp.valor=palabra_Reservada;
  Simbol_Table[palabra_Reservada]=Atrib_tmp;

}
bool InSimbolTable(string palabra,string &token,Tabla &Simbol_Table){
  Tabla::iterator it;
  it = Simbol_Table.find(palabra);
  if (it != Simbol_Table.end()){
    token=it->second.token;
    return true;
  }
  return false;
}
int insertTable(StringString &atrib,bool &encontro,Tabla &Simbol_Table){
  if(encontro){
    Simbol_Table.find(atrib.valor)->second.repeticiones++;
    Simbol_Table.find(atrib.valor)->second.posicion.push_back(atrib.posicion);
  }else{
    Atributos tmp;
    tmp.token=atrib.token;
    tmp.valor=atrib.valor;
    tmp.posicion.push_back(atrib.posicion);
    tmp.repeticiones=1;
    Simbol_Table[atrib.valor]=tmp;
  }
}


///////FUCIONES BUFFER/////////
bool Skip_or_Operator(int ascii){
  if ((ascii>=0 and ascii<=45 ) or ascii==47  or (ascii>=58 and ascii<=63 ) or (ascii>=123 and ascii<=126) or (ascii==91) or (ascii==93)) {
    return true;
  }
  return false;
}
int leerFile(string file, BufferSS & buffer){
  ifstream f(file);
  int fila=0, columna=0,tmpco;
  string line;
  string palabra="";
  StringString tmp;
  bool comentarioON=false;
  while (!f.eof()) {
    getline(f,line);
    for (size_t caracter = 0; caracter < line.length(); caracter++) {
      //cout<<columna<<endl;
      if ((int)line[caracter]==47 and (int)line[caracter+1]==42){
          comentarioON=true;
      }

      if(!comentarioON){
        if ((int)line[caracter]==47 and (int)line[caracter+1]==47){
          caracter=line.length();
        }else if((int)line[caracter]==47 and (int)line[caracter+1]==42){
          comentarioON=true;
        }else{
          if (!(Skip_or_Operator( (int)line[caracter] ))){
            if (palabra.length()==0) {
              tmpco=columna;
            }
            palabra+=line[caracter];

          }else{
            if (palabra.length()!=0) {
              tmp.valor=palabra;
              tmp.posicion.x=tmpco;
              tmp.posicion.y=fila;
              buffer.push_back(tmp);
              palabra="";
            }

            palabra="";
            if ((int)line[caracter]>32) {
              if ((int)line[caracter]>=60 && (int)line[caracter]<=62){
                if((int)line[caracter+1]==61){
                  palabra+=line[caracter+1];
                  caracter++;
                }
              }

              palabra+=line[caracter];
              tmp.valor=palabra;
              tmp.posicion.x=columna;
              tmp.posicion.y=fila;
              buffer.push_back(tmp);
              palabra="";
            }
          }
        }
      }
      if((int)line[caracter]==42 and (int)line[caracter+1]==47){
          comentarioON=false;
          caracter++;
      }
      columna++;
    }
    if (palabra.length()!=0) {
      tmp.valor=palabra;
      tmp.posicion.x=tmpco;
      tmp.posicion.y=fila;
      buffer.push_back(tmp);
    }
    palabra="";
    fila++;
    columna=0;
  }
}

int mostrarBuffer(BufferSS & buffer){
  for (size_t iter = 0; iter < buffer.size(); iter++) {
    cout<<"<"<<buffer[iter].token<<">"<<"<"<<buffer[iter].valor<<">"<<"("<<buffer[iter].posicion.x<<","<<buffer[iter].posicion.y<<")"<<" || ";
  }
  cout<<"\n";
}
int mostrarTable(Tabla & Simbol_Table){
  for (auto x : Simbol_Table){
    mostrarAtributos(x.second);
    cout<<endl;
  }
}

#endif
