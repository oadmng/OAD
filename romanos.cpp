#include<iostream>
using namespace std;
int separar(int numero,int num[],int aux)
{
  for(int i=1000;i>0;i=i/10){
    int cociente = numero/i;
    numero=numero%i;
    num[aux]=cociente;
    aux++;
    }
}

void romanos(int input)
{
  char l[]={'M','D','C','L','X','V','I'};//letras disponibles

  int num[4];//array donde se guarda el numero
  separar(input,num,0);
  //for(int i=0;i<4;i++){cout<<num[i]<<" ";}cout <<endl;
  if(num[0]<4){
	for(int i=num[0];i>0;i--){
		cout<<l[0];}    
	  for(int pos=1;pos<4;pos++){
		if(num[pos]<4){
			for(int i=num[pos];i>0;i--){
				cout<<l[2*pos];}			
				}
			if(num[pos]>4 && num[pos]<9){
				cout<<l[(2*pos)-1];
				for(int i=num[pos];i>5;i--){
					cout<<l[2*pos];}
				}
			if(num[pos] == 4){
				cout<<l[2*pos];
				cout<<l[(2*pos)-1];}
			if(num[pos] == 9){
				cout<<l[2*pos];
				cout<<l[(2*pos)-2];}
		
		}
	cout <<endl;
	}
else{
cout <<"OVER FLOW"<<endl;
}
}


int main()
{   
  cout <<"Ingrese un numero: "<<endl;
  int input;
  cin>>input;
  romanos(input);
}
