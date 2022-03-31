/*
	Villeda Patricio Arón Alejandro
	2BV1 - Estructrua de Datos
	Instituto Politecnico nacional - ESCOM
	Ingeniería en Inteligencía Artificial
*/

//LIBRERIAS USADAS
#include <iostream>
#include <queue>
using namespace std;

//ESTRUCTURA
typedef struct
{
    string Nombre;
    float Precio;
    int id;
}   Elemento;

//PROTOTIPOS
void CambiarOrden(queue<Elemento>Primario, queue<Elemento>Secundario);
void ModificarOrden(queue<Elemento>* Primario);

void Registro(Elemento *elemento);
Elemento RegistroMedio(Elemento *elemento);
void RegistroFinal(Elemento *elemento);
void AgregarPosicion(short int Posicion, short int *NumeroValores, queue<Elemento> *ColaAuxiliar, queue<Elemento> *ColaPrincipal, queue<Elemento> *ColaPrincipalAuxiliar, Elemento *elemento, short int *NumeroElementosPrincipal, short int *NumeroElementosAuxiliar);
void Impresion(short int NumeroValores, queue<Elemento> ColaAuxiliar, queue<Elemento> ColaPrincipal, queue<Elemento> ColaPrincipalAuxiliar, Elemento elemento, short int NumeroElementosPrincipal, short int NumeroElementosSecundario);
void ImpresionInversa(short int NumeroValores, queue<Elemento> ColaAuxiliar, queue<Elemento> ColaPrincipal, queue<Elemento> ColaPrincipalAuxiliar, Elemento elemento, short int NumeroElementosPrincipal, short int NumeroElementosSecundario);




