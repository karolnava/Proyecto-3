#include <iostream>
#include <fstream>
#include "Material.h"
#include "Software.h"
#include "Libro.h"
#include "Disco.h"
#include <string>
#include <sstream>
#include "Reserva.h"

using namespace std;
//declaracion de arreglos de punteros de objetos
Material *materiales[30];
Reserva *reservaciones[60];
//Variables de instancia o globales
int cantMateriales = 0, cantReservaciones = 0, reservacionesIniciales;
//Metodos para consulta de reservaciones por fecha
void consultaReservacionesFecha(){
    if(cantReservaciones == 0){//Si no hay reservaciones no muestra nada
            cout <<"No hay reservaciones!"<<endl;
    }
    else{//Si hay una o mas consultas pide la fecha
            int aa, mm, dd;
            Fecha fechaIF;
            cout <<"Ingresa la fecha a continuacion: "<<endl;
            cout <<"Dia (dd):"<<endl;
            cin >> dd;
            cout <<"Mes (mm):"<<endl;
            cin >> mm;
            cout <<"Ano (aa):"<<endl;
            cin >> aa;
            system("CLS"); //Limpia pantalla
            fechaIF.setFecha(dd, mm, aa);
            //Inicia la busqueda por reservacion, al traer la fecha de reservacion la compara la fecha ingresada con la fecha de cada reservacion
            for(int buscarFecha = 0; buscarFecha < cantReservaciones; buscarFecha++){
                //Si encuentra una fecha igual va a buscar los datos del material y del cliente
                if((fechaIF >= reservaciones[buscarFecha]->getFechaReservacion()) && (fechaIF <= reservaciones[buscarFecha]->getFechaReservacion())){
                        for(int buscarMaterial = 0; buscarMaterial < cantMateriales; buscarMaterial++){
                            if(reservaciones[buscarFecha]->getIdCliente() == materiales[buscarMaterial]->getIdMaterial()){
                                //Aqui imprime los datos del cliente
                                cout <<"Nombre del material: " + materiales[buscarMaterial]->getTitulo() <<endl;
                                cout <<"Cliente: " << reservaciones[buscarFecha]->getIdCliente()<<"\n" <<endl;
                            }
                        }
                }
                else{
                    //Si no hay reservaciones con esa fecha
                    cout <<"En esa fecha no hay reservaciones!"<<endl;
                }
            }
    }
}

void consultarReservacionesMaterial(){ //Busca reservaciones por material
    if(cantReservaciones == 0){
        cout <<"No hay reservaciones!"<<endl;
    }
    else{
            int idMaterial;
    bool success;
    if(reservaciones[0] == NULL){
        cout <<"No hay reservaciones"<<endl;
    }
    else{
                while(success == false){
                    cout <<"Ingresa el ID del material: "; //Busca la reservacion por el ID que se pide y cuando lo encuentra imprime los datos
                    cin >> idMaterial;
                    for(int idMaterialConsulta = 0; idMaterialConsulta < cantMateriales; idMaterialConsulta++){
                        if(idMaterial == materiales[idMaterialConsulta]->getIdMaterial()){
                            success = true;
                            break;
                        }
                        else{
                            success = false;
                        }
                    }
                }
                //que muestre para cada reservacion el nombre del material, su fecha de inicio de reservacion y su fecha de terminacion

                for(int buscaMaterial = 0; buscaMaterial < cantMateriales; buscaMaterial++){
                    if(idMaterial == materiales[buscaMaterial]->getIdMaterial()){

                        for(int buscaReservacion = 0; buscaReservacion < cantReservaciones; buscaReservacion++){

                            if(reservaciones[buscaReservacion]->getIdMaterial() == idMaterial){
                                cout <<"Nombre del material: " + materiales[buscaMaterial]->getTitulo() <<endl;
                                cout <<"Fecha de inicio: " << reservaciones[buscaReservacion]->getFechaReservacion()<<endl;
                                Fecha fechaFin = reservaciones[buscaReservacion]->calculaFechaFinReserva((materiales[buscaMaterial]->cantidadDiasPrestamo()));
                                cout << "Fecha de fin: " << fechaFin<< "\n" <<endl;

                            }
                        }
                    }
                }
        }
    }
}

