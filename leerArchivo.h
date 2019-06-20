#ifndef LEERARCHIVO_H
#define LEERARCHIVO_H
#include <fstream>
#include <string>
using std::string;
using std::ifstream;
#include <vector>
using std::vector;
class leerArchivo{
    private:
        ifstream file;
        string name;
        vector<string>contenido;
    public:
        vector<string> getContenido();
        leerArchivo(string);
        void leer();
};
#endif