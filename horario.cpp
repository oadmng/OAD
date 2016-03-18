#include "main.h"
using namespace std;
int validacionFormatoHora(){
    string formatoHoraUser;
    cout<<"Que formato de hora desea (12h/24h)"<<endl;
    //validacion del formato de hora
    cin>>formatoHoraUser;
    if(formatoHoraUser=="12h" or formatoHoraUser=="12H"){
        return 12;
    }
    else if(formatoHoraUser=="24h" or formatoHoraUser=="24H"){
        return 24;
    }
    else{
        cout<<"Ingreso mal el formato de hora, vuelva a ingresarlo"<<endl;
        cout<<" "<<endl;
        return validacionFormatoHora();
    }
}
int validacionHoraInicio(int formatoHora){
    string horaInicioUser;
    int validacionHoraInicio;
    if(formatoHora==12){
        cout<<"Ingrese la hora de inicio (00:00)"<<endl;
        cin>>horaInicioUser;
        cout<<"Ingrese si es (am/pm)"<<endl;
        string manana_tarde;
        cin>>manana_tarde;
        int horas = ((horaInicioUser[0]-48)*10) + (horaInicioUser[1]-48);
        int minutos = ((horaInicioUser[3]-48)*10) + (horaInicioUser[4]-48);
        if(manana_tarde[0]==112){
            horas=horas+12;
        }
        validacionHoraInicio = (horas*60)+minutos;
        return validacionHoraInicio;
    }
    else if(formatoHora==24){
        cout<<"Ingrese la hora de inicio (00:00)"<<endl;
        cin>>horaInicioUser;
        int horas = ((horaInicioUser[0]-48)*10) + (horaInicioUser[1]-48);
        int minutos = ((horaInicioUser[3]-48)*10) + (horaInicioUser[4]-48);
        validacionHoraInicio = (horas*60)+minutos;
        return validacionHoraInicio;
    }
};

int validacionHoraFinal(int formatoHora){
    string horaFinalUser;
    int validacionHoraFinal;
    if(formatoHora==12){
        cout<<"Ingrese la hora de final (00:00)"<<endl;
        cin>>horaFinalUser;
        cout<<"Ingrese si es (am/pm)"<<endl;
        string manana_tarde;
        cin>>manana_tarde;
        int horas = ((horaFinalUser[0]-48)*10) + (horaFinalUser[1]-48);
        int minutos = ((horaFinalUser[3]-48)*10) + (horaFinalUser[4]-48);
        if(manana_tarde[0]==112){
            horas=horas+12;
        }
        validacionHoraFinal = (horas*60)+minutos;
        return validacionHoraFinal;
    }
    else if(formatoHora==24){
        cout<<"Ingrese la hora de final (00:00)"<<endl;
        cin>>horaFinalUser;
        int horas = ((horaFinalUser[0]-48)*10) + (horaFinalUser[1]-48);
        int minutos = ((horaFinalUser[3]-48)*10) + (horaFinalUser[4]-48);
        validacionHoraFinal = (horas*60)+minutos;
        return validacionHoraFinal;
    }


};
int validacionDuracionHora(){
    string duracionHoraUser;
    cout<<"Ingrese la duracion de la hora (00:00)"<<endl;
    cin>>duracionHoraUser;
    int horas = ((duracionHoraUser[0]-48)*10) + (duracionHoraUser[1]-48);
    int minutos = ((duracionHoraUser[3]-48)*10) + (duracionHoraUser[4]-48);
    int validacionDuracionHora = (horas*60)+minutos;
    return validacionDuracionHora;
}
void crearHorario(int horaInicio, int duracion, int ciclos,int *horario){
    for(int i =0;i<ciclos;i++){
        *horario=horaInicio;
        horario++;
        horaInicio=horaInicio + duracion;
        if(horaInicio>1439){
        horaInicio=0;
        }
        *horario=horaInicio;
        horario++;
    }
};
void imprimirHorario(int ciclos, int *horario, int formatoHora){
    string manana="";
    string tarde="";
    for(int i=0;i<ciclos*2;i++){
        int hora;
        int minutos;
        hora=*horario/60;
        string horaCero="";
        if(hora==0){
            horaCero="0";
        }
        else{
            horaCero="";
        }
        if(formatoHora==12 and hora>12){
            hora=hora-12;
            tarde=" pm";
            manana="";
        }
        else if(formatoHora==12 and hora<12){
            tarde="";
            manana=" am";
        }
        else if(formatoHora==12 and hora==12){
            tarde=" pm";
            manana="";
        }
        minutos=*horario%60;
        string minutoCero="";
        if(minutos==0){
            minutoCero="0";
        }
        else{
            minutoCero="";
        }
        if(i%2==0){
            cout<<"-"<<hora<<horaCero<<":"<<minutos<<minutoCero<<manana<<tarde<<"-->";
        }
        else if(i%2==1){
            cout<<" "<<hora<<horaCero<<":"<<minutos<<minutoCero<<manana<<tarde<<endl;
        }
        horario++;
    }
}
int main(){
    int duracionHora;
    int formatoHora;
    int horaInicio;
    int horaFinal;
    //recoger los datos que ingresa el usuario
    formatoHora=validacionFormatoHora();
    horaInicio=validacionHoraInicio(formatoHora);
    horaFinal=validacionHoraFinal(formatoHora);
    duracionHora=validacionDuracionHora();
    //los datos estan todos en minutos
    int numeroHorasPosibles;
    if(horaFinal>horaInicio){
        numeroHorasPosibles=(horaFinal-horaInicio)/duracionHora;
    }
    else if(horaInicio>horaFinal){
        numeroHorasPosibles=((1440-horaInicio)+horaFinal)/duracionHora;
    }
    //
    int horario[numeroHorasPosibles*2];
    crearHorario(horaInicio,duracionHora,numeroHorasPosibles,horario);
    imprimirHorario(numeroHorasPosibles,horario,formatoHora);
    //
    return 0;
}
