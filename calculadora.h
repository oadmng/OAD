#include<iostream>
using namespace std;

class Calculadora
{

public:
int respuesta;

int suma(int a, int b,int mod){
    return (a+b)%mod;
    }
int resta(int a, int b,int mod){
 respuesta=(a-b)%mod;
if (respuesta <0){respuesta=respuesta+mod;}
    return respuesta;
    }
int multiplicar(int a, int b, int mod){
     respuesta=(a*b)%mod;
if (respuesta <0){respuesta=respuesta+mod;}
    return respuesta;
    }

};