void cargarMateriales(){
    string tituloMaterial, datoCuatro, datoCinco, cadena, tipo;
    int idMaterial, version, numPag, duracion;
    ifstream inFile;
	inFile.open("Material.txt");//Abre el archivo
    cantMateriales = 0;
    while(getline(inFile, cadena)){//lee cada linea para poder separar los campos

		stringstream idMaterialCast(cadena.substr(0, cadena.find(' ')));
		idMaterialCast >> idMaterial;
        cadena = cadena.substr(cadena.find(' ') + 1, cadena.length() - 1);
        tituloMaterial = cadena.substr(0, cadena.find(' '));
        cadena = cadena.substr(cadena.find(' ') + 1, cadena.length() - 1);
        tipo = cadena.substr(0, cadena.find(' '));
        cadena = cadena.substr(cadena.find(' ') + 1, cadena.length() - 1);
        //Define el tipo de material para determinar que tipo de objeto se va inizializar
        if(tipo == "S"){

            //Version
            stringstream versionCast(cadena.substr(0, cadena.find(' ')));
		    versionCast >> version;
            cadena = cadena.substr(cadena.find(' ') + 1, cadena.length() - 1);
            materiales[cantMateriales] = new Software(version, cadena);
            materiales[cantMateriales]->setIdMaterial(idMaterial);
            materiales[cantMateriales]->setTitulo(tituloMaterial);

        }
        else{
            if(tipo == "L"){
                //Es libro
                stringstream numPagCast(cadena.substr(0, cadena.find(' ')));
		        numPagCast >> numPag;
                cadena = cadena.substr(cadena.find(' ') + 1, cadena.length() - 1);
                materiales[cantMateriales] = new Libro(numPag, cadena);
                materiales[cantMateriales]->setIdMaterial(idMaterial);
                materiales[cantMateriales]->setTitulo(tituloMaterial);

            }
            else{
                //Es disco
                stringstream duracionCast(cadena.substr(0, cadena.find(' ')));
                duracionCast >> duracion;
                cadena = cadena.substr(cadena.find(' ') + 1, cadena.length() - 1);
                materiales[cantMateriales] = new Disco(duracion, cadena);
                materiales[cantMateriales]->setIdMaterial(idMaterial);
                materiales[cantMateriales]->setTitulo(tituloMaterial);

            }
        }
        //Aumenta uno a la cantidad de los materiales
		cantMateriales++;
    }
//Cierra archivo
    inFile.close();
}

void consultarMateriales(){
    if(cantMateriales == 0){//Si no hay materiales
            cout<<"No hay materiales registrados!"<<endl;

    }else{
        for(int cm = 0; cm < cantMateriales;cm++){//Va a enlistar todos los materiales, desde el material 0 hasta la cantidad maxima encontrada en el archivo
            cout <<"Id de material: " << materiales[cm]->getIdMaterial() <<endl;
            cout <<"Titulo de material: " + materiales[cm]->getTitulo() <<endl;
            materiales[cm]->muestraDatos();
            cout <<"\n"<<endl;
        }
    }
}

