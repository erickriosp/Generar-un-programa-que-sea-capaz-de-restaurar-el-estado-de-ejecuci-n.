#include <iostream>
#include <fstream>
#include <string.h>
#include<windows.h>
using namespace std;
int menuPrincipal( ){
    int opc;
    system("cls");
    cout<<"------------------------------------------------------";
    cout<<"\n1.-Capturar";
    cout<<"\n2.- Mostrar";
    cout<<"\n3.- Buscar";
    cout<<"\n4.- Modificar";
    cout<<"\n5.- Eliminar";
    cout<<"\n0.- Salir\n";
    cout<<"------------------------------------------------------\n";
    cin>>opc;
    return opc;
}
void Capturar(ofstream &es)
{
	system("cls");
	string Nom;
	string Ape;
	string Edad;
	es.open("Directorio.txt",ios::out | ios::app);
	cout<<"Nombre:";
	cin>>Nom;
	cout<<"Apellido:";
	cin>>Ape;
	cout<<"Edad:";
	cin>>Edad;
	es<<Nom<<" "<<Ape<<" "<<Edad<<" "<<"\n";
	es.close();
}
void Mostrar(ifstream &Lec){
	system("cls");
	string Nom;
	string Ape;
	string Edad;
	Lec.open("Directorio.txt", ios::in);
	Lec>>Nom;
	while(!Lec.eof()){
		Lec>>Ape;
		Lec>>Edad;
		cout<<"\nNombre:"<<Nom<<endl;
		cout<<"Apellido:"<<Ape<<endl;
		cout<<"Edad:"<<Edad<<endl;
		Lec>>Nom;
	}
	Lec.close();
	/*system("Pause");*/
}
void Buscar(ifstream &Lec){
	system("cls");
	Lec.open("Directorio.txt", ios::in);
	string Nom;
	string Ape;
	string Edad;
	string Nomaux;
	bool encontrado = false;
	cout<<"Digite el nombre:\n";
	cin>>Nomaux;
	Lec>>Nom;
	while(!Lec.eof() && !encontrado){
		Lec>>Ape;
		Lec>>Edad;
		if(Nom==Nomaux){
			system("cls");
			cout<<"\nNombre:"<<Nom<<endl;
			cout<<"Apellido:"<<Ape<<endl;
			cout<<"Edad:"<<Edad<<endl;
			encontrado = true;
		}
		Lec>>Nom;
	}
	Lec.close();
	if(!encontrado)
		cout<<"Dato no encontrado"<<endl;
	/*system("pause");*/
}
void Modificar(ifstream &Lec){
	system("cls");
	string Nom;
	string Ape;
	string Edad;
	string Apeaux;
	string Nomaux;
	Lec.open("Directorio.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if(Lec.is_open()){
		cout<<"Apellido:"<<endl;
		cin>>Apeaux;
		Lec>>Nom;
		while(!Lec.eof()){
			Lec>>Ape;
			Lec>>Edad;
			if(Ape == Apeaux){
				cout<<"Nuevo Nombre:"<<endl;
				cin>>Nomaux;
				cout<<"Nueva Edad:"<<endl;
				cin>>Edad;
				cout<<"Nueva Apellido:"<<endl;
				cin>>Ape;
				aux<<Nomaux<<" "<<Ape<<" "<<Edad<<"\n";	
			}else{
				aux<<Nom<<" "<<Ape<<" "<<Edad<<"\n";	
			}
			Lec>>Nom;
		}
		Lec.close();
		aux.close();
	}else
		cout<<"Error\n"<<endl;
	remove("Directorio.txt");
	rename("auxiliar.txt", "Directorio.txt");
}
void Eliminar(ifstream &Lec){
	system("cls");
	string Nom;
	string Ape;
	string Edad;
	string Apeaux;
	string Nomaux;
	Lec.open("Directorio.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if(Lec.is_open()){
		cout<<"Apellido:"<<endl;
		cin>>Apeaux;
		Lec>>Nom;
		while(!Lec.eof()){
			Lec>>Ape;
			Lec>>Edad;
			if(Ape == Apeaux){
				cout<<"El registro fue eliminado!"<<endl;
			}else
			{
				aux<<Nom<<" "<<Ape<<" "<<Edad<<"\n";	
			}
			Lec>>Nom;
		}
		Lec.close();
		aux.close();
	}else
		cout<<"Error\n"<<endl;
	remove("Directorio.txt");
	rename("auxiliar.txt", "Directorio.txt");
}
int main(void)
{
    ofstream Esc;
    ifstream Lec;
    int opc;
    do{
        system("cls");
        opc = menuPrincipal();
        switch(opc){
            case 1:{
                Capturar(Esc);
                break;
            }
            case 2:{
                Mostrar(Lec);
                break;
            }
            case 3:{
                Buscar(Lec);
                break;
            }
            case 4:{
                Modificar(Lec);  
				break;
			}
            case 5: {
                Eliminar(Lec);
				break;
            }
        }system("pause");
    }while(opc != 0);
    return 0;
}
