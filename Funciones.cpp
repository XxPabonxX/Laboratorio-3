#include "funciones.h"

void codificar(int semilla , int met, string nom , string sali)
{
    string texto_en_bin=texto_bin(nom);
    if (met==1)
    {
        int posi=0,posi2=0, len=texto_en_bin.length(), unos=0, ceros=0;
        string textofin,texto,textoaux,letra;
        int limite_ite=(len-1)/semilla, limite_interno;
        for (int i=0;i<=limite_ite;i++)
        {
            if(i==0)//si es la primera vez se invierte todo
            {
                texto="";
                for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                {
                    if (posi>=len)
                        break;
                    letra=texto_en_bin[posi];
                    texto+=letra;
                    posi++;
                }
                textoaux="";
                for (int j=0;j<=semilla-1;j++)
                {
                    letra=texto[j];
                    if(letra=="1")
                        textoaux+="0";
                    else
                        textoaux+="1";
                }
                textofin+=textoaux;
                posi=0;
            }
            else//si no es la primera vez revisar el bloque anterior
            {
                texto="";
                for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                {
                    if (posi>=len)
                        break;
                    letra=texto_en_bin[posi];
                    texto+=letra;
                    posi++;
                }
                textoaux="";
                ceros=0;
                unos=0;
                for (int j=0;j<=semilla-1;j++)//se cuentan cuantos 0's y 1's hay
                {
                    letra=texto[j];
                    if(letra=="1")
                        unos++;
                    else
                        ceros++;
                }
                if(unos>ceros)//si hay mas 1's que 0's
                {
                    texto="";
                    for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                    {
                        if (posi>=len)
                            break;
                        letra=texto_en_bin[posi];
                        texto+=letra;
                        posi++;
                    }
                    limite_interno=texto.length();
                    posi-=semilla;
                    posi2=0;
                    for(int k=0;k<=limite_interno-1;k++)
                    {
                        letra=texto[k];
                        if(posi2==2)
                        {
                            if(letra=="1")
                                letra="0";
                            else
                                letra="1";
                            posi2=-1;
                        }
                        textoaux+=letra;
                        posi2++;
                    }
                }
                else if(ceros>unos)//si hay mas 0's que 1's
                {
                    texto="";
                    for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                    {
                        if (posi>=len)
                            break;
                        letra=texto_en_bin[posi];
                        texto+=letra;
                        posi++;
                    }
                    limite_interno=texto.length();
                    posi-=semilla;
                    posi2=0;
                    for(int k=0;k<=limite_interno-1;k++)
                    {
                        letra=texto[k];
                        if(posi2==1)
                        {
                            if(letra=="1")
                                letra="0";
                            else
                                letra="1";
                            posi2=-1;
                        }
                        textoaux+=letra;
                        posi2++;
                    }
                }
                else//si hay igual cantidad de 1's que de 0's se invierte todo
                {
                    texto="";
                    for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                    {
                        if (posi>=len)
                            break;
                        letra=texto_en_bin[posi];
                        texto+=letra;
                        posi++;
                    }
                    limite_interno=texto.length();
                    posi-=semilla;
                    for (int k=0;k<=limite_interno-1;k++)
                    {
                        letra=texto[k];
                        if(letra=="1")
                            letra="0";
                        else
                            letra="1";
                        textoaux+=letra;
                    }
                }
                textofin+=textoaux;
            }
        }
        save(sali,textofin,met,semilla);
    }
    else
    {
        int posi=0,len=texto_en_bin.length(),nueva_pos;
        string textofin,texto,textoaux,letra;
        char pasochar;
        int limite_ite=(len-1)/semilla,limite_interno;
        for (int i=0;i<=limite_ite;i++)
        {
            texto="";
            for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
            {
                if (posi>=len)
                    break;
                letra=texto_en_bin[posi];
                texto+=letra;
                posi++;
            }
            limite_interno=texto.length();
            textoaux=texto;
            for(int k=0;k<=limite_interno-1;k++)
            {
                pasochar=texto[k];
                nueva_pos=k+1;
                if(nueva_pos>limite_interno-1)
                    nueva_pos=0;
                if(pasochar=='1' or pasochar=='0')
                    textoaux[nueva_pos]=pasochar;
            }
            textofin+=textoaux;
        }
        save(sali, textofin, met,semilla);
    }
}