void cargarReservaciones(){
    ifstream inFile;
    inFile.open("Reserva.txt");
    if(inFile.peek() == ifstream::traits_type::eof())//Con esta linea revisa si el archivo de reservaciones esta completamente vacio
    {

    }
    else{//Si el archivo no esta vacio pasa a leer linea por linea para poder cargar los datos de las reservaciones en el arreglo
        string cadena;
        int ddReservacion, mmReservacion, aaReservacion, idMaterial, idCliente;
        cantReservaciones = 0;

            while(getline(inFile, cadena)){
                //Aqui hace la separacion de las cadenas para obtener los datos necesarios toma la
                //línea del archivo y vas sacando dato por dato, desde la posición 0 hasta el siguiente espacio, por eso el find(' ')
                stringstream ddCast(cadena.substr(0, cadena.find(' ')));
                ddCast >> ddReservacion;
                cadena = cadena.substr(cadena.find(' ') + 1, cadena.length() - 1);

                stringstream mmCast(cadena.substr(0, cadena.find(' ')));
                mmCast >> mmReservacion;
                cadena = cadena.substr(cadena.find(' ') + 1, cadena.length() - 1);

                stringstream aaCast(cadena.substr(0, cadena.find(' ')));
                aaCast >> aaReservacion;
                cadena = cadena.substr(cadena.find(' ') + 1, cadena.length() - 1);

                Fecha fecha(ddReservacion,mmReservacion,aaReservacion);

                stringstream idMaterialCast(cadena.substr(0, cadena.find(' ')));
                idMaterialCast >> idMaterial;

                stringstream idClienteCast(cadena.substr(0, cadena.find(' ')));
                idClienteCast >> idCliente;
                reservaciones[cantReservaciones] = new Reserva(idMaterial, idCliente, fecha);

                cantReservaciones++;
                reservacionesIniciales++; //agrega uno al contador de las reservaciones iniciales totales
            }
        inFile.close(); //Cierra archivo
    }

}

void consultarReservaciones(){ //Consulta las reservaciones si es cero aparecera que no hay reservaciones
    if(cantReservaciones == 0){
            cout <<"No hay reservaciones!"<<endl;
    }
    else{for(int cr = 0; cr < cantReservaciones; cr++){
        cout <<"Reservacion #" << cr + 1 <<endl;
        cout <<"Fecha de inicio: " << reservaciones[cr]->getFechaReservacion() <<endl;

        //Buscar el nombre del material
        for(int cm = 0; cm < cantMateriales; cm++){
            if(materiales[cm]->getIdMaterial() == reservaciones[cr]->getIdMaterial()){
                //En caso de haber encontrado el material por la coincidencia entre id material en materiales y en reservaciones
                //Imprime los datos de la reservacion
                Fecha fechaFin = reservaciones[cr]->calculaFechaFinReserva((materiales[cm]->cantidadDiasPrestamo()));
                cout << "Fecha de fin: " << fechaFin <<endl;

                cout <<"Nombre del material: " + materiales[cm]->getTitulo() <<endl;

                cout <<"Id del cliente que reserva: " << reservaciones[cr]->getIdCliente() << endl;

                cout <<"\n"<<endl;

            }
        }
    }

    }

}

void hacerReservacion(){ //Hacer reservacion
    bool success = false;
    Fecha fechaaB;
    int idCliente, idMaterial, dd, mm, aa, indiceMaterial; //Pidiendo como datos el ID del cliente, ID material, dia, mes y año
    cout <<"Ingresa el id del cliente:";
    cin >> idCliente;

    while(success == false){
        cout <<"Ingresa el id del material:"; //Pide ID material, lo busca y si no existe lo seguirá pidiendo, si existe pasara
                                              //a la variable bool a succes true y seguira con el siguinte dato
        cin >> idMaterial;
        for(int x=0; x <cantMateriales; x++){
            if(materiales[x]->getIdMaterial() == idMaterial){
                success = true;
                indiceMaterial = x;
                break;
            }

        }
    }
    success = false;
    while(success == false){ //Si es false pedira la fecha de resevacion, dia, mes y año
        cout <<"Ingresa la fecha para reservacion: "<<endl;
        do{
        cout <<"Dia(dd): ";
        cin >> dd;
        }while(dd < 1 || dd > 31);
        do{
            cout <<"Mes(mm): ";
            cin >> mm;
        }while(mm < 1 || mm > 12);
        cout <<"Ano(aa): ";
        cin >> aa;
        fechaaB.setFecha(dd, mm, aa);
        if(reservaciones[0] == NULL){//Revisa si es la primera reservacion, si es asi el valor de la reservacion 1 esta en NUL entonces guarda los datos
            reservaciones[cantReservaciones] = new Reserva(idMaterial, idCliente, fechaaB);
            success = true;
            cantReservaciones++;
        }
        else{
            for(int buscarFecha = 0; buscarFecha < cantReservaciones; buscarFecha++){
                if(idMaterial == reservaciones[buscarFecha]->getIdMaterial() && fechaaB >= reservaciones[buscarFecha]->getFechaReservacion() && fechaaB <= reservaciones[buscarFecha]->calculaFechaFinReserva((materiales[indiceMaterial]->cantidadDiasPrestamo()))){ //Revisa si  ese material ya tiene esas fechas de reservacion
                    //en caso de que si setea success a false para que vuelvan a ingresar una fecha
                    success = false;
                    break;
                }else{
                    //si el archivo no tiene esas fechas ocupadas cambia la variable success a true
                    success = true;
                }
            }
            if(success == true){//Teniendo la variable en true se puede guardar la nueva reservacion
                    reservaciones[cantReservaciones] = new Reserva(idMaterial, idCliente, fechaaB);
                    cantReservaciones++;
            }
        }

    }
}

