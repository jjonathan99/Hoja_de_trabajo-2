/*Ejercicio # 2:
El director de un colegio desea realizar un programa que procese un archivo de registros correspondiente a los diferentes alumnos del centro a fin de obtener los siguientes datos:

Nota más alta y número de identificación del alumno correspondiente.
Nota media del colegio.
Datos de Estudiantes:

Identificación
Nombre
Nota*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void pedirdatos();
void leer();
void mostraralumnos();

struct datos{
	char identificacion[15];
	char nombre[30];
	float nota;
}est;

	float aux=0;
	float notamedia, totalmedia;
	int menu, cont=0;
int main(){
	do{
		system("cls");
		cout<<"\t\t-------Menu Colegio-------  "<<endl;
		cout<<"\t\t1. Ingresar Datos del Estudiante "<<endl;
		cout<<"\t\t2. Nota media del colegio y del mejor estudiante"<<endl;
		cout<<"\t\t3. Ver todos los estudiantes"<<endl;
		cout<<"\t\t4. Salir"<<endl;
		cout<<"\t\tIngrese una opcion: ";
		cin>>menu;
		
		if(menu==1){
			pedirdatos();
		}else if(menu==2){
			leer();
		}else if(menu==3){
			mostraralumnos();
		}else if(menu==4){
			menu=4;
		}
		
	}while(menu != 4);
	system("pause");
}

void leer(){
	system("cls");
				ifstream leer;
				string texto;
				int lineas=0, i;
				
				leer.open("datos.txt",ios::in); 
				
				if(leer.fail()){
					cout<<"No se pudo abrir el archivo";
					exit(1);
				}
				
					while(getline(leer,texto)){
						lineas++;
					}	
					leer.close(); //Cerramos el archivo	
					
			datos vector[lineas];
			
			leer.open("datos.txt",ios::in);
			if(leer.fail()){
			cout<<"No se pudo abrir el archivo!!!";
			exit(1);
			}
			for(i=0;i<lineas;i++){    
  			    leer>>vector[i].identificacion>>vector[i].nombre>>vector[i].nota;
			}				
			
			for(i=0;i<lineas;i++){
				if(vector[i].nota>aux){
					aux = vector[i].nota;
				}
				notamedia +=vector[i].nota;
			}
			
			for(i=0;i<lineas;i++){
				if(aux == vector[i].nota){
					cout<<"\t\t\t     Datos del Estudiante con mejor nota"<<endl;
					cout<<"\t\t\t---------------------------------------------"<<endl;
					cout<<"\t\t\t*Identificacion: "<<vector[i].identificacion<<endl;
					cout<<"\t\t\t*Nombre: "<<vector[i].nombre<<endl;
					cout<<"\t\t\t*Nota: "<<vector[i].nota<<endl;	
				}
			}
			totalmedia = notamedia/lineas;
			
			cout<<"\t\t\t*La nota media del colegio es: "<<totalmedia<<endl<<endl;				
			system("pause");
}

void pedirdatos(){
	system("cls");
				fflush(stdin);
				cout<<"Ingrese el numero de identificacion del estudiante: ";
				cin>>est.identificacion;
				fflush(stdin);
				cout<<"Ingrese el nombre del estudiante: ";
				cin.getline(est.nombre,30,'\n');
				fflush(stdin);
				cout<<"Ingrese la nota del estudiante: ";
				cin>>est.nota;
				fflush(stdin);
				
				ofstream archivo;
				
				try {
				archivo.open("datos.txt",ios::app);
				archivo<<est.identificacion<<"\t"<<est.nombre<<"\t"<<est.nota<<"\t"<<endl;
				archivo.close();
				cout<<"Datos grabados en el archivo"<<endl<<endl;
				}
				catch(exception X){
					cout<<"Error al grabar en el archivo"<<endl<<endl;
				} //fin try/catch
				system("PAUSE");
				archivo.close();
}

void mostraralumnos(){
	system("cls");
				ifstream leer;
				string texto;
				int lineas=0, i;
				
				leer.open("datos.txt",ios::in); 
				
				if(leer.fail()){
					cout<<"No se pudo abrir el archivo";
					exit(1);
				}
				
					while(getline(leer,texto)){
						lineas++;
					}	
					leer.close(); //Cerramos el archivo	
					
			datos vector[lineas];
			
			leer.open("datos.txt",ios::in);
			if(leer.fail()){
			cout<<"No se pudo abrir el archivo!!!";
			exit(1);
			}
			for(i=0;i<lineas;i++){    
  			    leer>>vector[i].identificacion>>vector[i].nombre>>vector[i].nota;
			}
			
			cout<<"\t\t\t\tIdentificacion|  Nombre  |    Nota  "<<endl;
			for(i=0;i<lineas;i++){
				cout<<"\t\t\t\t"<<vector[i].identificacion<<"\t\t"<<vector[i].nombre<<"\t\t"<<vector[i].nota<<endl;
			}	
			cout<<"\n\n";
			system("pause");
			leer.close();
}
