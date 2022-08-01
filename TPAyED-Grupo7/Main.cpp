//===============================================================
//ALGORITMOS Y ESTRUCTURAS DE DATOS-2do CUATRIMESTRE-2020
//TRABAJO PRACTICO
//GRUPO Nro.7
//===============================================================

/** ULTIMA ACTUALIZACION: 29/10/2020 **/

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>//para fichero
#include <iomanip>//para redondeo de dos decimales
#include <limits>
#include "Lista.h"
#include "Sucursal.h"
#include <string.h> //para quitar case-sensitive


using namespace std;


//tipo de datos para guardar totales Facturacion x Provincia
typedef struct{
    string provincia;
    float monto;
}Facturacion;

//tipo de datos para guardar Facturacion Nacional
typedef struct{
    string codigoSucursal;
    string provincia;
    float monto;
    string casaMatriz;
}FacturacionNacional;

//tipo de datos para guardar cant totales Articulos x Provincia
typedef struct{
    string provincia;
    int cantidad;
}Articulos;

//tipo de datos para guardar cantidad de Articulos Nacional y x Provincia
typedef struct{
    string codigoSucursal;
    string provincia;
    int cantidad;
    string casaMatriz;
}ArticulosNacional;

//tipo de datos para guardar Rendimiento
typedef struct{
string codigoSucursal;
string tipoRendimiento;
string descripcion;
float vRendimiento;
}Rendimiento;

//tipo de datos para guardar las provincias
typedef struct{
    string nombre;
}Provincia;

/*
===============================================================
 PROTOTIPOS DE FUNCIONES
===============================================================
*/
void leerArchivo(Lista &listaSucursales, Lista &listaAux);
void totalXFacturacion(Lista &listaAux, Lista &listaFacturacion);
void totalXFacturacionPais(Lista &listaAux, Lista &listaFacturacion);
void ordenarXFacturacionNacional(Lista &listaFacturacion);
void totalXFacturacionProvincia(Lista &listaAux, Lista &listaFacturacion);
Lista traerProvincias(Lista &listaAux);
void ordenarXFacturacion(Lista &listaFacturacion);
void imprimirListaFacturacion(Lista &listaFacturacion);
void totalXArticulos(Lista &listaAux, Lista &listaArticulos);
void totalXArticulosPais(Lista &listaAux, Lista &listaArticulos);
void ordenarXVentas(Lista &listaArticulos);
void ordenarXArticulosNacional(Lista &listaArticulos);
void totalXArticulosProvincia(Lista &listaAux, Lista &listaArticulos);
void imprimirListaVentas(Lista &listaArticulos);
void rendimientoIndividual(Lista &listaAux, Lista &listaRendimientos);
void rendimientoMatriz(Lista &listaAux, Lista &listaRendimientos);
void ordenarXRendimiento(Lista &listaRendimientos);
void imprimirListaRendimiento(Lista &listaRendimientos);
void imprimirLista(Lista &listaSucursales);
float sumasxProvincias(string provincia,Sucursal suc);
void asginarFacturacion(string Iprovincia,float Imonto,Lista &listaFacturacion);
int sumaArtxProvincias(string provincia,Sucursal suc);
void asginarArticulos(string Iprovincia,int IcantArt,Lista &listaArticulos);
void ordenarXMatriz(Lista &listaTemp);
Lista copiarCasaMatriz(Lista &listaAux);
void eliminarRep(Lista &listaTemp);
bool esNumero();

