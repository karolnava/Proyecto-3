#include <iostream>
#include "Fecha.h"

using namespace std;

class Reserva{
    public:
        Reserva(){
            this->idMaterial = 0;
            this->idCliente = 0;
            fechaReservacion = Fecha();
        }

        Reserva(int idMaterial, int idCliente, Fecha fechaReservacion){
            this->idMaterial = idMaterial;
            this->idCliente = idCliente;
            this->fechaReservacion = fechaReservacion;
        }

        //Gettes, metodos de acceso
        int getIdMaterial(){
            return this->idMaterial;
        }

        int getIdCliente(){
            return this->idCliente;
        }

        Fecha getFechaReservacion(){
            return this->fechaReservacion;
        }

        //Settes, metodos de modificacion
        void setIdMaterial(int idMaterial){
            this->idMaterial = idMaterial;
        }

        void setIdCliente(int idCliente){
            this->idCliente = idCliente;
        }

        void setFechaReservacion(Fecha fecha){
            this->fechaReservacion = fecha;
        }

        Fecha calculaFechaFinReserva(int cantidadDiasP){
            Fecha fecha;
            fecha.setDd(fechaReservacion.getDd() + cantidadDiasP);
            if(fechaReservacion.getDd() + cantidadDiasP > 30){
                fecha.setMm(fechaReservacion.getMm() + 1);
            }
            else{
                fecha.setMm(fechaReservacion.getMm());
                fecha.setAa(fechaReservacion.getAa());
            }

            return fecha;
        }

    private:
        int idMaterial;
        int idCliente;
        Fecha fechaReservacion;
};