int main()
{

//VARIABLES
    queue<Elemento>ColaPrincipal;             //ColaPrincipal: <queue> Es la cola principal
    queue<Elemento>ColaPrincipalAuxiliar;     //ColaPrincipalAuxiliar: <queue> Es la cola secundaria de la principal
    queue<Elemento>ColaAuxiliar;              //ColaAuxiliar: <queue> Es la cola auxiliar
    short int Respuesta;                    //Respuesta: <short int> Lee la seleccion del usuario al menu
    short int NumeroValores;                //NumeroValores: <short int> Registra el número de elementos total dentro de pila, función similar  a <queue>.size();
    short int Posicion;                     //Posicion: <short int> Registra la posicion a ingresar dentro de la pila
    short int NumeroElementosPrincipal;     //NumeroElementosPrincipal: <short int> registra cuantos elementos hay dentro de la cola principal
    short int NumeroElementosSecundario;    //NumeroElementosSecundario: <short int> registra cuantos elementos hay dentro de la cola secundaria
    string Palabra;                         //Palabra: <string> Lee el dato a almacenar en ls pilas
    Elemento elemento;
    Elemento tmp;

//MENÚ
    do
    {

    //OPERACIONES DE SISTEMA
        system("cls");

        cout<< "*********************\n";
        cout<< "\tCOLAS\n";
        cout<< "*********************\n";

        cout<<"MENU"<< "\t\tElementos ingresados: " << NumeroValores<< endl;
        cout<<"\t[1]. Agregar palabra al inicio"<< endl;
        cout<<"\t[2]. Agregar palabra al final"<< endl;
        cout<<"\t[3]. Agregar palabra en posicion N"<< endl;
        cout<<"\t[4]. Imprimir de inicio a fin"<< endl;
        cout<<"\t[5]. Imprimir de fin a inicio"<< endl;
        cout<<"\t[6]. Eliminar al inicio"<< endl;
        cout<<"\t[7]. Eliminar al final"<< endl;
        cout<<"\t[8]. Eliminar en la posicion N"<< endl;
        cout<<"\t[9]. Salir"<< endl;
        cout<<"\tRespuesta: ";
        cin>> Respuesta;

        switch(Respuesta)
        {
            case 1:
                Registro(&elemento);
                ColaPrincipal.push(elemento);


                cout<< "\n\tDatos introducidos: "<< endl;
                NumeroValores = NumeroValores + 1;

                elemento = ColaPrincipal.back();
                cout<< "\t\tNombre: "<< elemento.Nombre<< endl;
                cout<< "\t\tPrecio: "<< elemento.Precio<< endl;
                cout<< "\t\tID: "<< elemento.id<< endl;

                NumeroElementosPrincipal = ColaPrincipal.size();

            break;

            case 2:
                RegistroFinal(&elemento);
                ColaAuxiliar.push(elemento);

                cout<< "\n\tDatos introducidos: "<< endl;
                NumeroValores = NumeroValores + 1;

                elemento = ColaAuxiliar.back();
                cout<< "\t\tNombre: "<< elemento.Nombre<< endl;
                cout<< "\t\tPrecio: "<< elemento.Precio<< endl;
                cout<< "\t\tID: "<< elemento.id<< endl;

                NumeroElementosSecundario = ColaAuxiliar.size();
            break;

            case 3:
            //[3.1] REGISTRO DE LA POSICION DEL DATO DENTRO DE LA COLA
                cout<< "\n\tIngrese la posicion a agregar: "; cin>> Posicion;
                AgregarPosicion(Posicion, &NumeroValores, &ColaAuxiliar, &ColaPrincipal, &ColaPrincipalAuxiliar, &elemento, &NumeroElementosPrincipal, &NumeroElementosSecundario);
            break;

            case 4:

            Impresion(NumeroValores, ColaAuxiliar, ColaPrincipal, ColaPrincipalAuxiliar, elemento, NumeroElementosPrincipal, NumeroElementosSecundario);
            break;




            case 5:
                ImpresionInversa(NumeroValores, ColaAuxiliar, ColaPrincipal, ColaPrincipalAuxiliar, elemento, NumeroElementosPrincipal, NumeroElementosSecundario);
            break;

            case 6:

        //[6] ELIMINAR AL INICIO
            //[6.1] ELIMINAMOS EL PRIMER ELEMENTO EXISTENTE
                if(ColaPrincipal.empty() == 0) //Si la cola principal no está vacia, entonces...
                {
                    elemento = ColaPrincipal.front();
                    cout<< "\n\t\tElemento '"<< elemento.Nombre<< "' eliminado"<< endl;
                    ColaPrincipal.pop();
                    NumeroElementosPrincipal--;
                    NumeroValores = NumeroValores - 1;
                }

                else //Si la cola principal está vacia...
                {
                    if(ColaAuxiliar.empty() == 1)   //Y si la cola auxiliar está vacia, entonces...
                    {
                        cout<<"\n\t\tNo hay elementos, cola vacia"<< endl;
                    }

                    else    //Y si la cola auxiliar no está vacia, entonces.
                    {
                        ModificarOrden(&ColaAuxiliar);
                        elemento = ColaAuxiliar.front();
                        cout<< "\n\t\tElemento '"<< elemento.Nombre<< "' eliminado"<< endl;
                        ColaAuxiliar.pop();
                        ModificarOrden(&ColaAuxiliar);
                        NumeroElementosSecundario--;
                        NumeroValores = NumeroValores - 1;
                    }

                }
            break;

            case 7:
        //[7] ELIMINAR AL FINAL
            //[7.1] ELIMINAMOS EL PRIMER ELEMENTO EXISTENTE
                if(ColaAuxiliar.empty() == 0) //Si la cola auxiliar no está vacia, entonces...
                {
                    elemento = ColaAuxiliar.front();
                    cout<< "\n\t\tElemento '"<< elemento.Nombre<< "' eliminado"<< endl;
                    ColaAuxiliar.pop();
                    NumeroElementosSecundario--;
                    NumeroValores = NumeroValores - 1;
                }

                else ////Si la cola auxiliar está vacia...
                {

                    if(ColaPrincipal.empty() == 1) //Y la cola principal tambien, entonces...
                    {
                        cout<<"\n\t\tNo hay elementos, cola vacia"<< endl;
                    }

                    else    //Y la cola principal no, entonces...
                    {
                        ModificarOrden(&ColaPrincipal);
                        elemento = ColaPrincipal.front();
                        cout<< "\n\t\tElemento '"<< elemento.Nombre<< "' eliminado"<< endl;
                        ColaPrincipal.pop();
                        ModificarOrden(&ColaPrincipal);
                        NumeroElementosPrincipal--;
                        NumeroValores = NumeroValores - 1;
                    }
                }
            break;

            case 8:
        //[8] Eliminar en la posicion N

            //[8.0.1] EN CASO DE NO HABER ELEMENTOS, LA FUNCION SE CIERRA
                if(NumeroValores == 0)
                {
                    cout<< "\n\t\tNo hay elementos"<< endl;
                    break;
                }

            //[8.1] REGISTRO DE LA POSICION DEL DATO DENTRO DE LA COLA
                cout<< "\n\tIngrese la posicion a eliminar: "; cin>> Posicion;

                if((Posicion < 1) || (Posicion >= NumeroValores)) //En caso de dar un valor menor a 1 o mayor a NumeroValores, termina la funcion
                {
                    cout<< "\n\t\tSeleccione un valor entre el 1 y "<< NumeroValores<< endl;
                    break;
                }

                ModificarOrden(&ColaAuxiliar);  //Ordenamos la cola auxiliar

            //[8.2] UNION DE LA COLA PRINCIPAL Y LA AUXILIAR
                for(int i = NumeroElementosPrincipal + 1; i <= NumeroValores; i++)
                {
                    ColaPrincipal.push(ColaAuxiliar.front());
                    ColaAuxiliar.pop();
                }

            //[8.3] PASAMOS LOS DATOS DENTRO DE LA COLA A LA COLA SECUNDARIA
                for(short int i = 1; i <= NumeroValores; i++)
                {
                //[8.3.1] AL LLEGAR EN LA POSICION, ELIMINAMOS AL ELEMENTO SELECCIONADO
                    if(i == Posicion)
                    {
                        elemento = ColaPrincipal.front();
                        cout<< "\n\t\tElemento '"<< elemento.Nombre<< "' eliminado"<< endl;
                        ColaPrincipal.pop();
                    }
                //[8.3.2] SI NO LLEGAMOS AL ELEEMNTO, CONTINUAMOS HASTA FINALIZAR
                    else
                    {
                        ColaPrincipalAuxiliar.push(ColaPrincipal.front());
                        ColaPrincipal.pop();
                    }
                }

                NumeroValores--;    //Restamos un elemento al número de elementos totales


            //[8.4] REGRESAMOS LOS VALORES DE LA COLA AUXILIAR A LA PRINCIPAL
                for(int i = 1; i <= NumeroValores; i++)
                {
                    ColaPrincipal.push(ColaPrincipalAuxiliar.front());
                    ColaPrincipalAuxiliar.pop();
                }

            //[3.6] ESTABLECEMOS VALORES PARA CADA COLA
                if(Posicion <= NumeroElementosPrincipal) {NumeroElementosPrincipal--;}
                else {NumeroElementosSecundario--;}

            //[3.7] PASAMOS LOS VALORES DE LA COLA PRINCIPAL A SU PROPIA AUXILIAR CON TAL DE GUARDARLO
                for(int i = 1; i <= NumeroElementosPrincipal; i++)
                {
                    ColaPrincipalAuxiliar.push(ColaPrincipal.front());
                    ColaPrincipal.pop();
                }

            //[3.8] EL RESTO SE PASA A LA AUXILIAR
                for(int i = NumeroElementosPrincipal + 1; i <= NumeroValores; i++)
                {
                    ColaAuxiliar.push(ColaPrincipal.front());
                    ColaPrincipal.pop();
                }

                ModificarOrden(&ColaAuxiliar);  //Reordenamos la cola auxiliar

            //[3.8] REGRESAMOS LOS VALORES A LA COLA PRINCIPAL
                for(int i = 1; i <= NumeroElementosPrincipal; i++)
                {
                    ColaPrincipal.push(ColaPrincipalAuxiliar.front());
                    ColaPrincipalAuxiliar.pop();
                }
            break;

            case 9:
                cout<< "\n\t\tGracias, hasta luego"<< endl;
            break;

            default:
                cout<< "\n\t\tSeleccione otra opcion"<< endl;
            break;

        }
        cout<< "\n\n\t";
        system("pause");
    }   while(Respuesta != 9);
	return 0;
}

