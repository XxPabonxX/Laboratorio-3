#include <iostream>
#include "funciones.h"
#include "usuarios.h"

using namespace std;


/*
 * El programa utiliza un menu simple en el que el usuario selecciona que desea hacer
 * codificar, decodificar, etc. Una vez seleccionada una opcion el programa procede
 * a preguntarle al usuario las caracteristicas que desea por orden para poder llamar a
 * la funcion, cuando se piden los datos se indican que valores puede elegir y evita aceptar
 * ciertos valores (excepciones), finalmente realiza la accion pedida.
 *
 * NOTA PARA EL PROFESOR: deje algunos usuarios en comentarios, mi metodo de separacion fue mediante ; en los txt
 * el sudo era: elpepe;soyadmin, y los usuarios tenian la siguiente forma: documento;clave;saldo
 */

int main()
{
        int opcion;

        bool terminar=false;
        int term;
        while (terminar==false){

            cout<<"1 - Codificar un texto"<<endl;
            cout<<"2 - Decodificar un texto"<<endl;
            cout<<"3 - Sistema de cajero"<<endl;
            cout<<"4 - Salir del programa"<<endl<<endl;
            cout<<"Ingrese la opcion deseada: ";

            cin >> opcion;

            while ((opcion<1) || (opcion>4))
            {
                cout<<"Opcion invalida."<<endl;
                cout<<"Ingrese la opcion deseada: ";cin>>opcion;
            }

            switch(opcion)
            {
            //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            case 1: //codificacion de archivo de texto con cierta semilla
            {
                for (int i=0;i<=50;i++)
                {
                    cout<<endl;
                }
                string nombre,guardar;
                int semi, met;
                cout<<"Bienvenido al sistema de codificacion de texto"<<endl;
                cout<<"Digite el nombre de su archivo(sin extension): ";cin>>nombre;
                nombre+=".txt";//Se le agrega la extension
                cout<<"----------------------------------------------------------"<<endl;
                cout<<"Esto fue lo que se encontro en el archivo: "<<endl<<endl;
                lect_print(nombre);//se imprime el contenido del txt
                cout<<"----------------------------------------------------------"<<endl;
                cout<<"Ingrese que semilla desea usar para la codificacion(entre 2 y 20): ";cin>>semi;
                while ((semi<2) || (semi>20))
                {
                    cout<<"Ingrese que semilla desea usar para la codificacion(entre 1 y 20): ";cin>>semi;
                }
                cout<<endl;
                cout<<"Ingrese el metodo que desea usar para codificar (1 o 2): ";cin>>met;
                while ((met<1) || (met>2))
                {
                    cout<<"Ingrese el metodo que desea usar para codificar (1 o 2): ";cin>>met;
                }
                cout<<endl;
                cout<<"NOTA:Al nombre se le agregara el metodo y la semilla usadas por si se desea hacer una decodificacion."<<endl<<endl;
                cout<<"Ingrese el nombre del archivo en el que desea guardarlo(sin extension): ";cin>>guardar;
                codificar(semi,met,nombre,guardar);//se llama a la funcion que codifica con los datos recibidos
                cout<<"----------------------------------------------------------"<<endl;
                cout<<"Su texto fue codificado con el metodo "<<met<<" y la semilla "<<semi<<"."<<endl<<endl;
                cout<<endl<<endl;
                cout<<"Archivo guardado, ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
                while ((term<1) || (term>2))
                {
                    cout<<"Ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
                }
                if(term==1)
                {
                    terminar=true;
                }
                else
                {
                    terminar=false;
                    for (int i=0;i<=50;i++)
                    {
                        cout<<endl;
                    }
                }
            }
                break;
            //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            case 2: //Decodificar un archivo de texto con la misma semilla
            {
                for (int i=0;i<=50;i++)
                {
                    cout<<endl;
                }
                string nombre, textobin, texto_codi, letra, guardar;
                int semi, met;
                cout<<"Bienvenido al sistema de decodificacion de texto"<<endl;
                cout<<"Digite el nombre de el archivo(sin extension) que desea decodificar: ";cin>>nombre;
                nombre+=".txt";//Se le agrega la extension
                cout<<"Digite en que semilla se codifico originalmente el texto: ";cin>>semi;
                while ((semi<2) || (semi>20))
                {
                    cout<<"Digite en que semilla se codifico originalmente el texto: ";cin>>semi;
                }
                cout<<"Digite con que metodo se codifico originalmente el texto: ";cin>>met;
                while ((met<1) || (met>2))
                {
                    cout<<"Digite con que metodo se codifico originalmente el texto: ";cin>>met;
                }
                cout<<endl;
                cout<<"Ingrese el nombre del archivo en el que desea guardarlo(sin extension): ";cin>>guardar;
                decodificar(semi,met,nombre,guardar);//se llama a la funcion que decodifica con los datos recibidos
                cout<<"----------------------------------------------------------"<<endl;
                cout<<"Su texto fue decodificado."<<endl<<endl;
                cout<<endl<<endl;
                cout<<"Archivo guardado, ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
                while ((term<1) || (term>2))
                {
                    cout<<"Ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
                }
                if(term==1)
                {
                    terminar=true;
                }
                else
                {
                    terminar=false;
                    for (int i=0;i<=50;i++)
                    {
                        cout<<endl;
                    }
                }
            }
                break;
            //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            case 3: //Cajero
            {
                for (int i=0;i<=50;i++)
                {
                    cout<<endl;
                }
                cout<<"Bienvenido al sistema de cajero"<<endl;
                int elegir;
                cout<<"Como desea ingresar?"<<endl<<endl;
                cout<<"1 - Administrador"<<endl;
                cout<<"2 - Usuario"<<endl;
                cout<<"0 - Salir"<<endl<<endl;
                cout<<"Opcion: ";cin>>elegir;
                while((elegir<0) || (elegir>2))
                {
                    cout<<"Ingrese 1 o 2 (0 para salir): ";cin>>elegir;
                }

                switch (elegir)
                {
                //------------------------------------------------------------------------------------------------------------------------------------------------
                case 0: //salir
                {
                    terminar=true;
                }
                    break;
                //------------------------------------------------------------------------------------------------------------------------------------------------
                case 1: //Admin
                {
                    for (int i=0;i<=50;i++)
                    {
                        cout<<endl;
                    }
                    string user,letra, contra_string;
                    char password[30], caracter;
                    cout<<"Ingrese su informacion como administrador"<<endl<<endl;//nickname: elpepe - contraseña: soyadmin
                    cout<<"Ingrese su Nickname(Sensible a Mayus/Minus): ";cin>>user;
                    cout<<"Ingrese su contrasenha: ";
                    leerPasw(password);
                    contra_string="";
                    for (int i=0; i<=29;i++)//se pasa la contraseña de arreglo char a string normal
                    {
                        caracter=password[i];
                        if(caracter=='\0')
                        {
                            break;
                        }
                        letra=convertir(caracter);
                        contra_string+=letra;
                    }
                    bool correcta=contra_correcta(contra_string, user);
                    while (correcta==false)
                    {
                        cout<<"La contrasenha es incorrecta..."<<endl<<endl;
                        cout<<"Ingrese su contrasenha: ";
                        leerPasw(password);
                        contra_string="";
                        for (int i=0; i<=29;i++)//se pasa la contraseña de arreglo char a string normal
                        {
                            caracter=password[i];
                            if(caracter=='\0')
                            {
                                break;
                            }
                            letra=convertir(caracter);
                            contra_string+=letra;
                        }
                        correcta=contra_correcta(contra_string, user);
                    }
                    //Ya verificado que el usuario existe y es correcto
                    for (int i=0;i<=50;i++)
                    {
                        cout<<endl;
                    }

                    string cc, clave, digito;
                    float saldo;
                    bool verificacion, existe;
                    cout<<"Bienvenido al sistema de creacion de usuarios, a continuacion digite los datos que se le pidan."<<endl<<endl;

                    cout<<"Ingrese el documento de identidad del usuario: ";cin>>cc;
                    verificacion=veri_doc(cc);
                    while (verificacion==false)
                    {
                        cout<<"Error en el documento ingresado, debe ser solo numerico."<<endl;
                        cout<<"Ingrese el documento de identidad del usuario: ";cin>>cc;
                        verificacion=veri_doc(cc);
                    }
                    existe=existe_usuario(cc);
                    while (existe==true)
                    {
                        cout<<"Error en el documento ingresado, ya existe un usuario con ese documento."<<endl;
                        cout<<"Ingrese el documento de identidad del usuario: ";cin>>cc;
                        existe=existe_usuario(cc);
                    }

                    cout<<"Ingrese la clave para el usuario sin espacios (La clave se mostrara en pantalla): ";cin>>clave;
                    verificacion=veri_clave(clave);
                    while (verificacion==false)
                    {
                        cout<<"Error en la clave ingresado, debe tener minimo 6 caracteres."<<endl;
                        cout<<"Ingrese la clave para el usuario sin espacios (La clave se mostrara en pantalla): ";cin>>clave;
                        verificacion=veri_clave(clave);
                    }

                    cout<<"Ingrese el saldo del usuario: ";cin>>saldo;
                    while (saldo<0)
                    {
                        cout<<"El saldo tiene que ser mayor o igual a 0. "<<endl;
                        cout<<"Ingrese el saldo del usuario: ";cin>>saldo;
                    }

                    usuarios creado = usuarios(cc,clave,saldo);
                    crear_usu(creado.getCC(),creado.getClave(),creado.getSaldo());//se guarda el usuario en el archivo txt con los datos del objeto
                    cout<<"Usuario creado, ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
                    while ((term<1) || (term>2))
                    {
                        cout<<"Ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
                    }
                    if(term==1)
                    {
                        terminar=true;
                    }
                    else
                    {
                        terminar=false;
                        for (int i=0;i<=50;i++)
                        {
                            cout<<endl;
                        }
                    }
                }
                    break;
                //------------------------------------------------------------------------------------------------------------------------------------------------
                case 2: //User
                {
                    for (int i=0;i<=50;i++)
                    {
                        cout<<endl;
                    }
                    string doc,letra, contra_string;
                    char password[30], caracter;
                    bool existe, coherente;
                    cout<<"Ingrese su informacion como usuario"<<endl<<endl;//doc: 1089358678 clave: mellamocarlos (Uno de los usuarios, para saber mas decodificar usuarios_met1_sem4.txt)
                    cout<<"Ingrese su documento de identidad: ";cin>>doc;
                    cout<<"Ingrese su clave: ";//falta hacerla asteriskos y ver si vale la pena hacerlo con el doc o la clave
                    leerPasw(password);
                    contra_string="";
                    for (int i=0; i<=29;i++)//se pasa la contraseña de arreglo char a string normal
                    {
                        caracter=password[i];
                        if(caracter=='\0')
                        {
                            break;
                        }
                        letra=convertir(caracter);
                        contra_string+=letra;
                    }
                    existe=existe_usuario(doc);
                    coherente=contra_correcta_user(doc,contra_string);
                    while (existe==false)
                    {
                        cout<<"El usuario ingresado no existe, intentelo de nuevo."<<endl;
                        cout<<"Ingrese su documento de identidad: ";cin>>doc;
                        cout<<"Ingrese su clave: ";//falta hacerla asteriskos y ver si vale la pena hacerlo con el doc o la clave
                        leerPasw(password);
                        contra_string="";
                        for (int i=0; i<=29;i++)//se pasa la contraseña de arreglo char a string normal
                        {
                            caracter=password[i];
                            if(caracter=='\0')
                            {
                                break;
                            }
                            letra=convertir(caracter);
                            contra_string+=letra;
                        }
                        existe=existe_usuario(doc);
                        coherente=contra_correcta_user(doc,contra_string);
                    }
                    while (coherente==false)
                    {
                        cout<<"La clave o el documento son erroneos."<<endl;
                        cout<<"Ingrese su documento de identidad: ";cin>>doc;
                        cout<<"Ingrese su clave: ";//falta hacerla asteriskos y ver si vale la pena hacerlo con el doc o la clave
                        leerPasw(password);
                        contra_string="";
                        for (int i=0; i<=29;i++)//se pasa la contraseña de arreglo char a string normal
                        {
                            caracter=password[i];
                            if(caracter=='\0')
                            {
                                break;
                            }
                            letra=convertir(caracter);
                            contra_string+=letra;
                        }
                        existe=existe_usuario(doc);
                        coherente=contra_correcta_user(doc,contra_string);
                    }
                    for (int i=0;i<=50;i++)
                    {
                        cout<<endl;
                    }

                    int eleccion;
                    cout<<"Inicio sesion correctamente!"<<endl;
                    float saldo=saldo_user(doc,contra_string);
                    usuarios usu_actu = usuarios(doc,contra_string,saldo);
                    if (saldo<=1000) //no se le permite al usuarios realizar acciones
                    {
                        cout<<endl;
                        cout<<"Actualmente su saldo es menor o igual a 1000 pesos, por lo tanto no puede realizar acciones hasta que no agregue mas dinero a la cuenta. "<<endl;
                        cout<<"Accion terminada, ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
                        while ((term<1) || (term>2))
                        {
                            cout<<"Ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
                        }
                        if(term==1)
                        {
                            terminar=true;
                        }
                        else
                        {
                            terminar=false;
                            for (int i=0;i<=50;i++)
                            {
                                cout<<endl;
                            }
                        }
                    }
                    else
                    {
                        cout<<"Que desea hacer? (Cada accion le costara 1000 pesos)"<<endl<<endl;
                        cout<<"1 - Consultar saldo"<<endl;
                        cout<<"2 - Retirar dinero"<<endl;
                        cout<<"0 - Salir"<<endl<<endl;
                        cout<<"Digite su opcion: ";cin>>eleccion;
                        while((eleccion<0) || (eleccion>2))
                        {
                            cout<<"Ingrese 1 o 2 (0 para salir): ";cin>>eleccion;
                        }

                        switch (eleccion)
                        {
                        //------------------------------------------------------------------------
                        case 0: //salir
                        {
                            terminar=true;
                        }
                            break;
                        //------------------------------------------------------------------------
                        case 1: //Consultar saldo
                        {
                            for (int i=0;i<=50;i++)
                            {
                                cout<<endl;
                            }
                            usu_actu.consul_saldo();
                            cout<<"Accion terminada, ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
                            while ((term<1) || (term>2))
                            {
                                cout<<"Ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
                            }
                            if(term==1)
                            {
                                terminar=true;
                            }
                            else
                            {
                                terminar=false;
                                for (int i=0;i<=50;i++)
                                {
                                    cout<<endl;
                                }
                            }
                        }
                            break;
                        //------------------------------------------------------------------------
                        case 2: //Retirar dinero
                        {
                            for (int i=0;i<=50;i++)
                            {
                                cout<<endl;
                            }
                            usu_actu.reti_saldo();
                            cout<<"Accion terminada, ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
                            while ((term<1) || (term>2))
                            {
                                cout<<"Ingrese 1 para terminar o 2 para seguir usando el programa: ";cin>>term;
                            }
                            if(term==1)
                            {
                                terminar=true;
                            }
                            else
                            {
                                terminar=false;
                                for (int i=0;i<=50;i++)
                                {
                                    cout<<endl;
                                }
                            }
                        }
                            break;
                        }
                    }
                }
                    break;
                }
            }
                break;
            //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            case 4: //Salir
            {
                terminar=true;
            }
                break;
            }
        }
        return 0;
}