void eliminarFacturacion(Lista &listaFacturacion);
void eliminarFNacional(Lista &listaFacturacion);
void eliminarVentas(Lista &listaArticulos);
void eliminarVNacional(Lista &listaArticulos);
void eliminarRendimiento(Lista &listaRendimientos);
void eliminarProvincias(Lista &listaProvincias);
/*
===============================================================
 MAIN
===============================================================
*/
int main(int argc, char *argv[]){
int opcion = 0;
int opcionFact=0;
int opcionArt=0;
bool seguir = true;
bool seguirFact=true;
bool seguirArt = true;
bool esNum= true;
Lista listaSucursales;
crearLista(listaSucursales);
Lista listaAux;
crearLista(listaAux);
    while (seguir){
        system("cls");
        system("color 0a");//cambia color de la impresión por pantalla
        cout << endl;
        cout << "================================================================= \n";
        cout << "==========================FRANQUICIAS============================ \n";
        cout << "================================================================= \n";
        cout << "[0] Salir" << endl;
        cout << "[1] Cargar .txt" << endl;
        cout << "[2] Reporte: Ranking de sucursales con mayor facturacion" << endl;
        cout << "[3] Reporte: Ranking de sucursales con mayor cantidad de ventas" << endl;
        cout << "[4] Reporte de Rendimiento" << endl;
        cout << "[5] Imprimir Lista ORIGINAL." << endl;
        cout << "================================================================= \n";
        cout << endl;
        cout <<"Ingrese una opcion o cero(0) para salir: ";
        cin >> opcion;
        esNum=esNumero();
        cout << "\n=================================================================  \n";
        if(esNum){
        switch (opcion){

        case 0://SALIR DEL SISTEMA
            cout <<"\n=============================================== \n";
            cout <<"\t    VUELVA PRONTO!!! \n";
            cout <<"=============================================== \n"<<endl;
            eliminarLista(listaSucursales);
            eliminarLista(listaAux); // borramos listaSucursales y listaAux, una vez damos de baja el programa
            seguir = false;
            break;

        case 1://CARGA DEL ARCHIVO .txt
            cout << endl;
            cout <<"=================================== \n";
            cout <<"Resultado de carga de archivo .txt"<<endl;
            eliminarLista(listaAux);
            eliminarLista(listaSucursales);
            leerArchivo(listaSucursales,listaAux);
            cout <<"=================================== \n"<<endl;
            break;

            case 2://REPORTE: RANKING DE FACTURACION POR PROVINCIA Y NACIONAL
                Lista listaFacturacion;
                crearLista(listaFacturacion);
                seguirFact=true;
                while(seguirFact){
                    system("cls");

                    cout << endl;
                    cout << "===================================================== \n";
                    cout << "=====================Facturacion===================== \n";
                    cout << "===================================================== \n";
                    cout << "[0] Salir" << endl;
                    cout << "[1] Totales por provincia y pais" << endl;
                    cout << "[2] Sucursales de mayor facturacion por pais" << endl;
                    cout << "[3] Sucursales de mayor facturacion por provincia" << endl;
                    cout << "===================================================== \n";
                    cout << endl;
                    cout <<"Ingrese una opcion o cero(0) para salir: ";
                    cin >> opcionFact;
                    esNum=esNumero();
                    cout << "\n===================================================== \n";
                    if(esNum){
                        switch(opcionFact){
                        case 0:
                            eliminarLista(listaFacturacion);
                            seguirFact=false;
                            break;
                        case 1:
                            totalXFacturacion(listaAux,listaFacturacion);
                            break;
                        case 2:
                            totalXFacturacionPais(listaAux,listaFacturacion);
                            break;
                        case 3:
                            totalXFacturacionProvincia(listaAux,listaFacturacion);
                            break;
                        default:
                            cout << "Opcion Incorrecta" << endl;
                            break;
                        }
                    }
                    system("PAUSE");
                }
                break;

        case 3://REPORTE: RANKING DE CANTIDAD VENDIDA POR PROVINCIA Y NACIONAL
                Lista listaArticulos;
                crearLista(listaArticulos);
                seguirArt=true;
                while(seguirArt){
                    system("cls");

                    cout << endl;
                    cout << "======================================================== \n";
                    cout << "=======================Articulos======================== \n";
                    cout << "======================================================== \n";
                    cout << "[0] Salir" << endl;
                    cout << "[1] Totales por provincia y pais" << endl;
                    cout << "[2] Sucursales de mayor cantidad vendida por pais" << endl;
                    cout << "[3] Sucursales de mayor cantidad vendida por provincia" << endl;
                    cout << "======================================================== \n";
                    cout << endl;
                    cout <<"Ingrese una opcion o cero(0) para salir: ";
                    cin >> opcionArt;
                    esNum=esNumero();
                    cout << "\n===================================================== \n";
                    if(esNum){
                        switch(opcionArt){
                        case 0:
                            eliminarLista(listaArticulos);
                            seguirArt=false;
                            break;
                        case 1:
                            totalXArticulos(listaAux,listaArticulos);
                            break;
                        case 2:
                            totalXArticulosPais(listaAux,listaArticulos);
                            break;
                        case 3:
                            totalXArticulosProvincia(listaAux,listaArticulos);
                            break;
                        default:
                            cout << "Opcion Incorrecta" << endl;
                            break;
                        }
                    }
                    system("PAUSE");
                }
               break;

        case 4://REPORTE DE RENDIMIENTO INDIVIDUAL Y POR CASA MATRIZ
            Lista listaRendimientos;
            crearLista(listaRendimientos);
            system("CLS"); // limpiamos la consola, mostrando solamente el rendimiento
            //NO llamamos primero rendimientoIndividual porque de esa manera evitamos preguntar si tiene o no
            //casa matriz asociada.
            rendimientoMatriz(listaAux,listaRendimientos);
            // preguntamos si esta cargado en la listaRendimientos
            rendimientoIndividual(listaAux,listaRendimientos);
            ordenarXRendimiento(listaRendimientos);
            imprimirListaRendimiento(listaRendimientos);
            eliminarRendimiento(listaRendimientos);
            break;

        case 5://IMPRIMIR LISTA ORIGINAL
            imprimirLista(listaSucursales);
            break;

            default:
                cout << "Opcion Incorrecta" << endl;
                break;
            }
        }
       system("PAUSE");
    }
return 0;
}


/*
===============================================================
 FIN MAIN
===============================================================
*/

/*
======================================================================================
FUNCIONES:
--------------------------------------------------------------------------------------
CARGA DEL .TXT
--------------------------------------------------------------------------------------
1.0) leerArchivo(Lista &listaSucursales, Lista &listaAux): void.
--------------------------------------------------------------------------------------
REPORTE FACTURACION
--------------------------------------------------------------------------------------
2.0) totalXFacturacion(Lista &listaAux, Lista &listaFacturacion): void.
2.1) ordenarXFacturacion(Lista &listaFacturacion): void.
2.2) imprimirListaFacturacion(Lista &listaFacturacion): void.
2.3) sumasxProvincias(string provincia,Sucursal suc): float.
2.4) asginarFacturacion(string Iprovincia,float Imonto,Lista &listaFacturacion): void.
2.5) totalXFacturacionPais(Lista &listaAux, Lista &listaFacturacion): void.
2.6) ordenarXFacturacionNacional(Lista &listaFacturacion): void.
2.7) totalXFacturacionProvincia(Lista &listaAux, Lista &listaFacturacion): void.
2.8) traerProvincias(Lista &listaAux, Lista &listaFacturacion): Lista.
2.9) eliminarFacturacion(Lista &listaFacturacion): void.
2.10) eliminarFNacional(Lista &listaFacturacion): void.
--------------------------------------------------------------------------------------
REPORTE CANTIDAD ARTICULOS VENDIDOS
--------------------------------------------------------------------------------------
3.0) totalXArticulos(Lista &listaAux, Lista &listaArticulos): void.
3.1) ordenarXVentas(Lista &listaArticulos): void.
3.2) imprimirListaVentas(Lista &listaArticulos): void.
3.3) sumaArtxProvincias(string provincia,Sucursal suc): int.
3.4) asginarArticulos(string Iprovincia,int IcantArt,Lista &listaArticulos): void.
3.5) totalXArticulosPais(Lista &listaAux, Lista &listaArticulos): void.
3.6) ordenarXArticulosNacional(Lista &listaArticulos): void.
3.7) totalXArticulosProvincia(Lista &listaAux, Lista &listaArticulos): void.
3.8) eliminarVentas(Lista &listaArticulos): void.
3.9) eliminarVNacional(Lista &listaArticulos): void.
--------------------------------------------------------------------------------------
REPORTE RENDIMIENTO
--------------------------------------------------------------------------------------
4.0) rendimientoIndividual(Lista &listaAux, Lista &listaRendimentos): void.
4.1) rendimientoMatriz(Lista &listaAux, Lista &listaRendimentos): void.
4.2) ordenarXRendimiento(Lista &listaRendimentos): void.
4.3) ordenarXMatriz(Lista &listaTemp): void.
4.4) copiarCasaMatriz(Lista &listaAux): Lista.
4.5) eliminarRep(Lista &listaTemp): void.
4.6) imprimirListaRendimiento(Lista &listaRendimentos): void.
4.7) eliminarRendimiento(Lista &listaRendimientos): void.
--------------------------------------------------------------------------------------
IMPRIMIR LISTA ORIGINAL
--------------------------------------------------------------------------------------
5.0) imprimirLista(Lista &listaSucursales): void.
--------------------------------------------------------------------------------------
OTRAS FUNCIONES
6.0) esNumero(): bool.
6.1) eliminarProvincias(Lista &listaProvincias): void.
--------------------------------------------------------------------------------------
======================================================================================
*/


