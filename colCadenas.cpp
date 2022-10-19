
#include "../include/colCadenas.h"
#include "../include/cadena.h"

struct _rep_colCadenas {
TCadena colCad[CANT_CADS];
int topeCol;
};

TColCadenas crearColCadenas() {
  TColCadenas colCadsNueva = new _rep_colCadenas;
  (*colCadsNueva).topeCol = -1;
  for(int i=0;i<=(CANT_CADS); i++){
  (*colCadsNueva).colCad[i]=crearCadena();
  }
  return colCadsNueva;
} 

/* en siguientes tareas
void liberarColCadenas(TColCadenas col) {
}
*/
nat cantidadColCadenas(nat pos, TColCadenas col) {
  nat numElems = cantidadEnCadena((*col).colCad[pos]); 
  return numElems;
}

bool estaEnColCadenas(nat natural, nat pos, TColCadenas col) {
  //Primero, debo ingresar a la colección, especificamente
  //a la posición pos((*col).colCad[pos]),
  //luego, debo buscar dentro de los elems de ese arreglo (TInfos)
  //un natural tal que sea el natural buscado.
   bool aux = estaEnCadena(natural, (*col).colCad[pos]);
  return aux;
}

//REVISAR
TColCadenas insertarEnColCadenas(nat natural, double real, nat pos,
                                 TColCadenas col) {

  insertarAlInicio(natural, real, (*col).colCad[pos]);
  return col;
}

TInfo infoEnColCadenas(nat natural, nat pos, TColCadenas col) {
  //Tengo que buscar dentro de la colección, 
  //dentro de la posición pos el primer elemento del tipo TInfo
  //Cuya parte natural es natural.
  // natInfo((*col).colCad[pos]), (*col).colCad[pos] es una cadena
  //dentro de la cadena tengo que acceder a los TInfo

  //infoCadena hace literalmente eso.

  return infoCadena(natural, (*col).colCad[pos]);
}

TColCadenas removerDeColCadenas(nat natural, nat pos, TColCadenas col) {
  removerDeCadena(natural, (*col).colCad[pos]);

  return col;
}
