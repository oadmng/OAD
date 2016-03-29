#include <iostream>
#include <vector>
using namespace std;
int encontrarInverso(int numero, int modu){
    vector <int>cocientes;
    int clavePrivada=numero;
    int contador=-1;
    int modulo=modu;
    int modulo2=modulo;
    int burbuja=0;
    while(clavePrivada!=0){
        burbuja=clavePrivada;
        cocientes.push_back(modulo/clavePrivada);
        clavePrivada=modulo%clavePrivada;
        modulo=burbuja;
        contador++;
    }
    if(modulo==1){
        int pa=0;
        int pe=1;
        int burbu=1;
        for(int i=0;i<contador;i++){
            burbu=pe;
            pe=(pa-(pe*cocientes[i]));
            while(pe<0){
                pe=pe+modulo2;
            }
            pe=(pe)%modulo2;
            pa=burbu;
        }
        return pe;
    }
    else{
        cout<<"no existe inverso"<<endl;
        cout<<" "<<endl;
        return 0;
    }
}