void decodificar (int semilla , int met, string nom , string sali)
{
    string texto_codificado=lect_copy(nom), textonormal;
    if (met==1)
    {
        int posi=0,posi2=0, len=texto_codificado.length(), unos=0, ceros=0;
           string textofin,texto,textoaux,textoaux2,letra;
           int limite_ite=(len-1)/semilla,limite_interno;
           for (int i=0;i<=limite_ite;i++)
           {
               if(i==0)//si es la primera vez se invierte todo
               {
                   texto="";
                   for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                   {
                       if (posi>=len)
                           break;
                       letra=texto_codificado[posi];
                       texto+=letra;
                       posi++;
                   }
                   textoaux="";
                   for (int j=0;j<=semilla-1;j++)
                   {
                       letra=texto[j];
                       if(letra=="1")
                           textoaux+="0";
                       else
                           textoaux+="1";
                   }
                   textofin+=textoaux;
                   textoaux2=textoaux;
                   posi=0;
               }
               else//si no es la primera vez revisar el bloque anterior
               {
                   texto="";
                   for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                   {
                       if (posi>=len)
                           break;
                       letra=texto_codificado[posi];
                       texto+=letra;
                       posi++;
                   }
                   ceros=0;
                   unos=0;
                   for (int j=0;j<=semilla-1;j++)//se cuentan cuantos 0's y 1's hay
                   {
                       letra=textoaux2[j];
                       if(letra=="1")
                           unos++;
                       else
                           ceros++;
                   }
                   textoaux2="";
                   if(unos>ceros)//si hay mas 1's que 0's
                   {
                       texto="";
                       for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                       {
                           if (posi>=len)
                               break;
                           letra=texto_codificado[posi];
                           texto+=letra;
                           posi++;
                       }
                       limite_interno=texto.length();
                       posi-=semilla;
                       posi2=0;
                       for(int k=0;k<=limite_interno-1;k++)
                       {
                           letra=texto[k];
                           if(posi2==2)
                           {
                               if(letra=="1")
                                   letra="0";
                               else
                                   letra="1";
                               posi2=-1;
                           }
                           textoaux2+=letra;
                           posi2++;
                       }
                   }
                   else if(ceros>unos)//si hay mas 0's que 1's
                   {
                       texto="";
                       for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                       {
                           if (posi>=len)
                               break;
                           letra=texto_codificado[posi];
                           texto+=letra;
                           posi++;
                       }
                       limite_interno=texto.length();
                       posi-=semilla;
                       posi2=0;
                       for(int k=0;k<=limite_interno-1;k++)
                       {
                           letra=texto[k];
                           if(posi2==1)
                           {
                               if(letra=="1")
                                   letra="0";
                               else
                                   letra="1";
                               posi2=-1;
                           }
                           textoaux2+=letra;
                           posi2++;
                       }
                   }
                   else//si hay igual cantidad de 1's que de 0's se invierte todo
                   {
                       texto="";
                       for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                       {
                           if (posi>=len)
                               break;
                           letra=texto_codificado[posi];
                           texto+=letra;
                           posi++;
                       }
                       limite_interno=texto.length();
                       posi-=semilla;
                       for (int k=0;k<=limite_interno-1;k++)
                       {
                           letra=texto[k];
                           if(letra=="1")
                               letra="0";
                           else
                               letra="1";
                           textoaux2+=letra;
                       }
                   }
                   textofin+=textoaux2;
               }
           }
           textonormal=texto_deco(textofin);
           saveDeco(sali, textonormal);
    }
    else
    {
        int posi=0,len=texto_codificado.length(),nueva_pos;
            string textofin,texto,textoaux,letra;
            char pasochar;
            int limite_ite=(len-1)/semilla,limite_interno;
            for (int i=0;i<=limite_ite;i++)
            {
                texto="";
                for(int k=0;k<=semilla-1;k++)//se saca el bloque segun la semilla y se guarda en texto
                {
                    if (posi>=len)
                        break;
                    letra=texto_codificado[posi];
                    texto+=letra;
                    posi++;
                }
                limite_interno=texto.length();
                textoaux=texto;
                for(int k=0;k<=limite_interno-1;k++)
                {
                    pasochar=texto[k];
                    nueva_pos=k-1;
                    if(nueva_pos<0)
                        nueva_pos=limite_interno-1;
                    if(pasochar=='1' or pasochar=='0')
                        textoaux[nueva_pos]=pasochar;
                }
                textofin+=textoaux;
            }
            textonormal=texto_deco(textofin);
            saveDeco(sali, textonormal);
    }
}

