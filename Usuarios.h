#ifndef USUARIOS_H
#define USUARIOS_H

#include <iostream>

using namespace std;

class usuarios{ //clase para la creacion de usuarios

private:

    string cc; //identidad del usuario
    string clave; //clave del usuario
    float saldo; //saldo del usuario

public:

    usuarios(string, string, float); //constructor
    string getCC(); //retorna la identidad
    string getClave(); //retorna la clave
    float getSaldo();//retorna el saldo
    void consul_saldo(); //metodo para consultar el saldo del usuario
    void reti_saldo(); //metodo para retirar saldo
    ~usuarios(); //destructor

};

#endif // USUARIOS_H
