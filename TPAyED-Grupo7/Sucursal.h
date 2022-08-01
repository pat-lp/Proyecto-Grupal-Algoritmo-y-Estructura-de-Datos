#ifndef SUCURSAL_H_INCLUDED
#define SUCURSAL_H_INCLUDED

#include <string>


using namespace std;

/*
AXIOMAS:
Aclaraci�n: Para c�digo de sucursal, cantidad de art�culos, monto de facturaci�n y casa matriz
se tomar�n los valores a partir del cero inclusive, a excepci�n de los metros cuadrados que ser�n
utilizados para el c�lculo de rendimiento cuyo valor se tomar� a partir del 1 inclusive.

C�digo de Sucursal: Numerico de 4 y >=0.
Provincia: Alfanumerico de 20.
Cantidad de art�culos: num�rico de 10 y >=0.
Monto: num�rico de 12 con 2 decimales y >=0.
Metros cuadrados: num�rico de 12 con 2 decimales y >0.
Casa Matriz: Numerico de 4 y >=0.
Rendimiento: facturacion/metros cuadrados.
*/

typedef struct{
    string codigoSucursal;
    string provincia;
    int cantidadArticulos;
    float montoFacturacion;
    float metrosCuadrados;
    string casaMatriz;
}Sucursal;


/*
=================================================================================
PRE: La Sucursal no debe haber sido creada ni destruido.
Algunos atributos quedan setteaddos: codigoSucursal=0, cantidadArticulos=0,
montoFacturaci�n=0, metrosCuadrados=1, casaMatriz=0.
POST: La Sucursal queda creada y puede ser usada.
=================================================================================
*/
void crear(Sucursal &sucursal);

/*
=================================================================================
PRE: Se creo una Sucursal con la primitiva crear.
POST: La Sucursal es eliminada.
=================================================================================
*/
void eliminar(Sucursal &sucursal);

/*
=================================================================================
PRE: Se creo una Sucursal con la primitiva crear.
El codigo de la sucursal debe cumplir con el axioma.
POST: El codigo de sucursal queda registrada en la Sucursal.
=================================================================================
*/
void setCodigoSucursal(Sucursal &sucursal, string codigo);

/*
=================================================================================
PRE: Se creo una Sucursal con la primitiva crear.
POST: Devuelve el codigo de la Sucursal.
=================================================================================
*/
string getCodigoSucursal(Sucursal &sucursal);

/*
=================================================================================
PRE: Se creo una Sucursal con la primitiva crear.
La provincia de ser con el formato Alfanumerico de 20.
POST: La provincia queda registrada en la Sucursal.
=================================================================================
*/
void setProvincia(Sucursal &sucursal, string provincia);

/*
=================================================================================
PRE: Se creo una Sucursal con la primitiva crear.
POST: Devuelve la provincia de la Sucursal.
=================================================================================
*/
string getProvincia(Sucursal &sucursal);

/*
=================================================================================
PRE: Se creo una Sucursal con la primitiva crear.
La cantidad de articulos debe cumplir con el axioma.
POST: La cantidad de articulos quedan registrados en la Sucursal.
=================================================================================
*/
void setCantidadArticulos(Sucursal &sucursal, int cantidad);

/*
=================================================================================
PRE: Se creo una Sucursal con la primitiva crear.
POST: Devuelve la cantidad de articulos de la Sucursal.
=================================================================================
*/
int getCantidadArticulos(Sucursal &sucursal);

/*
=================================================================================
PRE: Se creo una Sucursal con la primitiva crear.
El monto de la Sucursal debe cumplir con el axioma.
POST: El monto de la facturaci�n queda registrado en la Sucursal.
=================================================================================
*/
void setMontoFacturacion(Sucursal &sucursal, float monto);

/*
=================================================================================
PRE: Se creo una Sucursal con la primitiva crear.
POST: Devuelve el monto de la facturaci�n de la Sucursal.
=================================================================================
*/
float getMontoFacturacion(Sucursal &sucursal);

/*
=================================================================================
PRE: Se creo una Sucursal con la primitiva crear.
Los metros cuadrados deben cumplir con el axioma.
POST: Los metros cuadrados quedan registrados en la Sucursal,
=================================================================================
*/
void setMetrosCuadrados(Sucursal &sucursal, float metros);

/*
=================================================================================
PRE: Se creo una Sucursal con la primitiva crear.
POST: Devuelve los metros cuadrados de la Sucursal.
=================================================================================
*/
float getMetrosCuadrados(Sucursal &sucursal);

/*
=================================================================================
PRE: Se creo una Sucursal con la primitiva crear.
El n�mero de casa Matriz debe cumplir con el axioma.
POST: El n�mero de casa Matriz queda registrado en la Sucursal,
=================================================================================
*/
void setCasaMatriz(Sucursal &sucursal, string matriz);

/*
=================================================================================
PRE: Se creo una Sucursal con la primitiva crear.
POST: Devuelve el n�mero de casa Matriz.
=================================================================================
*/
string getCasaMatriz(Sucursal &sucursal);


/*
=================================================================================
PRE: Se creo una Sucursal con la primitiva crear.
Se tiene en cuenta que los metros cuadrados no pueden ser cero.
POST: Devuelve el rendimiento.
=================================================================================
*/
float calcularRendimiento(float facturacion, float metros);



#endif // SUCURSAL_H_INCLUDED
