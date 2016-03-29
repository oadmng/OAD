#include<iostream>
using namespace std;

class Calculadora
{
public:
int suma(int a, int b,int mod){
    return (a+b)%mod;
    }
int resta(int a, int b,int mod){

    return(a-b)%mod;
    }
int multiplicar(int a, int b, int mod){
    return (a*b)%mod;
    }

};