void lect_print(string nombre)
{
    ifstream archivo;
    string texto;
    archivo.open("../practica3/archivostxt/"+nombre, ios::in);//archivo en modo lectura
    if(archivo.fail())
    {
        cout<<"El archivo no se pudo abrir"<<endl;
        exit(1);
    }

    while(!archivo.eof())//Mientras no llegue a en End Of File
    {
        getline(archivo,texto);
        cout<<texto<<endl;
    }
    archivo.close();
}

void save(string nombre, string texto, int metodo, int semilla)
{
    ofstream escritura;
    string met=to_string(metodo), semi=to_string(semilla);
    string nombre_completo=nombre+"_met"+met+"_sem"+semi+".txt";
    escritura.open("../practica3/archivostxt/"+nombre_completo);// Crear o abrir un archivo para escritura
    escritura<<texto;
    escritura.close();
}

void saveDeco(string nombre, string texto)
{
    ofstream escritura;
    string nombre_completo=nombre+"(decodificado)"+".txt";
    escritura.open("../practica3/archivostxt/"+nombre_completo);// Crear o abrir un archivo para escritura
    escritura<<texto;
    escritura.close();
}

string binario(int digi)
{
    string binario, caracter,binar;
    for (int i=0;i<8;i++)
    {
        caracter=to_string(digi%2);
        binario+=caracter;
        digi/=2;
    }
    for (int i=7;i>=0;i--)
    {
        caracter=binario[i];
        binar+=caracter;
    }
    return binar;
}

string texto_bin(string nombre)
{
    ifstream archivo;
    string texto,caracter,bin;
    char caracter2;
    int numero;
    archivo.open("../practica3/archivostxt/"+nombre, ios::in);//archivo en modo lectura
    if(archivo.fail())
    {
        cout<<"El archivo no se pudo abrir"<<endl;
        exit(1);
    }

    while(!archivo.eof())//Mientras no llegue a en End Of File
    {
        caracter2=archivo.get();
        if (archivo.eof())
            break;
        numero=caracter2;
        bin=binario(numero);
        texto+=bin;
    }
    archivo.close();
    return texto;
}

string texto_deco(string binario)
{
    int posi=0,len=binario.length();
    string textofin, texto, letra,texto2;
    int limite_ite=(len-1)/8, numero, suma;
    char caracter;
    for (int i=0;i<=limite_ite;i++)
    {
        texto="";
        suma=0;
        for(int k=0;k<=7;k++)//se saca el bloque segun la semilla y se guarda en texto
        {
            letra=binario[posi];
            texto+=letra;
            posi++;
        }
        texto2="";
        for(int k=7;k>=0;k--)
        {
            letra=texto[k];
            texto2+=letra;
        }
        texto=texto2;
        for (int k=0;k<=7;k++)
        {
            letra=texto[k];
            if(letra=="1")
            {
                numero= pow(2,k);
                suma+=numero;
            }
        }
        caracter=suma;
        textofin+=caracter;
    }
    return textofin;
}

string lect_copy(string nombre)
{
    ifstream archivo;
    string texto, textofin;
    archivo.open("../practica3/archivostxt/"+nombre, ios::in);//archivo en modo lectura
    if(archivo.fail())
    {
        cout<<"El archivo no se pudo abrir"<<endl;
        exit(1);
    }

    while(!archivo.eof())//Mientras no llegue a en End Of File
    {
        getline(archivo,texto);
        textofin+=texto+"\n";
    }
    archivo.close();
    int len=textofin.length()-1;
    textofin.erase(len);
    return textofin;
}