/*
=================================================================================
1.0) leerArchivo(Lista &listaSucursales, Lista &listaAux): void.
Recibirá un archivo .txt que contendrá el código de sucursal,la provincia,
la cantidad de artículos vendidos, el monto mensual de la facturación y
los metros cuadrados del local.
El archivo abierto se carga en dos listas una listaSucursales y otra listaAux que
es la que se utilizará para llevar a cabo lo solicitado en el trabajo práctico.
Se decide trabajar con la listaAux para evitar perder los datos originales en
caso de error.
[CódigoSucursal]-[Provincia]-[CantidadArtículos]-[MontoFacturación]-
            [metrosCuadrados] ]-[Casa Matriz]
=================================================================================
*/
void leerArchivo(Lista &listaSucursales, Lista &listaAux){
char cadena[500];
string auxCodigo="";
int auxCantidad=0;
string auxMatriz="";
float auxMonto=0, auxMetros=0;
ifstream fichero;

fichero.open ("ejemplo-sucursales.txt", ios::out | ios::in); //abre archivo

    // verifica la apertura del archivo
    if(fichero.fail()){
    cout<<"No se pudo abrir el archivo";
        exit(1);
    }else{
    // lectura de datos
           while (!fichero.eof()){

           Sucursal* suc=new Sucursal;
           crear(*suc);

           //getline-lectura de una línea de caracteres hasta el salto de línea
           fichero.getline(cadena,50, '-');

           auxCodigo=cadena;
           int lengthOfString = auxCodigo.size();//longitud del codigo
           setCodigoSucursal(*suc,auxCodigo);

           fichero.getline(cadena,50, '-');
           setProvincia(*suc,cadena);

           fichero.getline(cadena,50, '-');
           auxCantidad=atoi(cadena);
           setCantidadArticulos(*suc,auxCantidad);

           fichero.getline(cadena,50, '-');
           auxMonto=atof(cadena);
           setMontoFacturacion(*suc,auxMonto);

           fichero.getline(cadena,50, '-');
           auxMetros=atof(cadena);
           setMetrosCuadrados(*suc,auxMetros);

            fichero.getline(cadena,50, '\n');
           auxMatriz=cadena;
           setCasaMatriz(*suc,auxMatriz);

         agregarNodo(listaSucursales,suc);
         agregarNodo(listaAux,suc);
        eliminar(*suc);//elimino el espacio en memoria de new Sucursal
     }
    fichero.close();//cierro archivo
    cout<<"Archivo .txt  cargado"<<endl;
    }
}

/*
=====================================================================================
2.0) totalXFacturacion(Lista &listaAux, Lista &listaFacturacion): void.
Se recorre listaAux para obtener la provincia y el monto de facturacion de la misma,
si dicha provincia tiene varias facturaciones estas se suman.
Las sumas por provincia se pasan a una lista a partir de la estructura Facturacion
creada en main.
=====================================================================================
*/

void totalXFacturacion(Lista &listaAux, Lista &listaFacturacion){
PtrNodo cursor = primerNodo(listaAux);
Sucursal auxNombre;
Provincia provincia;
float sumaProvincia,sumaTotal=0;

Lista listaProvincias=traerProvincias(listaAux);

PtrNodo cursor1 = primerNodo(listaProvincias);

while(cursor1!= NULL){// recorro cada provincia
    provincia=*((Provincia*)cursor1->dato);
    cursor = primerNodo(listaAux);
    while (cursor != NULL) {    // recorre toda la lista de las sucursales
    auxNombre= *((Sucursal*)cursor->dato);
    sumaProvincia=sumaProvincia+sumasxProvincias(provincia.nombre,auxNombre);
    cursor=ptrSgte(listaAux,cursor);
    }
    sumaTotal=sumaProvincia+sumaTotal;
    asginarFacturacion(provincia.nombre,sumaProvincia,listaFacturacion);
    sumaProvincia=0;
    cursor1=ptrSgte(listaProvincias,cursor1);
}

ordenarXFacturacion(listaFacturacion);
imprimirListaFacturacion(listaFacturacion);

cout <<"============================================ \n";
cout<<"TOTAL NACIONAL FACTURADO ......: "<<sumaTotal<<endl;
cout <<"============================================ \n";
eliminarProvincias(listaProvincias);
eliminarFacturacion(listaFacturacion);
}


/*
=================================================================================
2.1) ordenarXFacturacion(Lista &listaFacturacion): void.
=================================================================================
*/
void ordenarXFacturacion(Lista &listaFacturacion){
PtrNodo cursor = primerNodo(listaFacturacion);
PtrNodo sigPosicion=NULL;
Dato aux;

 while (cursor->ptrSgte != NULL) {
    sigPosicion = cursor->ptrSgte;
        while (sigPosicion != NULL) {
 if ((((Facturacion*)sigPosicion->dato)->monto) > ((Facturacion*)cursor->dato)->monto) {

                 aux = cursor->dato;
                cursor->dato= sigPosicion->dato;
                sigPosicion->dato= aux;
             }
            sigPosicion = sigPosicion->ptrSgte;
        }
        cursor = cursor->ptrSgte;
    }
}

/*
=================================================================================
2.2) imprimirListaFacturacion(Lista &listaFacturacion): void.
=================================================================================
*/
void imprimirListaFacturacion(Lista &listaFacturacion){
PtrNodo cursor=primerNodo(listaFacturacion);

cout <<"\n============================================= \n";
cout <<"    FACTURACION POR PROVINCIA  \n";
cout <<"============================================= \n";

 while(cursor!= NULL){
     Facturacion *f=(Facturacion*)cursor->dato;
     cout<<"Provincia..........: "<<f->provincia<<endl;
     cout<<"Monto Facturacion..: "<<fixed<<setprecision(2)<<f->monto<<endl;
     cout <<"========================================== \n";
     cursor=ptrSgte(listaFacturacion,cursor);
    }
}

