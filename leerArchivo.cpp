#include "leerArchivo.h"
leerArchivo::leerArchivo(string filename){
    name=filename;
}
void leerArchivo::leer(){
    contenido.clear();
    file.open(name);
    if (file.is_open()){
        string carpeta;
        string adentro;
        if(file>>carpeta){
            contenido.push_back(carpeta);
            while(file>>adentro){
                contenido.push_back(adentro);
            }
        }
    }
    file.close();
}
vector<string> leerArchivo::getContenido(){
    return contenido;
}