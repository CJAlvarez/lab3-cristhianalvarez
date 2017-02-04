// Laboratorio 3 - Programacion 3
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

// Complemento del primer ejercicio
void balance(string);
// Segundo ejercicio
void calendar();

int main(){
	int option;
	cout << "Ingrese opcion: ";
	cin >> option;
	switch (option){

		//Primer ejercicio	
		case 1:{
			string letters;
			cout << "Ingrese secuencia: " << endl;
			cin >> letters;	
			balance (letters);
			break;
			}
		case 2:{
			calendar();
			break;
			}
	}
	return 0;
}

void balance (string letters){
	int corchetes =  0, parentecis = 0, llaves = 0;

	for(int i = 0; i < letters.length() ; i++){
		switch(letters.at(i)){
		
		case '[':{
			corchetes++;
			break;}
                case ']':{
			corchetes--;
                        break;}
                case '{':{
			llaves++;
                        break;}
                case '}':{
			llaves--;
                        break;}
                case '(':{
			parentecis++;
                        break;}
                case ')':{
			parentecis--;
                        break;}
		}		
	}
	if(llaves == 0 && corchetes == 0 && parentecis == 0){
		cout << "Balanceado" << endl;
	} else {
		cout << "No balanceado" << endl;
	}
}

void calendar(){
	string date;
	vector <string> allDates (2);
	string dayName[7] = {"Lunes", "Martes", "Miercoles", 
			"Jueves", "Viernes", "Sabado", "Domingo"};
	int formatDate[3];
	bool bisiesto = false; 
	while(true){
		cout << "Ingrese Fecha en YYYYMMDD: ";
		cin >> date;
		
			/* Validar*/
		// Tamaño
		if(date.length() != 8){
			cout << " * Tamaño incorrecto *" << endl;
			continue;
		}

		// Ordena en matriz
		formatDate[0] = atoi(date.substr(0,4).c_str());
		cout << "Año " << formatDate[0] << endl;
		formatDate[1] = atoi(date.substr(4,2).c_str());
		cout << "Mes " << formatDate[1] << endl;
		formatDate[2] = atoi(date.substr(6).c_str());
		cout << "Dia " << formatDate[2] << endl;
		// Año bisiesto
		if(formatDate[0]%400 == 0 && formatDate[0]%100 == 0){
			bisiesto = true;
			cout << "Bisiesto" << endl;
		}
		// Mes
		if(formatDate[1] > 12) {
			cout << " ** Mes inexistente **" << endl;
			continue;
		}
		// Dias
		if(formatDate[2] != 0){
			if((formatDate[1] == 2 && bisiesto == true && formatDate[2] > 29) 
			&& (formatDate[1] == 2 && bisiesto == false && formatDate[2] > 28) ){
				cout << " *** Dias invalidos***" << endl;
				continue;
			} else if ((formatDate[1] %2 == 0 && formatDate[2] > 30) 
			|| (formatDate[1] %2 != 0 && formatDate[2] > 31)){		
				cout << " *** Dias invalidos***" << endl;
                	        continue;
			}		
		}else{
			cout << " *** Dias invalidos***" << endl;
			continue;
		}
				/* DIAS */
		int centurioi = (formatDate[0] - (formatDate[0]%100))/100;	
		int centuriof = formatDate[0]%100;
		int dia;

//cout << formatDate[0] << " - " << formatDate[1] << " - " << formatDate[2] << " | " << centurioi<<centuriof << endl;
		dia =(-1)* (( formatDate[2] + (((formatDate[1] + 1) * 26)/10) + centuriof + (centuriof/4) + (centurioi/4) -  (2 * centurioi))%7)-1 ;
		cout << dia << endl;
//cout << (dia % 7)-9 << " Help"<< endl;

//		cout << dayName[dia] << endl;
		// Agregar a la lista
		string temp[4];
		temp[0] = formatDate[0];
		temp[1] = formatDate[1];
		temp[2] = formatDate[2];
		temp[3] = dayName[dia];
		
		allDates.resize(allDates.size()+2);
		cout << temp[3+1] << " " << formatDate[2] << " " << formatDate[1] << " " << formatDate[0] << endl;
	

		int option;
		//cout << "
		break;
	}	
}