/*
=================================================================================
2.3) Creamos sumasxProvincias para sacar la facturacion, si una tiene
varias facturaciones se suman a una variable declarada
=================================================================================
*/
float sumasxProvincias(string provincia,Sucursal suc){
float suma=0;
    if(provincia.compare(suc.provincia)==0){
        suma=suma+suc.montoFacturacion;
    }
    return suma;
}
/*
=================================================================================
2.4) Asignamos la facturacion a una lista de facturacion que es pasada por
parametro y le enviamos la provincia, y el monto total por cada provincia
=================================================================================
*/
void asginarFacturacion(string Iprovincia,float Imonto,Lista &listaFacturacion){
    Facturacion *f1=new Facturacion;
    f1->provincia=Iprovincia;
    f1->monto=Imonto;
    agregarNodo(listaFacturacion,f1);
}


/*
=================================================================================
2.5) totalXFacturacionPais(Lista &listaAux, Lista &listaFacturacion): void.
Se recorre listaAux para obtener el codigo ,la provincia, el monto, y casa matriz
de facturacion de la misma,
Dentro de la misma imprimimos cada sucursal ordenada de mayor a menor facturacion
=================================================================================
*/
void totalXFacturacionPais(Lista &listaAux, Lista &listaFacturacion){
PtrNodo cursor = primerNodo(listaAux);
Sucursal auxNombre;
    while (cursor != NULL){
        auxNombre= *((Sucursal*)cursor->dato);
        FacturacionNacional * f1=new FacturacionNacional;
        f1->codigoSucursal=auxNombre.codigoSucursal;
        f1->provincia=auxNombre.provincia;
        f1->monto=auxNombre.montoFacturacion;
        f1->casaMatriz=auxNombre.casaMatriz;
        agregarNodo(listaFacturacion,f1);
        cursor=ptrSgte(listaAux,cursor);
    }

ordenarXFacturacionNacional(listaFacturacion);
PtrNodo cursor1=primerNodo(listaFacturacion);

cout <<"\n============================================= \n";
cout <<"    FACTURACION DE SUCURSALES NACIONAL  \n";
cout <<"=============================================\n";

    while(cursor1!= NULL){
        FacturacionNacional *f=(FacturacionNacional*)cursor1->dato;
        cout<<"Codigo de sucursal.: "<<f->codigoSucursal<<endl;
        cout<<"Provincia..........: "<<f->provincia<<endl;
        cout<<"Monto Facturacion..: "<<fixed<<setprecision(2)<<f->monto<<endl;
        cout<<"Casa matriz .......: "<<f->casaMatriz<<endl;
        cout <<"========================================== \n";
        cursor1=ptrSgte(listaFacturacion,cursor1);
    }
eliminarFNacional(listaFacturacion);
}

/*
=================================================================================
2.6) ordenarXFacturacionNacional(Lista &listaFacturacion): void.
=================================================================================
*/
void ordenarXFacturacionNacional(Lista &listaFacturacion){
PtrNodo cursor = primerNodo(listaFacturacion);
PtrNodo sigPosicion=NULL;
Dato aux;
//ordena la lista de facturacion hay que meterlo en un procedimiento
    while (cursor->ptrSgte != NULL) {
        sigPosicion = cursor->ptrSgte;
        while (sigPosicion != NULL) {
 if ((((FacturacionNacional*)sigPosicion->dato)->monto) > ((FacturacionNacional*)cursor->dato)->monto) {

                 aux = cursor->dato;
                cursor->dato= sigPosicion->dato;
                sigPosicion->dato= aux;
             }
            sigPosicion = sigPosicion->ptrSgte;
        }
        cursor = cursor->ptrSgte;
    }
}
/*
=================================================================================
2.7) totalXFacturacionProvincia(Lista &listaAux, Lista &listaFacturacion): void.
El usuario introduce el nombre de la provincia a la que quiere preguntar su facturacion
Se recorre listaAux y preguntamos si la provincia esta cargada o no, y ademas para
obtener el codigo ,la provincia, el monto, y casa matriz de facturacion de la misma,
Dentro de la misma imprimimos cada sucursal ordenada de mayor a menor facturacion
=================================================================================
*/
void totalXFacturacionProvincia(Lista &listaAux, Lista &listaFacturacion){
PtrNodo cursor = primerNodo(listaAux);
Sucursal auxNombre;
string provincia;
bool encontro=false; //para preguntar despues si la provincia que ingreso está o no.


cout<<"Ingrese la provincia para conocer la facturacion: ";
cin.ignore(); // evitamos el espacio
getline(cin, provincia);
// faltaria que si envia los caracteres mayuscula o minuscula, que lo arregle


while(cursor != NULL){  //preguntamos si la provincia que ingresamos esta cargada, entonces agregamos la sucursal
    auxNombre= *((Sucursal*)cursor->dato);
    if(stricmp(provincia.c_str(),getProvincia(auxNombre).c_str())==0 ){ //pregunta si es correcta o no la provincia quitando el case sensitive
        FacturacionNacional * f1=new FacturacionNacional;
        f1->codigoSucursal=auxNombre.codigoSucursal;
        f1->monto=auxNombre.montoFacturacion;
        f1->provincia=auxNombre.provincia;
        f1->casaMatriz=auxNombre.casaMatriz;
        agregarNodo(listaFacturacion,f1);
        encontro=true;
    }
    cursor=ptrSgte(listaAux,cursor);
}
// si encuentra la provincia alguna vez, imprimo, si no lo encuentra envia un mensaje.
if(encontro==false){
    cout<<"La provincia ingresada no esta cargada, o es inexistente"<<endl;
}else{
ordenarXFacturacionNacional(listaFacturacion);
cursor=primerNodo(listaFacturacion);

cout <<"\n============================================= \n";
cout <<"    FACTURACION DE SUCURSALES PROVINCIA: "<<provincia<<endl;
cout <<"=============================================\n";

    while(cursor!= NULL){
        FacturacionNacional *f=(FacturacionNacional*)cursor->dato;
        cout<<"Codigo de sucursal.: "<<f->codigoSucursal<<endl;
        cout<<"Provincia..........: "<<f->provincia<<endl;
        cout<<"Monto Facturacion..: "<<fixed<<setprecision(2)<<f->monto<<endl;
        cout<<"Casa matriz .......: "<<f->casaMatriz<<endl;
        cout <<"========================================== \n";
        cursor=ptrSgte(listaFacturacion,cursor);
    }
}
eliminarFNacional(listaFacturacion);
}

