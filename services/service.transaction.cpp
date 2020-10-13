#include<fstream>
#include<string>
using namespace std;
/*test*/
void getFile(){
    string line;
    cout<<"obteniendo archivo..."<<endl;
    fstream file("data.txt");
    if(file.is_open()){
        while (getline(file,line))
        {
            cout<<line<<endl;
        }
        
    }else cout<<"error al abrir el archivo"<<endl;
}