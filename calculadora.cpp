#include<iostream>
using namespace std;

int suma(int a, int b,int mod){
    return ((a% mod)+(b%mod))%mod;
    }
int resta(int a, int b,int mod){
	
    return((a% mod)-(b%mod))%mod;
    }
int multiplicar(int a, int b, int mod){
    return ((a% mod)*(b%mod))%mod;
    }
int dividir(int a, int b, int mod){
    return ((a% mod)/(b%mod))%mod;
    }

void menu(){
     cout<<endl<<"¿Que operacion desea realizar?"<<endl;
     cout<<"............................"<<endl;
     cout<<"           Suma      (1)"<<endl;
     cout<<"           Resta     (2)"<<endl;
     cout<<"       Multipicacion (3)"<<endl;
     cout<<"          Division   (4)"<<endl;
     cout<<"           Salir     (0)" << endl;

     
}




int main(){
int salida=5;
while(salida != 0){
	menu();
	int opcion;
	cin>>opcion;
  int a;//primer numero
  int b;//segundo numero
  int modulo;
  int respuesta=0;
  cout<<"Ingrese 1er numero "<<endl;
  cin>>a;
  cout<<"Ingrese 2do numero "<<endl;
  cin>>b;
  cout<<"Ingrese modulo con el que trabajaremos "<<endl;
  cin>>modulo;
  if(opcion==1){
      respuesta=suma(a,b,modulo);}
  if(opcion==2){
      respuesta=resta(a,b,modulo);}
  if(opcion==3){
      respuesta=multiplicar(a,b,modulo);}
  if(opcion==4){
      respuesta=dividir(a,b,modulo);}
  cout<<endl<<"La respuesta es :"<<respuesta<<endl;
  cout<<endl<<"Que desea hacer? 1: seguir       0:salir"<<endl;
	cin>> salida;
	}
}
