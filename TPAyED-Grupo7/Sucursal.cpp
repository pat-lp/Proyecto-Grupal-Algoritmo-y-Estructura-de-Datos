#include "Sucursal.h"



void crear(Sucursal &sucursal){
    sucursal.codigoSucursal="";
    sucursal.provincia="";
    sucursal.cantidadArticulos=0;
    sucursal.montoFacturacion=0;
    sucursal.metrosCuadrados=1;
    sucursal.casaMatriz="";
}


void eliminar(Sucursal &sucursal){
}


void setCodigoSucursal(Sucursal &sucursal, string codigo){
        sucursal.codigoSucursal=codigo.substr(0,4);//Obtengo una subcadena a partir del caracter 0 y con una longitud de 4
}


string getCodigoSucursal(Sucursal &sucursal){
    return sucursal.codigoSucursal;
}


void setProvincia(Sucursal &sucursal, string provincia){
    sucursal.provincia=provincia;
}


string getProvincia(Sucursal &sucursal){
    return sucursal.provincia;
}


void setCantidadArticulos(Sucursal &sucursal, int cantidad){
    if(cantidad>=0){
    sucursal.cantidadArticulos=cantidad;
    }
}


int getCantidadArticulos(Sucursal &sucursal){
    return sucursal.cantidadArticulos;
}


void setMontoFacturacion(Sucursal &sucursal, float monto){
    if(monto>=0){
    sucursal.montoFacturacion=monto;
    }
}


float getMontoFacturacion(Sucursal &sucursal){
    return sucursal.montoFacturacion;
}


void setMetrosCuadrados(Sucursal &sucursal, float metros){
    if(metros>0){
        sucursal.metrosCuadrados=metros;
    }
}


float getMetrosCuadrados(Sucursal &sucursal){
    return sucursal.metrosCuadrados;
}

void setCasaMatriz(Sucursal &sucursal, string matriz){
    sucursal.casaMatriz=matriz.substr(0,4);//Obtengo una subcadena a partir del caracter 0 y con una longitud de 4
}

string getCasaMatriz(Sucursal &sucursal){
    return sucursal.casaMatriz;
}

float calcularRendimiento(float facturacion, float metros){
    if(metros > 0){
    return facturacion/metros;
    }
}