void CambiarOrden(queue<Elemento>Primario, queue<Elemento>Secundario)
{
    if(Primario.size() >= 1)
    {
        Elemento elemento;
        Elemento ValorGuardado = Primario.front();
        Primario.pop();
        CambiarOrden(Primario, Secundario);
        Secundario.push(ValorGuardado);
        elemento = Secundario.back();

        cout<< "\t\tNombre: "<< elemento.Nombre<< endl;
        cout<< "\t\tPrecio: "<< elemento.Precio<< endl;
        cout<< "\t\tID: "<< elemento.id<< endl<< endl;
    }
}

void ModificarOrden(queue<Elemento> *Primario)
{
    if(Primario->size() >= 1)
    {
        Elemento ValorGuardado = Primario->front();
        Primario->pop();
        ModificarOrden(Primario);
        Primario->push(ValorGuardado);
    }
}

void Registro(Elemento *elemento)
{
//[1.1] REGISTRO DEL DATO DENTRO DE COLA
    cout<< "\n\tRegistro de datos: "<< endl;
    cout<< "\t\tNombre: "; cin>> elemento->Nombre;
    cout<< "\t\tPrecio: "; cin>> elemento->Precio;
    elemento->id = rand()%101;
}

void RegistroFinal(Elemento *elemento)
{
//[2.1] REGISTRO DEL DATO DENTRO DE COLA AUXILIAR
    cout<< "\n\tRegistro de datos: "<< endl;
    cout<< "\t\tNombre: "; cin>> elemento->Nombre;
    cout<< "\t\tPrecio: "; cin>> elemento->Precio;
    elemento->id = rand()%101;
}