void guardarReservaciones(){ //Guardar las reservaciones
    if(cantReservaciones != reservacionesIniciales){ //Revisa que la cantidad de reservaciones finales e iniciales no sea igual en caso de que no sean iguales
        //Guardar reservaciones en el archivo
        ofstream saveToFile;//Abrir un archivo en modo de escritura
        saveToFile.open("Reserva.txt", ofstream::out | ofstream::trunc);//Sirve para abrir un archivo y borrarlo por completo para posteriormente poder  escribir en el
        for(int saveIndex = 0; saveIndex < cantReservaciones; saveIndex++){//Recorre el arreglo de reservacioens
                saveToFile << reservaciones[saveIndex]->getFechaReservacion().getDd() << " " << reservaciones[saveIndex]->getFechaReservacion().getMm() << " " << reservaciones[saveIndex]->getFechaReservacion().getAa() << " " << reservaciones[saveIndex]->getIdMaterial() << " " << reservaciones[saveIndex]->getIdCliente() << endl;//Va guardando linea por linea en el archivo
        }
        exit(1);
    }
    else{
        exit(1);//Sale el programa sin error
    }
}

char menu(){
    system("CLS"); //Limpia la pantalla
    char opcion;
    cout <<"A.- Consultar la lista de Materiales"<<endl;
    cout <<"B.- Consultar la lista de Reservaciones"<<endl;
    cout <<"C.- Consultar las reservaciones de un material dado"<<endl;
    cout <<"D.- Consultar las reservaciones de una fecha dada"<<endl;
    cout <<"E.- Hacer una reservacion"<<endl;
    cout <<"F.- Salir"<<endl;
    cout <<"Seleccion: ";
    cin >> opcion;
    if(opcion == '\0'){
        menu();
    }
    else{
        return opcion;

    }
}

int main(){
    system("color 1F");//Cambia el color de la consola
    cargarMateriales(); //Antes de mostrar cualquier cosa carga los materiales
    cargarReservaciones();// carga las reservaciones desde los archivos correpondientes
    char seleccion;
    do{
        seleccion = menu();
        system("CLS"); //Limpia la pantalla
            switch(seleccion){
            case 'A':                       //Inicia el metodo especiifcado
                    consultarMateriales();
                    system("pause");
                break;
            case 'B':
                    consultarReservaciones();
                    system("pause");
                break;
            case 'C':
                    consultarReservacionesMaterial();
                    system("pause");
                break;
            case 'D':
                    consultaReservacionesFecha();
                    system("pause");
                break;
            case 'E':
                    hacerReservacion();
                    system("pause");
                break;
            case 'F':
                guardarReservaciones();
                break;
        }
    }while(seleccion != 'F');
}