void leerPasw(char frase[])
{
    int i=0;
    cout.flush();
    do
    {
        frase[i] = (unsigned char)getch();
        if(frase[i]!=8)  // no es retroceso
        {
            cout << '*';  // muestra por pantalla
            i++;
        }
        else if(i>0)    // es retroceso y hay caracteres
        {
            cout << (char)8 << (char)32 << (char)8;
            i--;  //el caracter a borrar e el backspace
        }
        cout.flush();
    }
    while(frase[i-1]!=13);  // si presiona ENTER
    frase[i-1] = NULL;
    cout << endl;
}

string convertir(char c)
{
    return string(1,c);
}

bool contra_correcta(string contra, string nick)
{
    bool esta=false;
    decodificar(4, 2, "sudo_met2_sem4.txt", "temporal");
    string sudo_normal=lect_copy("temporal(decodificado).txt");
    remove("../practica3/archivostxt/temporal(decodificado).txt");
    string texto="", texto2="";
    char letra;
    int longi=(sudo_normal.length())-1, posicion=0;
    for (int i=0; i<=longi; i++)
    {
        letra=sudo_normal[i];
        if (letra==';')
        {
            posicion=i+1;
            break;
        }
        texto2+=letra;
    }
    if(texto2==nick)
    {
        for (int i=posicion; i<=longi; i++)
        {
            letra=sudo_normal[i];
            texto+=letra;
        }
        if(texto==contra)
        {
            esta=true;
        }
        else
        {
            esta=false;
        }
    }
    else
    {
        esta=false;
    }
    return esta;
}

bool veri_doc(string documento)
{
    int longi=documento.length()-1;
    char letra;
    bool correcto;
    for (int i=0; i<=longi; i++)
    {
        letra=documento[i];
        if(letra<46 or letra>57)
        {
            correcto=false;
            break;
        }
        else
        {
            correcto=true;
        }
    }
    return correcto;
}

bool veri_clave(string clave)
{
    int longi=clave.length();
    bool correcto;
    if (longi<6)
    {
        correcto=false;
    }
    else
    {
        correcto=true;
    }
    return correcto;
}

bool existe_usuario(string doc)
{
    bool esta=false;
    decodificar(4, 2, "usuarios_met2_sem4.txt", "temporal");
    string usuarios_normal=lect_copy("temporal(decodificado).txt");
    remove("../practica3/archivostxt/temporal(decodificado).txt");
    if(usuarios_normal.find(doc)!=std::string::npos)
        esta=true;
    else
        esta=false;
    return esta;
}

std::string a_string_de_float(float num)
{
    std::ostringstream buff;
    buff<<num;
    return buff.str();
}

string texto_binario(string texto)
{
    int longi=texto.length()-1, numero;
    char caracter;
    string texto2, bin;
    for (int i=0; i<=longi; i++)
    {
        caracter=texto[i];
        numero=caracter;
        bin=binario(numero);
        texto2+=bin;
    }
    return texto2;
}

void crear_usu(string doc, string clave, float saldo)
{
    decodificar(4, 2, "usuarios_met2_sem4.txt", "temporal");
    string usuarios_normal=lect_copy("temporal(decodificado).txt");
    remove("../practica3/archivostxt/temporal(decodificado).txt");
    string sald=a_string_de_float(saldo);
    int longi=usuarios_normal.length()-1;
    char letrafin=usuarios_normal[longi];
    if(letrafin!='\n')
    {
        usuarios_normal+="\n";
    }
    string texto=doc+";"+clave+";"+sald;
    usuarios_normal+=texto;
    save("usuarios_txt",usuarios_normal, 2, 4);
    codificar(4, 2, "usuarios_txt_met2_sem4.txt", "temporal");
    usuarios_normal=lect_copy("temporal_met2_sem4.txt");
    remove("../practica3/archivostxt/temporal_met2_sem4.txt");
    remove("../practica3/archivostxt/usuarios_txt_met2_sem4.txt");
    ofstream escritura;
    escritura.open("../practica3/archivostxt/usuarios_met2_sem4.txt");
    escritura<<usuarios_normal;
    escritura.close();
}

