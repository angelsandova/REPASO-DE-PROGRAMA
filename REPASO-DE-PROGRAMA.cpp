//lista doblemente enlazada
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h> //librerias
#include <stdint.h>
#include<iomanip>
#include<fstream>
#include<cstdlib>//exit
#include <windows.h>

using namespace std;
void dibujarCuadro(int x1,int y1,int x2,int y2);
void gotoxy(int x,int y);

using namespace std;
//clase Nodo
class Cnodo{
    public:
    string Dato;
    Cnodo *Siguiente;
    Cnodo *Anterior;
    //prototipos
    void InsertarAdelante(string Dt);
    void Insertarmedi(string Dt,int p);
    string eliminarSiguiente();
};
//funciones de nodo
void Cnodo::Insertarmedi(string Dt,int p)
{
    Cnodo*nd=new Cnodo;
    Cnodo *aux=this;
    nd->Dato=Dt;
    int r=0;
    do{
        getch();
        aux=aux->Siguiente;
        r++;
      }while(r==p-1);
    nd->Anterior=aux->Anterior;
    nd->Siguiente=aux->Siguiente;
    aux->Siguiente=nd;
    nd->Siguiente->Anterior=nd;

}
void Cnodo::InsertarAdelante(string Dt){
    Cnodo*nd=new Cnodo;
    nd->Dato=Dt;
    nd->Anterior=this;
    nd->Siguiente=this->Siguiente;
    this->Siguiente=nd;
    nd->Siguiente->Anterior=nd;
}
string Cnodo::eliminarSiguiente(){
    string temp;
    Cnodo* nodotemp=this->Siguiente;
    temp=nodotemp->Dato;
    this->Siguiente->Siguiente->Anterior=this;
    this->Siguiente=this->Siguiente->Siguiente;
    delete nodotemp;
    return temp;
}
//clase lista
class Clista{
    private:
    Cnodo *inicio;
    Cnodo *final;
    public:
    Clista();
    ~Clista();
    void insertarpocicion(string Dato);
    void Insertarinicio(string Dato);
    void Insertarfinal(string Dato);
    string eliminarinicio();
    string eliminarfinal();
    int size();//tamaño
    bool isempty();//esta vacia
    bool isFull();//esta llena
    void Imprimir();
    string Tos();
    void eliminar(string Dato);
    void Buscar(string Dato);
    void vacia();
    void Primero();
    void Ultimo();
    void Anterior();
};
//funciones de lista
/*creo en el constructor los nodos iniciales que
van a estar apuntandose mutuamente y su salidas como su entrada a null*/
Clista::Clista(){
    inicio=new Cnodo;
    final=new Cnodo;
    inicio->Siguiente = final;
    final->Anterior=inicio;
    inicio->Anterior=NULL;
    final->Siguiente=NULL;
}
void Clista::insertarpocicion(string Dato)
{
    Cnodo *aux2=inicio->Siguiente;
    Cnodo *aux=inicio;
    string Dato2;
    Cnodo *auxAnt=nullptr;
    bool band=true;
    int i=0,p=0;
    cout<<"\t";
    while(aux2!=final)
    {
        i++;
        cout<<"\n\t<-"<<i<<"-"<<aux2->Dato<<" -> ";
        aux2=aux2->Siguiente;

    }
    if(i>=1)
    {
     cout<<"\n\tAdelante de cual pocision lo ponemos:";cin>>p;
     if(p<=i)
     {

         return inicio->Insertarmedi(Dato,p);
     }else{cout<<"\n\tNO HAY ESA POCISION................";getch();}
        }else
        {
            return inicio->InsertarAdelante(Dato);
        }

}
void Clista::Anterior()
{
    Cnodo *nd = final->Anterior;
    cout<<"\n\tEl Ultimo es este:";
    while (nd != inicio)
    {
        cout<<nd->Dato<<" -><- ";
        nd=nd->Anterior;
    }

}
void Clista::Ultimo()
{
     Cnodo *nd = final->Anterior;
     cout<<"\tEl Ultimo Nombre es:"<<nd->Dato;
}
void Clista::Primero()
{
    Cnodo *nd = inicio->Siguiente;
        cout<<"\tEl Primer Nombre es:"<<nd->Dato;


}
 void Clista::vacia()
 {
    Cnodo *nd = inicio->Siguiente;
    int i=0;
    while(nd!=final)
    {
        nd=nd->Siguiente;
        i++;
    }
    if (i>=1){
        cout<<"\n\tEsta llena";
    }
    if(i<=0)
    {
        cout<<"\n\tEsta vacia";
    }

 }