Elemento RegistroMedio(Elemento *elemento)
{
//[3.4] REGISTRO DEL DATO DENTRO DE COLA AUXILIAR
    cout<< "\n\tRegistro de datos: "<< endl;
    cout<< "\t\tNombre: "; cin>> elemento->Nombre;
    cout<< "\t\tPrecio: "; cin>> elemento->Precio;
    elemento->id = rand()%101;

    return *elemento;
}

void AgregarPosicion(short int Posicion, short int *NumeroValores, queue<Elemento> *ColaAuxiliar, queue<Elemento> *ColaPrincipal, queue<Elemento> *ColaPrincipalAuxiliar,  Elemento *elemento, short int *NumeroElementosPrincipal, short int *NumeroElementosAuxiliar)
{
    if((Posicion < 1) || (Posicion >= *NumeroValores)) //En caso de dar un valor menor a 1 o mayor a NumeroValores, termina la funcion
    {
        cout<< "\n\t\tSeleccione un valor entre el 1 y "<< *NumeroValores<< endl;
    }

    ModificarOrden(ColaAuxiliar);  //Ordenamos la cola auxiliar

//[3.2] UNION DE LA COLA PRINCIPALE Y LA AUXILIAR
    for(int i = *NumeroElementosPrincipal + 1; i <= *NumeroValores; i++)
    {
        ColaPrincipal->push(ColaAuxiliar->front());
        ColaAuxiliar->pop();
    }

//[3.3] PASAMOS LOS DATOS DENTRO DE LA COLA A LA COLA SECUNDARIA
    for(int i = 1; i <= *NumeroValores; i++)
    {
        ColaPrincipalAuxiliar->push(ColaPrincipal->front());
        ColaPrincipal->pop();
    }

//[3.5] REGRESAMOS LOS VALORES DE LA COLA AUXILIAR A LA PRINCIPAL
    Elemento elementoGuardado;
    *NumeroValores = *NumeroValores + 1;

    for(int i = 1; i <= *NumeroValores; i++)
    {
    //[3.5.1] SI LA POSICION ES IGUAL AL CONTADOR, SE COLOCA EL VALOR DADO
        if(i == Posicion)
        {
        //[3.4] REGISTRO DEL VALOR
            elementoGuardado = RegistroMedio(elemento);
            ColaPrincipal->push(elementoGuardado);


        }

    //[3.5.2] DE LO CONTRARÍO, SE PASA LA COLA NORMALMENTE
        else
        {
            ColaPrincipal->push(ColaPrincipalAuxiliar->front());
            ColaPrincipalAuxiliar->pop();
        }

        cout<< endl;
        cout<< "______________________"<< endl;
        elementoGuardado = ColaPrincipal->back();
        cout<< "\t\tNombre: "<< elementoGuardado.Nombre<< endl;
        cout<< "\t\tPrecio: "<< elementoGuardado.Precio<< endl;
        cout<< "\t\tID: "<< elementoGuardado.id<< endl;
    }

//[3.6] ESTABLECEMOS VALORES PARA CADA COLA
    if(Posicion <= *NumeroElementosPrincipal)
    {
        *NumeroElementosPrincipal = *NumeroElementosPrincipal + 1;
        cout<< "AAAA INICIAL: "<< *NumeroElementosPrincipal;
    }
    else
    {
        *NumeroElementosAuxiliar = *NumeroElementosAuxiliar + 1;
        cout<< "AAAA FINAÑL: "<< *NumeroElementosAuxiliar;
    }

//[3.7] PASAMOS LOS VALORES DE LA COLA PRINCIPAL A SU PROPIA AUXILIAR CON TAL DE GUARDARLO
    for(int i = 1; i <= *NumeroElementosPrincipal; i++)
    {
        ColaPrincipalAuxiliar->push(ColaPrincipal->front());
        ColaPrincipal->pop();
    }

//[3.8] EL RESTO SE PASA A LA AUXILIAR
    cout<< "\n\nAuxiliar: ";
    for(int i = *NumeroElementosPrincipal + 1; i <= *NumeroValores; i++)
    {
        ColaAuxiliar->push(ColaPrincipal->front());
        ColaPrincipal->pop();
    }

    ModificarOrden(ColaAuxiliar);

//[3.9] REGRESAMOS LOS VALORES A LA COLA PRINCIPAL
    cout<< "\n\nPrincipal: ";
    for(int i = 1; i <= *NumeroElementosPrincipal; i++)
    {
        ColaPrincipal->push(ColaPrincipalAuxiliar->front());
        ColaPrincipalAuxiliar->pop();
    }
}

