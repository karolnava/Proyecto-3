#include <iostream>
#include <string>

using namespace std;

class Software : public Material{
    public:
    Software(){
        version = 0;
        so = "";
    }

    Software(int version, string so){
        this->version = version;
        this->so = so;
    }

    //Gettes
    int getVersion(){
        return this->version;
    }

    string getSo(){
        return this->so;
    }

    //Settes
    void setVersion(int version){
        this->version = version;
    }

    void setSo(string so){
        this->so = so;
    }

    //Metodos de clase Reserva
    void muestraDatos(){
        cout <<"Version: " << this->version << endl;
        cout <<"Sistema operativo: " + this->so << endl;
    }

    int cantidadDiasPrestamo(){
        return 1;
    }

    private:
    int version;
    string so;
};

