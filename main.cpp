#include<iostream>
#include<string>
#include"models/account.h"
#include"services/service.transaction.cpp"

using namespace std;
extern void addAccount();
extern void fetchAccounts();
extern void addTransaction(string type,bool increment);
extern void fetchAccountById(string id);
void datosPersonales(){
    cout<<"------------------Creditos--------------------"<<endl;
    cout<<"Universidad Mariano Gálvez de Guatemala"<<endl;
    cout<<"Ingeniería en Sistemas de información"<<endl;
    cout<<"Nombre: Luis Eduardo Alvarado Celano"<<endl;
    cout<<"Carnet: 0900-20-7376"<<endl;
    cout<<"Curso: Algoritmos"<<endl;
}
void menu(){
    cout<<"-----------OPERACIONES FINANCIERAS---------------"<<endl;
    cout<<"elige una opcion ingresado el numero solicitado: "<<endl;
    cout<<"Ingreso de nueva cuenta - (opcion 1)"<<endl;
    cout<<"Ver estado de cuenta y movimientos - (opcion 2)"<<endl;
    cout<<"Realizar un deposito - (opcion 3)"<<endl;
    cout<<"Realizar un retiro - (opcion 4)"<<endl;
    cout<<"Salir - (opcion 0)"<<endl;
    cout<<"-------------------------------------------------"<<endl;
}
void selectedOption(int option){
    string id;
    switch (option)
    {
    case 1:
        addAccount();
        break;
    case 2:
        cout<<"Ingrese el número de cuenta"<<endl;
        cin.ignore();
        getline(cin,id);
        fetchAccountById(id);
        break;
    case 3:
        addTransaction("deposito",true);
        break;
    case 4:
        addTransaction("retiro",false);
        break;
    case 5:
        fetchAccounts();
        break;
    case 0:
        cout<<"Vuelve pronto!!!"<<endl;
        break;
    default:
        cout<<"debes seleccionar una de las opciones indicadas";
        break;
    }
}
int main_3(){
    //getFile();
    //  addTransaction("retiro");
    // fetchAccounts();
    fetchAccountById("55");
    return 0;
}
int main(){
    int option;
    datosPersonales();
    menu();
    cin>>option;
    selectedOption(option);
    while(option>0){
      menu();
      cin>>option;
      selectedOption(option);
    }
    return 0;
}