void Clista::Buscar(string Dato)
{
    Cnodo *aux=inicio;
    Cnodo *auxAnt=nullptr;
    bool band=true;
    string Dato2;
    int i=0;
    while(aux->Siguiente!=final)
    {
        aux=aux->Siguiente;
        i++;
    }
    if(i>=1)
    {
        while(aux and band)
        {
            if(Dato==aux->Dato)
            {
            cout<<"\n\tSi esta el nombre:"<<Dato;
            Dato=Dato2;
                band=false;
            }
            else
            {
                auxAnt=aux;
                aux=aux->Siguiente;
            }
        }
        if(Dato!=Dato2)
        {
            cout<<"\n\tNo esta el nombre:"<<Dato;
        }

        }else
        {
            cout<<"\n\tLista esta vacia........";
        }

}
void Clista::eliminar(string Dato)
{
    Cnodo *aux=inicio;
    Cnodo *auxAnt=nullptr;
    bool band=true;
    int i=0;
    while(aux->Siguiente!=final)
    {
        aux=aux->Siguiente;
        i++;
    }
    if(i>=1)
    {
        while(aux and band)
        {
            if(Dato==aux->Dato)
            {
                band=false;
            }
            else
            {
                auxAnt=aux;
                aux=aux->Siguiente;
            }
        }
        if(aux==nullptr)
        {
            inicio=inicio->Siguiente;
            delete aux;
        }
        else if(aux->Siguiente==nullptr)
        {
            auxAnt->Siguiente=nullptr;
            delete aux;
        }else
        {
            auxAnt->Siguiente=aux->Siguiente;
            delete aux;
        }
        }
        if(i<=0)
        {
            cout<<"\n\tNo se encuentra el nombre........";
        }
}
string Clista::Tos(){
    Cnodo* nd=final->Anterior;
    cout<<"El numero de hasta arriba es: "<<nd->Dato<<endl;
}
void Clista::Insertarinicio(string Dato){
   return inicio->InsertarAdelante(Dato);
}
void Clista::Insertarfinal(string Dato){
    final->Anterior->InsertarAdelante(Dato);
}
string Clista::eliminarinicio(){
    return inicio->eliminarSiguiente();
}
string Clista::eliminarfinal(){
    return final->Anterior->Anterior->eliminarSiguiente();
}
int Clista::size(){
    int i=0;
    Cnodo *nd = inicio->Siguiente;
    while(nd!=final)
    {
        nd=nd->Siguiente;
        i++;
    }
    cout<<"\n\tEl Tamano de la Lista es: "<<i<<endl;
    return i;
}
bool Clista::isempty(){
    Cnodo *nd = inicio->Siguiente;
    while(nd!=final)
    {
        nd=nd->Siguiente;
    }
    if (nd==final){
        return true;
    }
    else
        return false;
}
bool Clista::isFull(){
    Cnodo *nd = inicio->Siguiente;
    while(nd!=final)
    {
        nd=nd->Siguiente;
    }
    if (nd==final){
        return true;
    }
    else
        return false;
}
void Clista::Imprimir(){
    Cnodo *nd = inicio->Siguiente;
    cout<<"\n\t";
    while (nd != final)
    {   cout<<"  [ID-Origen-Destino-Peso]"<<endl;
        cout<<"\n\t<-"<<nd->Dato<<" ->";
        nd=nd->Siguiente;
    }
}
Clista::~Clista(){
    while (inicio->Siguiente!=final)
    {
        eliminarinicio();
    }
}


