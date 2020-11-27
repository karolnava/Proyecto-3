#include <iostream>
#include <string>

using namespace std;

class Disco : public Material{
    public:
    Disco(){
        duracion = 0;
        genero = "";
    }

    Disco(int duracion, string genero){
        this->duracion = duracion;
        this->genero = genero;
    }

    //Gettes
    int getDuracion(){
        return this->duracion;
    }

    string getGenero(){
        return this->genero;
    }

    //Settes
    void setDuracion(int duracion){
        this->duracion = duracion;
    }

    void setGenero(string genero){
        this->genero = genero;
    }

    //Metodos de clase Reserva
    void muestraDatos(){
        cout <<"Duracion: " << this->duracion << endl;
        cout <<"Genero: " + this->genero << endl;
    }

    int cantidadDiasPrestamo(){
        return 3;
    }

    private:
    int duracion;
    string genero;
};

