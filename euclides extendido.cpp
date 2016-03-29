#include <iostream>
#include <vector>
using namespace std;
int funcionPedirClavePrivada(){
    cout<<"Ingrese su clave privada"<<endl;
    int clavePrivadaUser;
    cin>>clavePrivadaUser;
    if(clavePrivadaUser<256 && clavePrivadaUser>=0){
        return clavePrivadaUser;
    }
    else{
        cout<<"Ingreso mal la clave privada"<<endl;
        cout<<" "<<endl;
        return funcionPedirClavePrivada();
    }
}
int encontrarInverso(){
    vector <int>cocientes;
    int clavePrivada=funcionPedirClavePrivada();
    int contador=-1;
    int modulo=256;
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
                pe=pe+256;
            }
            pe=(pe)%256;
            pa=burbu;
        }
        return pe;
    }
    else{
        cout<<"no existe inverso"<<endl;
        cout<<" "<<endl;
        return encontrarInverso();
    }
    }
int main(){
    //la funcion devuelve la clave publica, si es que la clave privada no tiene inverso vuelve a perdir otra clave
    int inverso=encontrarInverso();
    cout<<"el inverso es: "<<inverso<<endl;
    return 0;
}
