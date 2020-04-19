/*Ejercicio # 1:
Se dispone de un archivo STOCK correspondiente a la existencia de artículos de un almacén y se desea señalar aquellos artículos cuyo nivel está por debajo del mínimo y que visualicen un mensaje “hacer pedido”. Cada artículo contiene un registro con los siguientes campos: número del código del artículo, nivel mínimo, nivel actual, proveedor, precio.

El programa debe tener un menu que se especifiquen las siguientes opciones:
1) Agregar productos (Grabar datos a un archivo)
2) Leer archivo y mostrar en pantalla que productos tiene nivel minimo. 

*if (nivel actual==nivel mínimo)
    cout<<"Nivel Minimo";
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct datos{
	int cod_art;
	int niv_min;
	int niv_act;
	char proveedor[20];
	float precio;
}est;

void menu();
void pedirdatos();
void aniadir();
void leer();
void leer2();

int main(){
	menu();
	system("pause");
}

void menu(){
	int menu;
	
	do{	
		system("cls");	
		cout<<"\t\t\tMenu "<<endl;
		cout<<"\t\t\t1. Agregar producto"<<endl;
		cout<<"\t\t\t2. Leer archivo"<<endl;
		cout<<"\t\t\t3. Verificar producto por debajo del minimo"<<endl;
		cout<<"\t\t\t4. Salir"<<endl;
		cout<<"\t\t\tEliga una opcion: ";
		cin>>menu;
		
		switch(menu){
			case 1:
			system("cls");			
				pedirdatos();
				aniadir();
				
				break;
			case 2:
				system("cls");
				leer();	
				break;
			case 3:
				system("cls");
				leer2();
				break;
			case 4:
				menu = 4;
				break;
		}		
	}while(menu != 4);
		
}

void pedirdatos(){
		cout<<"ingrese el codigo del producto: ";
		cin>>est.cod_art;
		cout<<"ingrese la cantidad de producto minima: ";
		cin>>est.niv_min;
		cout<<"ingrese la cantidad del producto actual: ";
		cin>>est.niv_act;
		fflush(stdin);
		cout<<"ingrese el proveedor: ";
		cin.getline(est.proveedor,20,'\n');
		cout<<"ingrese el precio del producto: ";
		cin>>est.precio;
}

void aniadir(){
	ofstream archivo;
				
		try {
		archivo.open("datos.txt",ios::app);
		archivo<<est.cod_art<<"\t"<<est.niv_min<<"\t"<<est.niv_act<<"\t"<<est.proveedor<<"\t"<<est.precio<<endl;
		archivo.close();
		cout<<"Datos grabados en el archivo"<<endl<<endl;
		}
		catch(exception X){
			cout<<"Error al grabar en el archivo"<<endl<<endl;
		} //fin try/catch
		system("PAUSE");
		archivo.close();
}

void leer(){
	system("cls");
	ifstream leer;
	string archivo;
	int lineas=0, i;
			
		leer.open("datos.txt",ios::in); 
				
		if(leer.fail()){
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
				
		while(getline(leer,archivo)){
			lineas++;
		}	
	leer.close(); 	
					
	datos vector[lineas];
			
		leer.open("datos.txt",ios::in);
		if(leer.fail()){
			cout<<"No se pudo abrir el archivo!!!";
			exit(1);
		}
		
		for(i=0;i<lineas;i++){    
  			leer>>vector[i].cod_art>>vector[i].niv_min>>vector[i].niv_act>>vector[i].proveedor>>vector[i].precio;
		}
		
		cout<<"\t Codigo del articulo  |  Nivel Minimo   |   Nivel Actual  |       Proveedor    |       Precio    |"<<endl;
		for(i=0;i<lineas;i++){
			cout<<"\t\t"<<vector[i].cod_art<<"\t\t\t"<<vector[i].niv_min<<"\t\t"<<vector[i].niv_act<<"\t\t"<<vector[i].proveedor<<"\t\t"<<vector[i].precio<<endl;
		}
		cout<<"\n\n"<<endl;
system("pause");
leer.close();
}

void leer2(){
	system("cls");
	ifstream leer;
	string archivo;
	int lineas=0, i, band=0;
			
		leer.open("datos.txt",ios::in); 
				
		if(leer.fail()){
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
				
		while(getline(leer,archivo)){
			lineas++;
		}	
	leer.close(); 	
					
	datos vector[lineas];
			
		leer.open("datos.txt",ios::in);
		if(leer.fail()){
			cout<<"No se pudo abrir el archivo!!!";
			exit(1);
		}
		
		for(i=0;i<lineas;i++){    
  			leer>>vector[i].cod_art>>vector[i].niv_min>>vector[i].niv_act>>vector[i].proveedor>>vector[i].precio;
		}
		
		for(i=0;i<lineas;i++){
			if((vector[i].niv_act==vector[i].niv_min) || (vector[i].niv_act<vector[i].niv_min)){
				cout<<"El producto con el codigo "<<vector[i].cod_art<<endl;
				band = 1;
				//cout<<"ESTA IGUAL O POR DEBAJO DEL MINIMO !HACER PEDIDO¡ "<<endl<<endl;				
			}else if(vector[i].niv_act>vector[i].niv_min){
				band = 0;
			}
		}
		
		if(band == 1){
			cout<<"\nESTA IGUAL O POR DEBAJO DEL MINIMO !HACER PEDIDO¡ "<<endl<<endl;	
		}else if(band == 0){
			cout<<"Ningun producto se encuentra por debajo del minimo"<<endl<<endl;
		}
system("pause");
leer.close();	
} 
