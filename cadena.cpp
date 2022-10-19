
#include "../include/cadena.h"

// los elementos se mantienen entre 0 y cantidad - 1, incluidos
struct _rep_cadena {
  int tope;
  TInfo arr[L]; //Pues para pedir almacenar entre 0 y L-1 preciso L espacios
};
//Si quiero que la cadena tenga 0 elementos, el tope será -1.

TCadena crearCadena() {
  TCadena cadNueva = new _rep_cadena;
  (*cadNueva).tope = -1; 
  //El tope es -1 pues a mi lo que me interesa con el tope es indicar
  //la posición del ultimo elemento, dentro del struct. 

  return cadNueva;
}

/* en siguientes tareas
void liberarCadena(TCadena cad) {
}
*/  

nat cantidadEnCadena(TCadena cad) {
  return (*cad).tope+1;
}

//El error estaba en que el tope me marca la posición del ultimo elem
//la posición del ultimo elemento es la cantidad +1
bool estaEnCadena(nat natural, TCadena cad) {
  int i=0;
  bool pertenece;
  if(cantidadEnCadena(cad) != 0) {
    while ((i < (*cad).tope+1) && (natInfo((*cad).arr[i]) != natural))
      i++;
    pertenece = (i!=(*cad).tope+1);
  }
  else {
    pertenece = cantidadEnCadena(cad); //Estoy acá solo si la cant es 0 (0 = false)
  }

  return pertenece;
}


TCadena insertarAlInicio(nat natural, double real, TCadena cad) {
  (*cad).tope++;    
  
  // for(int i=0; i<=(*cad).tope; i++){
  // (*cad).arr[(*cad).tope-i+1] = (*cad).arr[(*cad).tope-i];
  // }
  for(int i=(*cad).tope; i>0;i--){
    (*cad).arr[i]= (*cad).arr[i-1];
  }
  (*cad).arr[0]= crearInfo(natural, real);
  return cad;
}

TInfo infoCadena(nat natural, TCadena cad) {
  int i=0;
  while ((i!=(*cad).tope) && (natInfo((*cad).arr[i])!= natural)){
    i++;
  }
  return (*cad).arr[i];
}

//EN MANTENIMIENTO
TCadena removerDeCadena(nat natural, TCadena cad) {
  int i = 0;
  
  while ((i <(*cad).tope) && (natInfo((*cad).arr[i]) != natural))
  {
    i++;
  }

  for(int j=i; j<=(*cad).tope-1 ;j++){
    (*cad).arr[j]=(*cad).arr[j+1];
  }
  (*cad).tope--;

  return cad;
}
//


void imprimirCadena(TCadena cad) {
  if(cantidadEnCadena(cad)!=0){
  for(int i=0; i<(*cad).tope+1; i++){
    printf("(%d,%.2f)", natInfo((*cad).arr[i]), realInfo((*cad).arr[i]));
  }
  printf("\n");
  }
  else
  printf("\n");
}
