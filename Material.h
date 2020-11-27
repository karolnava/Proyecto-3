#include <iostream>
#include <string>
class Disco;
class Software;
class Libro;

using namespace std;

class Material{
    public:
    Material(){
        this->idMaterial = 0;
        this->titulo = "";
    }

    Material (int idMaterial, string titulo){
        this->idMaterial = idMaterial;
        this->titulo = titulo;
    }

    //Gettes, Metodos de acceso
    int getIdMaterial(){
        return this->idMaterial;
    }

    string getTitulo(){
        return this->titulo;
    }

    //Settes, Metodos de modificacion
    void setIdMaterial(int idMaterial){
        this->idMaterial = idMaterial;
    }

    void setTitulo(string titulo){
        this->titulo = titulo;
    }

    virtual void muestraDatos() {};
    virtual int cantidadDiasPrestamo() {};

    private:
    int idMaterial;
    string titulo;

};