/*
=================================================================================
2.8) traerProvincias(Lista &listaAux, Lista &listaFacturacion): Lista.
agregamos las provincias que tenemos cargadas en el txt y posteriormente
eliminamos las repetidas.
=================================================================================
*/
Lista traerProvincias(Lista &listaAux){
PtrNodo cursor = primerNodo(listaAux);
Sucursal auxNombre;

Lista listaProvincias;
crearLista(listaProvincias);

while(cursor!=NULL){// recorremos la lista auxiliar y asignamos todas la provincias de las sucursales
    auxNombre=*((Sucursal*)cursor->dato);
    Provincia *p= new Provincia;
    p->nombre=getProvincia(auxNombre);
    agregarNodo(listaProvincias,p);
    cursor = cursor->ptrSgte;
}

// elimina provincias repetidas
cursor = primerNodo(listaProvincias);
PtrNodo sigPosicion=NULL;

    while (cursor != NULL) {
        sigPosicion = cursor->ptrSgte;
        while (sigPosicion != NULL) {
            if ((((Provincia*)sigPosicion->dato)->nombre) == ((Provincia*)cursor->dato)->nombre) {
                eliminarNodo(listaProvincias,sigPosicion);
             }
            sigPosicion = sigPosicion->ptrSgte;
        }
        cursor = cursor->ptrSgte;
    }
    return listaProvincias;
}

/**
=================================================================================
2.9) eliminarFacturacion(Lista &listaFacturacion): void.
Libero el espacio de memoria solicitado y elimino la lista de reporte facturacion.
=================================================================================
*/
void eliminarFacturacion(Lista &listaFacturacion){
PtrNodo cursor=primerNodo(listaFacturacion);
    while(cursor != NULL){
    //libero espacio en memoria que solicite para Facturacion.
        delete (Facturacion*)cursor->dato;
        cursor=ptrSgte(listaFacturacion, cursor);
    }
    eliminarLista(listaFacturacion);
}

/**
=================================================================================
2.10) eliminarFNacional(Lista &listaFacturacion): void.
Libero el espacio de memoria solicitado y elimino la lista de reporte facturacion.
=================================================================================
*/
void eliminarFNacional(Lista &listaFacturacion){
PtrNodo cursor=primerNodo(listaFacturacion);
    while(cursor != NULL){
    //libero espacio en memoria que solicite para FacturacionNacional.
        delete (FacturacionNacional*)cursor->dato;
        cursor=ptrSgte(listaFacturacion, cursor);
    }
    eliminarLista(listaFacturacion);
}

/*
======================================================================================
3.0) totalXArticulos(Lista &listaAux,Lista &listaArticulos): void.
Se recorre listaAux para obtener la provincia y la cantidad de artículos vendidos por
sucursal, dichos valores se suman para poder obtener una lista con la cantidad vendida
a nivel nacional y por provincia y se pasan a la listaArticulos para su posterior
ordenamiento.
======================================================================================
*/
void totalXArticulos(Lista &listaAux,Lista &listaArticulos){
PtrNodo cursor = primerNodo(listaAux);
Sucursal auxNombre;
Provincia provincia;
float sumaProvincia,sumaTotal=0;

Lista listaProvincias=traerProvincias(listaAux);
PtrNodo cursor1 = primerNodo(listaProvincias);

while(cursor1!= NULL){// recorro cada provincia
    provincia=*((Provincia*)cursor1->dato);
    cursor = primerNodo(listaAux);
    while (cursor != NULL) { // recorro la lista auxiliar
        auxNombre= *((Sucursal*)cursor->dato);
        sumaProvincia=sumaProvincia+sumaArtxProvincias(provincia.nombre,auxNombre);
        cursor=ptrSgte(listaAux,cursor);
    }
    sumaTotal=sumaProvincia+sumaTotal;
    asginarArticulos(provincia.nombre,sumaProvincia,listaArticulos);
    sumaProvincia=0;
    cursor1=ptrSgte(listaProvincias,cursor1);
}

ordenarXVentas(listaArticulos);
imprimirListaVentas(listaArticulos);

cout <<"============================================== \n";
cout<<"TOTAL NACIONAL ARTICULOS VENDIDOS..: "<<sumaTotal<<endl;
cout <<"============================================== \n";
eliminarProvincias(listaProvincias);
eliminarVentas(listaArticulos);
}

/*
=================================================================================
3.1) ordenarXVentas(Lista &listaArticulos): void.
=================================================================================
*/
void ordenarXVentas(Lista &listaArticulos){
PtrNodo cursor = primerNodo(listaArticulos);
PtrNodo sigPosicion=NULL;
Dato aux;

    while (cursor->ptrSgte != NULL) {
        sigPosicion = cursor->ptrSgte;
        while (sigPosicion != NULL) {

            if ((((Articulos*)sigPosicion->dato)->cantidad) > ((Articulos*)cursor->dato)->cantidad) {

                 aux = cursor->dato;
                cursor->dato= sigPosicion->dato;
                sigPosicion->dato= aux;
             }
            sigPosicion = sigPosicion->ptrSgte;
        }
        cursor = cursor->ptrSgte;
    }
}

/*
=================================================================================
3.2) imprimirListaVentas(Lista &listaArticulos): void.
=================================================================================
*/
void imprimirListaVentas(Lista &listaArticulos){
PtrNodo cursor=primerNodo(listaArticulos);

cout <<"\n=============================================== \n";
cout <<"    RANKING DE CANTIDAD VENDIDA POR PROVINCIA  \n";
cout <<"=============================================== \n";

    while(cursor!= NULL){
     Articulos* a=(Articulos*)cursor->dato;
        cout<<"Provincia..........: "<<a->provincia<<endl;
        cout<<"Cantidad Vendida...: "<<a->cantidad<<endl;
        cout <<"=========================== \n";
        cursor=ptrSgte(listaArticulos,cursor);
    }
}


/*
=================================================================================
3.3) Creamos sumaArtxProvincias para sacar la cantidad de articulos, si una tiene
varios articulos se suman a una variable declarada
=================================================================================
*/
int sumaArtxProvincias(string provincia,Sucursal suc){
int suma=0;
    if(provincia.compare(suc.provincia)==0){
        suma=suma+suc.cantidadArticulos;
    }
    return suma;
}

