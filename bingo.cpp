#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
int genintervalo(){
    srand((unsigned)time(NULL));
    int primerAleatorio = rand()%10 + 1;
    srand((unsigned)time(NULL));
    int segundoAleatorio = rand()%5 + 1;
    return (primerAleatorio + segundoAleatorio);
}

void llenar(int (*p)[5], int numeroCartillas, int columna){
    int intervalo=genintervalo();
    double contador=0;
    int contadorCartillas=0;
    int a=columna;
    int interint=intervalo;
    for(int i=a;i<(a+15);i++){
        for(int j=a;j<(a+15);j++){
            if(i != j){
                for(int k=a;k<(a+15);k++){
                    if(k!=i and k!=j){
                        for(int l=a;l<(a+15);l++){
                            if(l!=i and l!=j and l!=k){
                                for(int m=a;m<(a+15);m++){
                                    if(m!=i and m!=j and m!=k and m!=l){
                                        if(contador==interint and contadorCartillas<numeroCartillas){
                                            /*cout<<"INGRESO"<<endl;
                                            cout<<i<<j<<k<<l<<m<<endl;*/
                                            p[contadorCartillas][0]=i;
                                            p[contadorCartillas][1]=j;
                                            p[contadorCartillas][2]=k;
                                            p[contadorCartillas][3]=l;
                                            p[contadorCartillas][4]=m;
                                            interint=interint+intervalo;
                                            contadorCartillas=contadorCartillas+1;
                                        }
                                        contador++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void imprimir(int (*p)[5],int (*s)[5],int (*t)[5],int (*c)[5],int (*q)[5],int numeroCartillas){
    for(int i=0;i<numeroCartillas;i++){
        for(int j=0;j<5;j++){
            cout<<p[i][j]<<" "<<s[i][j]<<" ";
            if(j!=2){
                cout<<t[i][j];
            }
            else{
                cout<<char(254);
            }
            cout<<" "<<c[i][j]<<" "<<q[i][j]<<endl;
        };
        cout<<i+1<<endl;
    };
}

int main() {
    cout<<"ingrese el numero de cartillas que desea"<<endl;
    int ncartillas;
    cin>>ncartillas;
    int cartillaPrimeraColumna[ncartillas][5];
    int cartillaSegundaColumna[ncartillas][5];
    int cartillaTerceraColumna[ncartillas][5];
    int cartillaCuartaColumna[ncartillas][5];
    int cartillaQuintaColumna[ncartillas][5];
    llenar(cartillaPrimeraColumna,ncartillas,1);
    llenar(cartillaSegundaColumna,ncartillas,16);
    llenar(cartillaTerceraColumna,ncartillas,31);
    llenar(cartillaCuartaColumna,ncartillas,46);
    llenar(cartillaQuintaColumna,ncartillas,61);
    imprimir(cartillaPrimeraColumna,cartillaSegundaColumna,cartillaTerceraColumna,cartillaCuartaColumna,cartillaQuintaColumna,ncartillas);

    int espera;
    cin>>espera;
    return 0;
}
