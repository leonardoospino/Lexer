#include <iostream>
#include <conio.h>
using namespace std;

#include "libraries/lexer.h"
  
int main() {
	system("title Lexer (Leonardo F. Ospino Ayala)");
	system("color 0B");
	int value;
	menu();
	string word;
	cin>>word;
	Lexer *lexer = new Lexer(word);
	
	tryLexer:
	value = lexer->state_0();
	cout<<(value == -1? "\n\nError, no coincide con un token valido." : ""); 
	switch(value){
		case 1:
			cout<<"Sumar ";
			break;
		case 2:
			cout<<"Restar ";
			break;
		case 3:
			cout<<"Asignar ";
			break;
		case 5:
			cout<<"Entero ";
			lexer->decrementMark();
			goto tryLexer;
			break;
		case 7:
			cout<<"Letras ";
			lexer->decrementMark();
			goto tryLexer;
			break;
		case 12:
			cout<<"Imprimir";
			break;
	}
	return value;
}