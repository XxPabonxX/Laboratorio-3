#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include <math.h>
#include <conio.h>
#include <sstream>
#include <cstdio>

using namespace std;

void codificar(int semilla , int metodo, string nombre , string salida);//codifica un archivo de txt que este en la carpeta de archivostxt
void decodificar(int semilla , int metodo, string nombre , string salida);//decodifica un archivo codificado previamente
void lect_print(string nombre_archivo);//lee e imprime todo lo que hay en un txt
void save(string nombre,string texto,int metodo,int semilla);//guarda la codificacion en un archivo
void saveDeco(string nombre,string texto);//guarda la decodificacion en un archivo
void leerPasw(char frase[]);//Lee la contraseña y la reemplaza con asteriscos
void crear_usu(string doc, string clave, float saldo);//Falta crea el usuario en una linea de texto nueva en el documento encriptado
void actualizar_saldo(string documento, string clave, float saldo);//Falta Actualiza el saldo de un usuario
bool contra_correcta(string contra, string nick);//Verifica que la contraseña coincida con el usuario y sea correcta para el admin
bool veri_doc(string documento);//Verifica que el documento para el nuevo usuario tenga sentido
bool veri_clave(string clave);//Verifica que la contraseña tenga sentido
bool existe_usuario(string doc);//Verifica que el usuario ingresado existe
bool contra_correcta_user(string documento, string clave);//Verifica que la contraseña coincida con el usuario y sea correcta para los usuarios
float saldo_user(string documento, string clave);//Saca el saldo del usuario en cuestion
string a_string_de_float(float num);//Pasa un float a string
string binario(int digito);//pasa un numero a binario
string texto_bin(string nombre_archivo);//pasa el .txt a binario
string texto_deco(string texto_para_volver_legible);//pasa el texto de binario a lenguaje legible
string lect_copy(string nombre_archivo);//copia todo el texto codificado a un string para poder decodificarlo despues
string convertir(char c);//Convierte un caracter de char a string
string texto_binario(string texto);//pasa un string a binario

#endif // FUNCIONES_H