/*
=================================================================================
3.4) Asignamos la articulos a una lista de articulos que es pasada por
parametro y le enviamos la provincia, y la cantidad total por cada provincia
=================================================================================
*/
void asginarArticulos(string Iprovincia,int IcantArt,Lista &listaArticulos){
Articulos *articulos=new Articulos;
articulos->provincia=Iprovincia;
articulos->cantidad=IcantArt;
agregarNodo(listaArticulos,articulos);
}

/*
=================================================================================
3.5) totalXArticulosPais(Lista &listaAux, Lista &listaArticulos): void.
Se recorre listaAux para obtener el codigo ,la provincia, la cantidad de articulos, y casa matriz,
Dentro de la misma imprimimos cada sucursal ordenada de mayor a menor cantidad vendida
=================================================================================
*/
void totalXArticulosPais(Lista &listaAux, Lista &listaArticulos){
PtrNodo cursor = primerNodo(listaAux);
Sucursal auxNombre;
    while (cursor != NULL){
        auxNombre= *((Sucursal*)cursor->dato);
        ArticulosNacional * a1=new ArticulosNacional;
        a1->codigoSucursal=auxNombre.codigoSucursal;
        a1->provincia=auxNombre.provincia;
        a1->cantidad=auxNombre.cantidadArticulos;
        a1->casaMatriz=auxNombre.casaMatriz;
        agregarNodo(listaArticulos,a1);
        cursor=ptrSgte(listaAux,cursor);
    }

ordenarXArticulosNacional(listaArticulos);
PtrNodo cursor1=primerNodo(listaArticulos);

cout <<"\n============================================= \n";
cout <<"    CANTIDAD VENDIDA DE SUCURSALES NACIONAL  \n";
cout <<"=============================================\n";

    while(cursor1!= NULL){
        ArticulosNacional *a=(ArticulosNacional*)cursor1->dato;
        cout<<"Codigo de sucursal.: "<<a->codigoSucursal<<endl;
        cout<<"Provincia..........: "<<a->provincia<<endl;
        cout<<"Cantidad Vendida...: "<<a->cantidad<<endl;
        cout<<"Casa matriz........: "<<a->casaMatriz<<endl;
        cout <<"========================================== \n";
        cursor1=ptrSgte(listaArticulos,cursor1);
    }
    eliminarVNacional(listaArticulos);
}

/*
=================================================================================
3.6) ordenarXArticulosNacional(Lista &listaArticulos): void.
=================================================================================
*/
void ordenarXArticulosNacional(Lista &listaArticulos){
PtrNodo cursor = primerNodo(listaArticulos);
PtrNodo sigPosicion=NULL;
Dato aux;
//ordena la lista de articulos hay que meterlo en un procedimiento
    while (cursor->ptrSgte != NULL) {
        sigPosicion = cursor->ptrSgte;
        while (sigPosicion != NULL) {
 if ((((ArticulosNacional*)sigPosicion->dato)->cantidad) > ((ArticulosNacional*)cursor->dato)->cantidad) {

                 aux = cursor->dato;
                cursor->dato= sigPosicion->dato;
                sigPosicion->dato= aux;
             }
            sigPosicion = sigPosicion->ptrSgte;
        }
        cursor = cursor->ptrSgte;
    }
}
/*
=================================================================================
3.7) totalXArticulosProvincia(Lista &listaAux, Lista &listaArticulos): void.
El usuario introduce el nombre de la provincia a la que quiere preguntar su cantidad de Articulos vendida
Se recorre listaAux y preguntamos si la provincia esta cargada o no, y ademas para
obtener el codigo ,la provincia, el monto, y casa matriz,
Dentro de la misma imprimimos cada sucursal ordenada de mayor a menor cantidad de Articulos vendida
=================================================================================
*/
void totalXArticulosProvincia(Lista &listaAux, Lista &listaArticulos){
PtrNodo cursor = primerNodo(listaAux);
Sucursal auxNombre;
string provincia;
bool encontro=false; //para preguntar despues si la provincia que ingreso está o no.


cout<<"Ingrese la provincia para conocer la cantidad de articulos: ";
cin.ignore(); // evitamos el espacio
getline(cin, provincia);
// faltaria que si envia los caracteres mayuscula o minuscula, que lo arregle


while(cursor != NULL){  //preguntamos si la provincia que ingresamos esta cargada, entonces agregamos la sucursal
    auxNombre= *((Sucursal*)cursor->dato);
    if(stricmp(provincia.c_str(),getProvincia(auxNombre).c_str())==0){
        ArticulosNacional * a1=new ArticulosNacional;
        a1->codigoSucursal=auxNombre.codigoSucursal;
        a1->cantidad=auxNombre.cantidadArticulos;
        a1->provincia=auxNombre.provincia;
        a1->casaMatriz=auxNombre.casaMatriz;
        agregarNodo(listaArticulos,a1);
        encontro=true;
    }
    cursor=ptrSgte(listaAux,cursor);
}
// si encuentra la provincia alguna vez, imprimo, si no lo encuentra envia un mensaje.
if(encontro==false){
    cout<<"La provincia ingresada no esta cargada, o es inexistente"<<endl;
}else{
ordenarXArticulosNacional(listaArticulos);
cursor=primerNodo(listaArticulos);

cout <<"\n============================================= \n";
cout <<"    CANTIDAD VENDIDA POR PROVINCIA: "<<provincia<<endl;
cout <<"=============================================\n";

    while(cursor!= NULL){
        ArticulosNacional *a=(ArticulosNacional*)cursor->dato;
        cout<<"Codigo de sucursal.....: "<<a->codigoSucursal<<endl;
        cout<<"Provincia..............: "<<a->provincia<<endl;
        cout<<"Cantidad de Articulos..: "<<a->cantidad<<endl;
        cout<<"Casa matriz ...........: "<<a->casaMatriz<<endl;
        cout <<"========================================== \n";
        cursor=ptrSgte(listaArticulos,cursor);
    }
  }
    eliminarVNacional(listaArticulos);
}

/**
=================================================================================
3.8) eliminarVentas(Lista &listaArticulos): void.
Libero el espacio de memoria solicitado y elimino la lista
de reporte cantidad de articulos vendidos.
=================================================================================
*/
void eliminarVentas(Lista &listaArticulos){
PtrNodo cursor=primerNodo(listaArticulos);
    while(cursor != NULL){
    //libero espacio en memoria que solicite para Articulos
        delete (Articulos*)cursor->dato;
        cursor=ptrSgte(listaArticulos, cursor);
    }
    eliminarLista(listaArticulos);
}

