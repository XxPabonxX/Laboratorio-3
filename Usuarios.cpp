#include "usuarios.h"
#include "funciones.h"

usuarios::usuarios(string _cc, string _clave, float _saldo)
{
    cc= _cc;
    clave= _clave;
    saldo= _saldo;
}

string usuarios::getCC()
{
    return cc;
}
string usuarios::getClave()
{
    return clave;
}

float usuarios::getSaldo()
{
    return saldo;
}

void usuarios::consul_saldo()
{
    float saldo_copy;
    saldo_copy=saldo-1000;
    cout<<"Actualmente su saldo es: "<<saldo_copy<<endl;
    cout<<"Tenga en cuenta que al saldo mostrado ya se le han quitado los 1000 pesos"<<endl<<endl;
    actualizar_saldo(cc,clave,saldo_copy);
}

void usuarios::reti_saldo()
{
    float sacar, saldo_copy=saldo;
    cout<<"Actualmente su saldo es: "<<saldo<<endl;
    cout<<"Tenga en cuenta que la accion cuesta 1000 pesos"<<endl;
    cout<<"Ingrese cuanto desea retirar: ";cin>>sacar;
    while(sacar<=0)
    {
        cout<<"Se debe sacar una cantidad mayor a 0"<<endl;
        cout<<"Ingrese cuanto desea retirar: ";cin>>sacar;
    }
    sacar+=1000;
    saldo_copy-=sacar;
    while (saldo_copy<0)
    {
        cout<<endl;
        cout<<"No es posible sacar esa cantidad con su saldo actual, recuerde que la transaccion cuesta 1000 pesos."<<endl;
        cout<<"Actualmente su saldo es: "<<saldo<<endl;
        cout<<"Ingrese cuanto desea retirar: ";cin>>sacar;
        saldo_copy=saldo;
        sacar+=1000;
        saldo_copy-=sacar;
    }
    cout<<endl;
    cout<<"Su nuevo saldo es: "<<saldo_copy<<endl;
    actualizar_saldo(cc,clave,saldo_copy);
}

usuarios::~usuarios()
{
}