void Impresion(short int NumeroValores, queue<Elemento> ColaAuxiliar, queue<Elemento> ColaPrincipal, queue<Elemento> ColaPrincipalAuxiliar, Elemento elemento, short int NumeroElementosPrincipal, short int NumeroElementosSecundario)
{
//[4.1] UNIMOS TODAS LAS COLAS GENERADAS EN CASO DE EXISTIR
    if(ColaAuxiliar.empty() == 0)   //Si no está vacia la cola secundaria, entonces...
    {
        ModificarOrden(&ColaAuxiliar);

        for(int i = NumeroElementosPrincipal + 1; i <= NumeroValores; i++)
        {
            ColaPrincipal.push(ColaAuxiliar.front());
            ColaAuxiliar.pop();
        }
    }

//[4.2] IMPRIMIMOS LA COLA GENERAL
    cout<<"\n\tImpresion de cola [INICIO - FIN]"<< endl;
    for(int i = 1; i <= NumeroValores; i++)
    {
        ColaPrincipalAuxiliar.push(ColaPrincipal.front());

        elemento = ColaPrincipalAuxiliar.back();
        cout<< "\t\tNombre: "<< elemento.Nombre<< endl;
        cout<< "\t\tPrecio: "<< elemento.Precio<< endl;
        cout<< "\t\tID: "<< elemento.id<< endl<< endl;

        ColaPrincipal.pop();
    }

    if(ColaPrincipalAuxiliar.empty() == 1)
    {
        cout<< "\n\t\tCola vacia"<< endl;
    }

//[4.3] REGRESAMOS LOS VALORES A LA COLA PRINCIPAL
    for(int i = 1; i <= NumeroElementosPrincipal; i++)
    {
        ColaPrincipal.push(ColaPrincipalAuxiliar.front());
        ColaPrincipalAuxiliar.pop();
    }

//[4.4] REGRESAMOS LOS VALORES A LA COLA AUXILIAE
    for(int i = NumeroElementosPrincipal + 1; i <= NumeroValores; i++)
    {
        ColaAuxiliar.push(ColaPrincipalAuxiliar.front());
        ColaPrincipalAuxiliar.pop();
    }

    ModificarOrden(&ColaAuxiliar);
}

void ImpresionInversa(short int NumeroValores, queue<Elemento> ColaAuxiliar, queue<Elemento> ColaPrincipal, queue<Elemento> ColaPrincipalAuxiliar, Elemento elemento, short int NumeroElementosPrincipal, short int NumeroElementosSecundario)
{
//[5.1] UNIMOS TODAS LAS COLAS GENERADAS EN CASO DE EXISTIR
    if(ColaAuxiliar.empty() == 0)   //Si no está vacia la cola secundaria, entonces...
    {
        ModificarOrden(&ColaAuxiliar);

        for(int i = NumeroElementosPrincipal + 1; i <= NumeroValores; i++)
        {
            ColaPrincipal.push(ColaAuxiliar.front());
            ColaAuxiliar.pop();
        }
    }

//[5.2] CAMBIAMOS EL ORDEN
    cout<<"\n\tImpresion de cola [FIN - INICIO]"<< endl;
    CambiarOrden(ColaPrincipal, ColaAuxiliar);

//[5.3] REGRESAMOS LOS VALORES A LA COLA PRINCIPAL SECUNDARIA, ESTO SÓLO PARA APARTARLOS Y MOVER LOS OTROS
    for(int i = 1; i <= NumeroElementosPrincipal; i++)
    {
        ColaPrincipalAuxiliar.push(ColaPrincipal.front());
        ColaPrincipal.pop();
    }

//[5.4] REGRESAMOS LOS VALORES A LA COLA AUXILIAR
    for(int i = 1; i <= NumeroElementosPrincipal; i++)
    {
        ColaPrincipal.push(ColaPrincipalAuxiliar.front());
        ColaPrincipalAuxiliar.pop();
    }

//[5.3] REGRESAMOS LOS VALORES A LA COLA AUXILIAE
    for(int i = NumeroElementosPrincipal + 1; i <= NumeroValores; i++)
    {
        ColaAuxiliar.push(ColaPrincipal.front());
        ColaPrincipal.pop();
    }

    ModificarOrden(&ColaAuxiliar);
}