/**
=================================================================================
3.9) eliminarVNacional(Lista &listaArticulos): void.
Libero el espacio de memoria solicitado y elimino la lista
de reporte cantidad de articulos vendidos.
=================================================================================
*/
void eliminarVNacional(Lista &listaArticulos){
PtrNodo cursor=primerNodo(listaArticulos);
    while(cursor != NULL){
    //libero espacio en memoria que solicite para ArticulosNacional
        delete (ArticulosNacional*)cursor->dato;
        cursor=ptrSgte(listaArticulos, cursor);
    }
    eliminarLista(listaArticulos);
}

/*
=================================================================================
4.0) rendimientoIndividual(Lista &listaAux, Lista &listaRendimientos): void.
=================================================================================
*/
void rendimientoIndividual(Lista &listaAux, Lista &listaRendimientos){
PtrNodo cursor = primerNodo(listaAux);
Sucursal aux;
Rendimiento aux2;
float rendimiento=0;
bool salir=false;

    while (cursor != NULL){ //lista general
        aux=  *((Sucursal*)cursor->dato);
        PtrNodo cursor1 = primerNodo(listaRendimientos);
        if (aux.casaMatriz=="0000"){    //pregunto en la lista general los que tengan casa matriz 0000
            while(cursor1 != NULL&&(salir==false)){ //lista de rendimientos cargada
                aux2=  *((Rendimiento*)cursor1->dato);
                if(aux2.codigoSucursal==aux.codigoSucursal){
                    salir=true;
                }
            cursor1=ptrSgte(listaRendimientos,cursor1);
            }
            if(salir==false){
            rendimiento=calcularRendimiento(aux.montoFacturacion,aux.metrosCuadrados);
            Rendimiento *ren= new Rendimiento;
            ren->tipoRendimiento="Individual/Casa Matriz";
            ren->descripcion=aux.provincia+"-Sucursal: "+aux.codigoSucursal;
            ren->vRendimiento=rendimiento;
            agregarNodo(listaRendimientos, ren);
            rendimiento=0;
            }
            salir=false;
        }
        cursor=ptrSgte(listaAux,cursor);
    }
}

/*
=====================================================================================
4.1) rendimientoMatriz(Lista &listaAux, Lista &getPrimerNodolistaRendimientos): void.
=====================================================================================
*/
void rendimientoMatriz(Lista &listaAux, Lista &listaRendimientos){
Lista listaAuxMatriz;
crearLista(listaAuxMatriz);
listaAuxMatriz=copiarCasaMatriz(listaAux);//devuelve lista solo con las casas matrices
ordenarXMatriz(listaAuxMatriz);//ordena por numero de casa matriz
eliminarRep(listaAuxMatriz);//solo quedan las casas matrices sin repetir
float rendimiento=0, sumaMonto=0, sumaMetros=0, sumaMontoMadre=0, sumaMetrosMadre=0;
string casa="Casa Matriz Nro: ";
Sucursal aux1;
Sucursal aux2;

PtrNodo cursor1 = primerNodo(listaAuxMatriz);

while (cursor1 != NULL){
    aux1=  *((Sucursal*)cursor1->dato);
    PtrNodo cursor2 = primerNodo(listaAux);

    while (cursor2 != NULL){
        aux2= *((Sucursal*)cursor2->dato);
        if(aux2.casaMatriz=="0000"&&aux2.codigoSucursal==aux1.casaMatriz){ // esto es para sumar a el monto y metros de las matrizes la casa madre. Lo recorre una sola vez
            sumaMontoMadre=aux2.montoFacturacion;
            sumaMetrosMadre=aux2.metrosCuadrados;
        }
        if(aux1.casaMatriz==aux2.casaMatriz){
            sumaMonto=sumaMonto+aux2.montoFacturacion;
            sumaMetros=sumaMetros+aux2.metrosCuadrados;
        }//fin if
        cursor2=cursor2->ptrSgte;
    }//fin while 2

        sumaMonto+=sumaMontoMadre;
        sumaMetros+=sumaMetrosMadre;
        rendimiento=calcularRendimiento(sumaMonto, sumaMetros);

        Rendimiento *ren= new Rendimiento;
        ren->tipoRendimiento="Casa Matriz";
        ren->descripcion=casa+aux1.casaMatriz;
        ren->vRendimiento=rendimiento;
        ren->codigoSucursal=aux1.casaMatriz;
        agregarNodo(listaRendimientos, ren);
        cursor1=cursor1->ptrSgte;
        rendimiento=0;
        sumaMetros=0;
        sumaMonto=0;
        sumaMontoMadre=0;
        sumaMetrosMadre=0;
    }//fin while 1
}

/*
=================================================================================
4.2) ordenarXRendimiento(Lista &listaRendimientos): void.
=================================================================================
*/
void ordenarXRendimiento(Lista &listaRendimientos){
PtrNodo cursor = primerNodo(listaRendimientos);
PtrNodo sigPosicion=NULL;
Dato aux;

    while (cursor->ptrSgte != NULL) {
        sigPosicion = cursor->ptrSgte;
        while (sigPosicion != NULL) {

            if ((((Rendimiento*)sigPosicion->dato)->vRendimiento) > ((Rendimiento*)cursor->dato)->vRendimiento) {

                 aux = cursor->dato;
                cursor->dato= sigPosicion->dato;
                sigPosicion->dato= aux;
             }
            sigPosicion = sigPosicion->ptrSgte;
        }
        cursor = cursor->ptrSgte;
    }
}


