#include<iostream>
#include<string.h>
#include"models/customer.h"
using namespace std;
void datosPersonales(){
    cout<<"-----------Creditos--------------------"<<endl;
    cout<<"Universidad Mariano Gálvez de Guatemala"<<endl;
    cout<<"Ingeniería en Sistemas de información"<<endl;
    cout<<"Nombre: Luis Eduardo Alvarado Celano"<<endl;
    cout<<"Carnet: 0900-20-7376"<<endl;
    cout<<"Curso: Algoritmos"<<endl;
}
int menu(){
    int option;
    cout<<"-----------Operaciones financieras---------------"<<endl;
    cout<<"elige una opcion ingresado el numero solicitado: "<<endl;
    cout<<"Ingreso de nueva cuenta - (opcion 1)"<<endl;
    cout<<"Ver estado de cuenta y movimientos - (opcion 2)"<<endl;
    cout<<"Realizar un deposito - (opcion 3)"<<endl;
    cout<<"Realizar un retiro - (opcion 4)"<<endl;
    cout<<"Salir - (opcion 0)"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cin>>option;
    return option;
}
void selectedOption(int option){
    switch (option)
    {
    case 1:
        cout<<"has seleccionado el 1"<<endl;
        break;
    case 2:
        cout<<"has seleccionado el 2"<<endl;
        break;
    case 3:
        cout<<"has seleccionado el 3"<<endl;
        break;
    case 4:
        cout<<"has seleccionado el 4"<<endl;
        break;
    case 0:
        cout<<"Vuelve pronto!!!"<<endl;
        break;
    default:
        cout<<"debes seleccionar una de las opciones indicadas";
        break;
    }
}
int main(){
    customer cliente;
    // while(menu()>0){
    //   //  opt=menu();
    //     cout<<"opcion seleccionada "<<menu()<<endl;
    //     //selectedOption(menu());
    // }
    cout<<"hola mundo";
    return 0;
}