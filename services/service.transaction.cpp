#include<fstream>
#include<string>
#include<iostream>
#include<time.h>
#include<conio.h>
#include"../models/transaction.h"
#define N 4000 
using namespace std;
/*test*/
transaction movements[100];
account accounts[100];
void delay(clock_t a)
{
    clock_t start;
    start  = clock();
    while(clock()-start<a)
    {

    }
}
void updateBalance(int id,bool increment,double value){
    cout<<"actualizando balance"<<endl;
    account customer;
    double newbalance=0;
    fstream file("accounts.dat",ios::in|ios::app|ios::out);
    if(file.is_open()){
        cout<<"archivo abierto exitosamente"<<endl;
        while(!file.eof()){
            file.read((char*)&customer.accountNumber,sizeof(customer.accountNumber));
            getline(file,customer.name,'\0');
            file.read((char*)&customer.balance,sizeof(customer.balance));
            cout<<customer.accountNumber<<"-"<<id<<endl;
            if(id==customer.accountNumber){
                file.seekg(file.tellg());
                if(increment) newbalance=customer.balance+value;
                else newbalance=customer.balance-value;
                customer.balance=newbalance;
                file.write(reinterpret_cast<char *>(&customer.balance),sizeof(customer.balance));
                cout<<"nuevo saldo: "<<customer.balance<<endl;
                cin.ignore();
                return;
                }
        }
        file.close();
    }else cout<<"error el abrir el archivo"<<endl;
}
void fetchMovements(int id){
    cout<<"id encontrado: "<<id<<endl;
    transaction allMovements[N];
    int flag=0;
    transaction customerMovements;
    ifstream file("transactions.dat",ios::in|ios::app);
    if(file.is_open()){
        // cout<<"----------transacciones------------"<<endl;
        while (!file.eof())
        {
        file.read((char*)&customerMovements.accountNumber,sizeof(customerMovements.accountNumber));
        getline(file,customerMovements.type,'\0');
        file.read((char*)&customerMovements.balance,sizeof(customerMovements.balance));
        // if(customerMovements.accountNumber==id){
        //     cout<<"["<<customerMovements.type<<"] - ["<<customerMovements.accountNumber<<"]"<<endl;
        // }
        allMovements[flag]=customerMovements;
        flag++;
        }
        file.close();
        cout<<"total de movimientos: "<<flag<<endl;
        for(int x=0;x<flag;x++){
            cout<<"cuenta no: "<<allMovements[x].accountNumber<<endl;
            if(allMovements[x].accountNumber==id){
                cout<<"["<<allMovements[x].type<<"] - ["<<allMovements[x].accountNumber<<"]"<<endl;
            }
        }
    }else cout <<"Error al obtener las transacciones";
}
void fetchAccounts(){
    account customer;
    int flag=0;
    ifstream file("accounts.dat",ios::in|ios::app);
    if(file.is_open()){
        do{
        file.read((char*)&customer.accountNumber,sizeof(customer.accountNumber));
        getline(file,customer.name,'\0');
        file.read((char*)&customer.balance,sizeof(customer.balance));
        cout<<"["<<customer.accountNumber<<"] - ["<<customer.name<<"] - ["<<customer.balance<<"]"<<endl;
        delay(600);
        fetchMovements(customer.accountNumber);
        
        flag++;
        }while(!file.eof());
        file.close();
    }else cout <<"error al obtener las cuentas";
}
void fetchAccountById(string id){
    int number = stoi(id);
    account customer;
    bool exists=false;
    int flag=0;
    ifstream file("accounts.dat",ios::in|ios::app);
    if(file.is_open()){
        do{
        file.read((char*)&customer.accountNumber,sizeof(customer.accountNumber));
        getline(file,customer.name,'\0');
        file.read((char*)&customer.balance,sizeof(customer.balance));
        accounts[flag]=customer;
        flag++;
        }while(!file.eof());
        file.close();
        cout<<"----------------------- total: "<<flag<<endl;
        for(int x=0;x<flag-2;x++){
            // cout<<accounts[x].accountNumber<<endl;
            if(accounts[x].accountNumber==number){
                exists=true;
             cout<<"[No. Cuenta] - [Cliente] - [Saldo Actual]"<<endl;
             cout<<"["<<accounts[x].accountNumber<<"] - ["<<accounts[x].name<<"] - ["<<accounts[x].balance<<"]"<<endl;
            cout<<"------Historico de movimientos---------"<<endl;
            cout<<"[No. Cuenta] - [tipo] - [Saldo]"<<endl;
             fetchMovements(accounts[x].accountNumber);
            //  delay(600);
            }
        }
        if(!exists) cout<<"Lo sentimos, no hemos encontrado ninguna cuenta con este numero!"<<endl;
    }else cout <<"error al obtener las cuentas";
}
void addTransaction(string type,bool increment){
    transaction movement;
    ofstream file("accounts.dat",ios::out|ios::app);
    if(file.is_open()){
        cout<<"Ingrese el número de cuenta: ";
        cin>>movement.accountNumber;
        cout<<"Ingrese el saldo: ";
        cin>>movement.balance;
        movement.type=type;
        file.write(reinterpret_cast<char *>(&movement.accountNumber),sizeof(movement.accountNumber));
        file.write(movement.type.c_str(), movement.type.length()+1);
        file.write(reinterpret_cast<char *>(&movement.balance),sizeof(movement.balance));
        file.close();
        // updateBalance(movement.accountNumber,increment,movement.balance);
        
    }else cout<<"error al obtener el archivo"<<endl;
}
void addAccount(){
    account customer;
    ofstream file("accounts.dat",ios::out|ios::app);
    if(file.is_open()){
        cout<<"Numero de cuenta: ";
        cin>>customer.accountNumber;
        cout<<"Nombre del cliente: ";
        cin.ignore();
        getline(cin,customer.name);
        customer.balance=0;
        cout<<"guardando..."<<endl;
        delay(600);
        file.write(reinterpret_cast<char *>(&customer.accountNumber),sizeof(customer.accountNumber));
        file.write(customer.name.c_str(), customer.name.length()+1);
        file.write(reinterpret_cast<char *>(&customer.balance),sizeof(customer.balance));
        file.close();
        cout<<"Cuenta agregada con exito!!"<<endl;
        // addTransaction("retiro");
    }else cout<<"error al obtener el archivo"<<endl;
}