/*
=================================================================================
4.3) ordenarXMatriz(Lista &listaTemp): void.dadatoto
=================================================================================
*/
void ordenarXMatriz(Lista &listaTemp){
PtrNodo cursor = primerNodo(listaTemp);
PtrNodo sigPosicion=NULL;
Dato aux;

    while (cursor->ptrSgte != NULL) {
        sigPosicion = cursor->ptrSgte;
        while (sigPosicion != NULL) {
            if ((((Sucursal*)sigPosicion->dato)->casaMatriz) < ((Sucursal*)cursor->dato)->casaMatriz) {
                 aux = cursor->dato;
                cursor->dato= sigPosicion->dato;
                sigPosicion->dato= aux;
             }
            sigPosicion = sigPosicion->ptrSgte;
        }
        cursor = cursor->ptrSgte;
    }
}
/*
=================================================================================
4.4) copiarCasaMatriz(Lista &listaAux): Lista.
Se copia y genera una listaTemp de la listaAux para elimianr posteriormente las
casas matrices repetidas y así poder generar una lista con la cual comparar la
listaAux.
=================================================================================
*/
Lista copiarCasaMatriz(Lista &listaAux){
PtrNodo cursor = primerNodo(listaAux);
Sucursal aux;
Lista listaTemp;
crearLista(listaTemp);
string auxCodigo="";
int auxArticulos=0;
string auxMatriz="";
float auxMonto=0, auxMetros=0;
string auxProvincia="";

    while(cursor !=NULL){
    aux=*(Sucursal*)cursor->dato;
    Sucursal *suc= new Sucursal;
    crear(*suc);

    auxCodigo=aux.codigoSucursal;
    auxProvincia=aux.provincia;
    auxArticulos=aux.cantidadArticulos;
    auxMonto=aux.montoFacturacion;
    auxMetros=aux.metrosCuadrados;
    auxMatriz=aux.casaMatriz;
    //solo se copian a la listaTemp las casas matrices no las individuales
    //int lengthOfString = string.size();
    if(aux.casaMatriz!="0000"){//preguntamos las sucursales que sean matrices o dependientes de otras sucursales
    setCodigoSucursal(*suc,auxCodigo);
    setProvincia(*suc,aux.provincia);
    setCantidadArticulos(*suc,auxArticulos);
    setMontoFacturacion(*suc,auxMonto);
    setMetrosCuadrados(*suc,auxMetros);
    setCasaMatriz(*suc,auxMatriz);
    agregarNodo(listaTemp, suc);//agregamos al final de la lista
    }
     cursor=ptrSgte(listaAux,cursor);
     eliminar(*suc);//se libera el espacio de memoria
    }
    return listaTemp;
}

/*
=================================================================================
4.5) eliminarRep(Lista &listaAuxMatriz): void.
Se eliminan las casas matrices repetidas.
=================================================================================
*/
void eliminarRep(Lista &listaAuxMatriz){
PtrNodo cursor = primerNodo(listaAuxMatriz);
PtrNodo sigPosicion=NULL;

    while (cursor != NULL) {
        sigPosicion = cursor->ptrSgte;
        while (sigPosicion != NULL) {
            if ((((Sucursal*)sigPosicion->dato)->casaMatriz) == ((Sucursal*)cursor->dato)->casaMatriz) {
                eliminarNodo(listaAuxMatriz,sigPosicion);
             }
            sigPosicion = sigPosicion->ptrSgte;
        }
        cursor = cursor->ptrSgte;
    }
}

/*
=================================================================================
4.6) imprimirListaRendimiento(Lista &listaRendimientos): void.
=================================================================================
*/
void imprimirListaRendimiento(Lista &listaRendimientos){
PtrNodo cursor=primerNodo(listaRendimientos);
cout <<"\n================================================================= \n";
cout <<"\t    RANKING RENDIMIENTO INDIVIDUAL Y C.MATRIZ  \n";
cout <<"================================================================= \n";

    while(cursor!= NULL){
        Rendimiento* r=(Rendimiento*)cursor->dato;
        cout<<"Rendimiento...: "<<r->tipoRendimiento<<endl;
        cout<<"Descripcion...: "<<r->descripcion<<endl;
        cout<<"Rendimento....: "<<fixed<<setprecision(2)<<r->vRendimiento<<endl;
        cout <<"================================================================= \n";
        cursor=ptrSgte(listaRendimientos,cursor);
    }
}

/**
=================================================================================
4.7) eliminarRendimientos(Lista &listaRendimientos): void.
Libero el espacio de memoria solicitado y elimino la lista de reporte rendimiento.
=================================================================================
*/
void eliminarRendimiento(Lista &listaRendimientos){
PtrNodo cursor=primerNodo(listaRendimientos);
    while(cursor != NULL){
        delete (Rendimiento*)cursor->dato;
        cursor=ptrSgte(listaRendimientos, cursor);
    }
    eliminarLista(listaRendimientos);
}

/*
=================================================================================
5.0) imprimirLista(Lista &listaSucursales): void.
Imprime la lista ORIGINAL.
=================================================================================
*/
void imprimirLista(Lista &listaSucursales){
PtrNodo cursor=primerNodo(listaSucursales);
cout <<"\n=============================================== \n";
cout <<"\t\t    LISTA  \n";
cout <<"=============================================== \n";

    while(cursor!= NULL){
     Sucursal* s=(Sucursal*)cursor->dato;
        cout<<"Codigo.............: "<<s->codigoSucursal<<endl;
        cout<<"Provincia..........: "<<s->provincia<<endl;
        cout<<"Cantidad Articulos.: "<<s->cantidadArticulos<<endl;
        cout<<"Monto Facturacion..: "<<fixed<<setprecision(2)<<s->montoFacturacion<<endl;
        cout<<"Metros Cuadrados...: "<<fixed<<setprecision(2)<<s->metrosCuadrados<<endl;
        cout<<"Casa Matriz........: "<<s->casaMatriz<<endl;
       cout <<"================================ \n";
        cursor=ptrSgte(listaSucursales,cursor);
    }
}

/*
=================================================================================
6.0) esNumero(): bool.
Preguntamos si el resultado es el correcto, si lo es pasamos y devolvemos que
esNumero es true, sino limpiamos y eliminamos el buffer y devolvemos falso.
=================================================================================
*/
bool esNumero(){
    bool resultado=true;
    /* Si algo no fue bien durante la lectura o se ingreso disntinto a un int */
    if (!std::cin.good()){
        /* Borramos el indicador de error */
        std::cin.clear();
        /* Ignoramos lo que tecleamos hasta el fin de el input */
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        /* Devolvermos falso, para que no haga el switch case. */
        resultado=false;
    }
    return resultado;
}

/**
=================================================================================
6.1) eliminarProvincias(Lista &listaProvincias): void.
Libero el espacio de memoria solicitado y elimino la lista de Provincias.
=================================================================================
*/
void eliminarProvincias(Lista &listaProvincias){
PtrNodo cursor=primerNodo(listaProvincias);
    while(cursor != NULL){
        delete (Provincia*)cursor->dato;
        cursor=ptrSgte(listaProvincias, cursor);
    }
    eliminarLista(listaProvincias);
}