bool contra_correcta_user(string documento, string clave)
{
    decodificar(4, 2, "usuarios_met2_sem4.txt", "temporal");
    string usuarios_normal=lect_copy("temporal(decodificado).txt");
    remove("../practica3/archivostxt/temporal(decodificado).txt");
    string texto, texto2;
    char letra;
    bool esta=false;
    int longi=usuarios_normal.length()-1, posi=0;
    for (int i=0; i<=longi; i++)
    {
        texto="";
        for (int k=posi; k<=longi; k++)//se saca linea a linea
        {
            letra=usuarios_normal[k];
            if(letra=='\n')
            {
                posi+=2;
                break;
            }
            texto+=letra;
            posi=k;
        }
        if(texto.find(documento)!=std::string::npos)
        {
            if(texto.find(clave)!=std::string::npos)
            {
                esta=true;
                return esta;
            }
        }
    }
    return esta;
}

float saldo_user(string documento, string clave)
{
    decodificar(4, 2, "usuarios_met2_sem4.txt", "temporal");
    string usuarios_normal=lect_copy("temporal(decodificado).txt");
    remove("../practica3/archivostxt/temporal(decodificado).txt");
    string texto, texto2;
    char letra;
    float num=0;
    int longi=usuarios_normal.length()-1, posi=0, posi2,conta;
    for (int i=0; i<=longi; i++)
    {
        texto="";
        for (int k=posi; k<=longi; k++)//se saca linea a linea
        {
            letra=usuarios_normal[k];
            if(letra=='\n')
            {
                posi+=2;
                break;
            }
            texto+=letra;
            posi=k;
        }
        if(texto.find(documento)!=std::string::npos)
        {
            if(texto.find(clave)!=std::string::npos)
            {
                posi2=0;
                conta=0;
                int longi2=texto.length()-1;
                for (int k=0; k<=longi2; k++)//se saca la posicion del 2do punto y coma
                {
                    letra=texto[k];
                    if(letra==';')
                    {
                        conta++;
                        if(conta==2)
                        {
                            posi2=k+1;
                            break;
                        }
                    }
                }

                texto2="";
                for (int k=posi2; k<=longi2; k++)//se saca el saldo
                {
                    letra=texto[k];
                    texto2+=letra;
                }
                num = std::stof(texto2);
                return num;
            }
        }
    }
    return num;
}

void actualizar_saldo(string documento, string clave, float saldo)
{
    decodificar(4, 2, "usuarios_met2_sem4.txt", "temporal");
    string usuarios_normal=lect_copy("temporal(decodificado).txt");
    remove("../practica3/archivostxt/temporal(decodificado).txt");
    string texto, texto2,textofin="", texto_sin_saldo, saldo_string=a_string_de_float(saldo);
    char letra;
    int longi=usuarios_normal.length()-1, posi=0, conta;
    for (int i=0; i<=longi/2; i++)
    {
        texto="";
        for (int k=posi; k<=longi; k++)//se saca linea a linea
        {
            letra=usuarios_normal[k];
            if(letra=='\n')
            {
                posi+=2;
                break;
            }
            texto+=letra;
            posi=k;
            if (posi==longi)
            {
                break;
            }
        }
        if(texto.find(documento)!=std::string::npos)
        {
            if(texto.find(clave)!=std::string::npos)
            {
                conta=0;
                int longi2=texto.length()-1;
                texto_sin_saldo="";
                for (int k=0; k<=longi2; k++)//se saca la posicion del 2do punto y coma
                {
                    letra=texto[k];
                    texto_sin_saldo+=letra;
                    if(letra==';')
                    {
                        conta++;
                        if(conta==2)
                        {
                            break;
                        }
                    }
                }
                texto_sin_saldo+=saldo_string;
                texto=texto_sin_saldo;
            }
        }
        if (posi==longi)
        {
            textofin+=texto;
            break;
        }
        else
        {
            textofin+=texto+"\n";
        }
    }
    save("textofin", textofin,2,4);
    codificar(4, 2, "textofin_met2_sem4.txt", "temporal");
    textofin=lect_copy("temporal_met2_sem4.txt");
    remove("../practica3/archivostxt/temporal_met2_sem4.txt");
    remove("../practica3/archivostxt/textofin_met2_sem4.txt");
    ofstream escritura;
    escritura.open("../practica3/archivostxt/usuarios_met2_sem4.txt");
    escritura<<textofin;
    escritura.close();
}
