#include <string>
#include <iostream>

using namespace std;

class Fecha{
    public:
        Fecha(){
            this->dd = 0;  //this se apuntan a las variables de la  clase para que no se confundan con las variables de los argumentos
            this->mm = 0;
            this->aa = 0;
        }

        Fecha(int dd, int mm, int aa){
            this->dd = dd;
            this->mm = mm;
            this->aa = aa;
        }

        //Operators overload
        friend ostream& operator<<(ostream& out, const Fecha& arg);
        //Gettes
        int getDd()const{
            return this->dd;
        }

        int getMm()const{
            return this->mm;
        }

        int getAa()const {
            return this->aa;
        }

        //Settes
        void setDd(int dd){
            this->dd = dd;
        }

        void setMm(int mm){
            this->mm = mm;
        }

        void setAa(int aa){
            this->aa = aa;
        }

        void setFecha(int dd, int mm, int aa){
            this->dd = dd;
            this->mm = mm;
            this->aa = aa;
        }

        //Sobrecarga de operadores
        //Miembro clase > verifica si la fecha local es mayor al argumento
        bool operator > (Fecha fecha)
        {
            int fechaLocal, argumento;
            fechaLocal = (this->aa * 365) + (this->mm * 30) + (this->dd);
            argumento = (fecha.getAa() * 365) + (fecha.getMm()) + (fecha.getDd());
            if(fechaLocal > argumento){
                return true;
            }
            else{
                return false;
            }
        }

        bool operator < (Fecha fecha)
        {
            int fechaLocal, argumento;
            fechaLocal = (this->aa * 365) + (this->mm * 30) + (this->dd);
            argumento = (fecha.getAa() * 365) + (fecha.getMm() * 30) + (fecha.getDd());
            if(fechaLocal < argumento){
                return true;
            }
            else{
                return false;
            }
        }

        bool operator == (Fecha fecha)             //Sobre craga de operadores sirven para comparar las fechas
        {
            int fechaLocal, argumento;
            fechaLocal = (this->aa * 365) + (this->mm * 30) + (this->dd);
            argumento = (fecha.getAa() * 365) + (fecha.getMm() * 30) + (fecha.getDd());
            if(fechaLocal == argumento){
                return true;
            }
            else{
                return false;
            }
        }

        bool operator >= (Fecha fecha)
        {
            int fechaLocal, argumento;
            fechaLocal = (this->aa * 365) + (this->mm * 30) + (this->dd);
            argumento = (fecha.getAa() * 365) + (fecha.getMm() *30) + (fecha.getDd());
            if(fechaLocal >= argumento){
                return true;
            }
            else{
                return false;
            }
        }

        bool operator <= (Fecha fecha)
        {
            int fechaLocal, argumento;
            fechaLocal = (this->aa * 365) + (this->mm * 30) + (this->dd);
            argumento = (fecha.getAa() * 365) + (fecha.getMm() * 30) + (fecha.getDd());
            if(fechaLocal <= argumento){
                return true;
            }
            else{
                return false;
            }
        }

        int operator+(int sumar){
            int temp;
            temp = this->dd + sumar;
            return temp;
        }

        friend ostream & operator<<(ostream& out, const Fecha &c){
            out << c.getDd() << "/" + c.nombreMes(c.getMm()) + "/" << c.getAa() ;
            return out;
        }

        friend istream & operator >> (istream &in,  Fecha &c)
        {
            in >> c.dd >> c.mm >> c.aa;
            return in;
        }

        string nombreMes(int numeroMes)const{
            static string meses[12]= {"Ene", "Feb", "Mar", "Abr", "May", "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"};
            return meses[numeroMes];
        }
    private:
        int dd;
        int mm;
        int aa;
};
