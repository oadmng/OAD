// Saludos
#include<iostream>
#include "cal.h"
using namespace std;

void menu(){
     cout<<endl<<"¿Que operacion desea realizar?"<<endl;
     cout<<"............................"<<endl;
     cout<<"           Suma      (1)"<<endl;
     cout<<"           Resta     (2)"<<endl;
     cout<<"       Multipicacion (3)"<<endl;
     cout<<"           Salir     (0)" << endl;


}




int main(){
int salida=5;
while(salida != 0){
	menu();
	int opcion;
	cin>>opcion;
    int a;
    int b;
    int modulo;
    int respuesta=0;
	Calculadora cal;
    cout<<"Ingrese 1er numero "<<endl;
    cin>>a;
    cout<<"Ingrese 2do numero "<<endl;
    cin>>b;
    cout<<"Ingrese modulo con el que trabajaremos "<<endl;
    cin>>modulo;
    if(opcion==1){
        respuesta=cal.suma(a,b,modulo);}
    if(opcion==2){
        respuesta=cal.resta(a,b,modulo);}
    if(opcion==3){
        respuesta=cal.multiplicar(a,b,modulo);}
cout<<endl<<"La respuesta es :"<<respuesta<<endl;
cout<<endl<<"Que desea hacer? 1: seguir       0:salir"<<endl;
	cin>> salida;
	}
}
