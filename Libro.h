#include <iostream>
#include <string>

using namespace std;

class Libro : public Material{
    public:
        Libro(){
            this->numPag = 0;
            this->autor = "";
        }

        Libro(int numPag, string autor){
            this->numPag = numPag;
            this->autor = autor;
        }

        //Gettes
        int getNumPag(){
            return this->numPag;
        }

        string getAutor(){
            return this->autor;
        }

        //Settes
        void setNumPag(int numPag){
            this->numPag = numPag;
        }

        void setAutor(string autor){
            this->autor = autor;
        }

        //Metodos de clase Reserva
        void muestraDatos(){
            cout <<"Numero de paginas: " << this->numPag << endl;
            cout <<"Autor: " + this->autor << endl;
        }

        int cantidadDiasPrestamo(){
            return 5;
        }

    private:
        int numPag;
        string autor;
};