int main()//funcion principal
{
    int s=1,d;
	Clista lista;
    do{
     system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	system("COLOR F0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(0,1);
	ifstream archivoClientesEntrada;
    archivoClientesEntrada.open("clientes.txt",ios::in);
    if(!archivoClientesEntrada)
    {ofstream archivoClienteSalida;
    archivoClienteSalida.open("clientes.txt",ios::out);
    }
	cout<<"\n\t\t\t &LISTA DOBLEMENTE LIGADA&\n\n";
	cout<<"\t\t\t\t   -MENU-\n";
	cout<<"\t1-insertar\n\t2-eliminar\n\t3-buscar\n\t4-vaciar\n\t5-inicializa\n\t6-primero\n\t7-ultimo\n\t8-anterior\n\t9-tamano\n\t10-vaciar todo\n\t11-mostrar lista\n\t12-salir\n\trespuesta:";cin>>d;
	switch(d)
	{

    case 1:
        {
            int y;
            string x,A,Z,B,Y,Q;
             system("cls");
             system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	system("COLOR A0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(0,1);
	cout<<"\n\t\t\t &LISTA SIMPLEMENTE LIGADA&\n\n";
	cout<<"\t\t\t\t   -Insertar-\n";
	cout<<"\tCual es el ID:";cin>>A;
	cout<<"\tCual es su Origen:";cin>>Z;
	cout<<"\tCual es su Destino:";cin>>B;
	cout<<"\tCual es su peso:";cin>>Y;
	Q=("-");
	x=A+Q+Z+Q+B+Q+Y;
	//cout<<"\tCual nombre del perro y raza:";cin>>x;
	cout<<"\t1-Al inicio\n\t2-Al final\n\t3-Escojer:\n\t";cin>>y;
	switch(y)
	{
    case 1:
        {
            lista.Insertarinicio(x);
            break;
        }
    case 2:
        {
            lista.Insertarfinal(x);
            break;
        }
    case 3:
        {
            lista.insertarpocicion(x);
            break;
        }
    default:
        {
            cout<<"\t-ERROR DE NUMERO-\n";
        }

	}

            break;
        }
    case 2:
        {
            int y;
             system("cls");
             system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	system("COLOR D0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(0,1);
	cout<<"\n\t\t\t &LISTA SIMPLEMENTE LIGADA&\n\n";
	cout<<"\t\t\t\t   -Eliminar-\n";
	cout<<"\tDe que manera quieres eliminar:\n\t1-Al inicio\n\t2-Al final\n\t3-Escojer\n\t";cin>>y;
	switch(y)
	{
    case 1:
        {
            lista.eliminarinicio();
            break;
        }
    case 2:
        {
            lista.eliminarfinal();
            break;
        }
    case 3:
        {string x,z,y,a;
        lista.Imprimir();
        cout<<"\n\tNombre de mascota quieres eliminar:";cin>>z;
        cout<<"\n\tRaza de la  mascota quieres eliminar:";cin>>y;
        a=(" ");
        x=z+a+y;
            lista.eliminar(x);
            lista.Imprimir();
            break;
        }
    default:
        {
            cout<<"\t-ERROR DE NUMERO-\n";
            getch();
        }
	}
	cout<<"\n\tListo.................";
	getch();
          break;
        }
    case 3:
        {
             string y,x,z,a;
             system("cls");
             system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	system("COLOR C0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(0,1);
	cout<<"\n\t\t\t &LISTA SIMPLEMENTE LIGADA&\n\n";
	cout<<"\t\t\t\t   -Buscar-\n";
	cout<<"\tQue nombre de mascota que quieres Buscar:\n\t";cin>>x;
	cout<<"\tQue raza de la  mascota que quieres Buscar:\n\t";cin>>z;
	a=(" ");
	y=x+a+z;
	 lista.Buscar(y);
	 getch();


           break;
        }
    case 4:
        {
              system("cls");
             system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	system("COLOR A0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(0,1);
	cout<<"\n\t\t\t &LISTA SIMPLEMENTE LIGADA&\n\n";
	cout<<"\t\t\t\t   -Vacia-\n";
	lista.vacia();
	getch();

         break;
        }
    case 5:
        {
            system("cls");
             system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	system("COLOR B0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(0,1);
	cout<<"\n\t\t\t &LISTA SIMPLEMENTE LIGADA&\n\n";
	cout<<"\t\t\t\t   -Inicializa-\n";
	cout<<"\tLISTA CREADA...............\n\t";
	getch();


            break;
        }
    case 6:
        {
            system("cls");
             system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	system("COLOR B0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(0,1);
	cout<<"\n\t\t\t &LISTA SIMPLEMENTE LIGADA&\n\n";
	cout<<"\t\t\t\t   -Primero-\n";
	lista.Primero();
	getch();
          break;
        }
    case 7:
        {
             system("cls");
             system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	system("COLOR B0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(0,1);
	cout<<"\n\t\t\t &LISTA SIMPLEMENTE LIGADA&\n\n";
	cout<<"\t\t\t\t   -Ultimo-\n";
	lista.Ultimo();
	getch();
           break;
        }
    case 8:
        {
            system("cls");
             system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	system("COLOR B0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(0,1);
	cout<<"\n\t\t\t &LISTA SIMPLEMENTE LIGADA&\n\n";
	cout<<"\t\t\t\t   -Anterior-\n";
	lista.Anterior();
	getch();

         break;
        }
    case 9:
        {
            system("cls");
             system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	system("COLOR B0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(0,1);
	cout<<"\n\t\t\t &LISTA SIMPLEMENTE LIGADA&\n\n";
	cout<<"\t\t\t\t   -Tamaño-\n";
	lista.size();
	getch();

            break;
        }
    case 10:
        {
            system("cls");
             system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	system("COLOR 40"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(0,1);
	cout<<"\n\t\t\t &LISTA SIMPLEMENTE LIGADA&\n\n";
	cout<<"\t\t\t\t   -Vaciar Todo-\n";
	lista.~Clista();
	cout<<"\n\tTODO FUE BORRADO........";
	getch();

          break;
        }
    case 11:
        {
            system("cls");
             system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	system("COLOR B0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(0,1);
	cout<<"\n\t\t\t &LISTA SIMPLEMENTE LIGADA&\n\n";
	cout<<"\t\t\t\t  -Mostrar lista-\n";
	lista.Imprimir();
	getch();

           break;
        }
    case 12:
        {
             system("cls");
             system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	system("COLOR 50"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(0,1);
	cout<<"\n\t\t\t &LISTA SIMPLEMENTE LIGADA&\n\n";
	cout<<"\t\t\t\t   -Salir-\n";
	cout<<"\n\tESTAS SEGURO DE SALIR:\n\t1-NO\n\t0-SI\n\t";cin>>s;
            break;
        }
    default:
        {
            cout<<"\tNO EXISTE ESE NUMERO EN EL MENU"<<endl;
        }

	}


    }while(s>=1);
    getch();
    return 0;
}

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
 void dibujarCuadro(int x1,int y1,int x2,int y2){
	int i;

    for (i=x1;i<x2;i++){
		gotoxy(i,y1); printf("\304"); //linea horizontal superior
		gotoxy(i,y2); printf("\304"); //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); printf("\263"); //linea vertical izquierda
		gotoxy(x2,i); printf("\263"); //linea vertical derecha
	}

    gotoxy(x1,y1); printf("\332");
    gotoxy(x1,y2); printf("\300");
    gotoxy(x2,y1); printf("\277");
    gotoxy(x2,y2); printf("\331");

 }
