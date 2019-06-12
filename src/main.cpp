#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <locale>


// declaraciones de constantes
const char TAB = '\t';

// declaraciones de variables
char look;    // caracter lookahead

// prototipos
void getChar();

int main() 
{
	// inicializar
	getChar();
	
}


// lee un nuevo caracter desde el input stream
void getChar()
{
    std::cin >> look;
}

// reporta un error
void error(std::string s)
{
	std::cout << std::endl;
	std::cout << "Error: " << s << ".";
}

// reportar un error y abortar
void abortar(std::string s)
{
	error(s);
	throw std::exception();
}

// informa la informacioon que se esperaba
void esperado(std::string s)
{
	abortar("Se esperaba el dato: " + s);
}

// compara en busca de un caracter especiifico
void emparejar(char x)
{
	if (look == x)
	{
		getChar();
	}
	else 
	{	
		std::stringstream ss;
		std::string s;
		ss << "**" << x << "**";
		ss >> s;
		esperado(s);
	}
}

// get an identifier
char getNombre()
{
	if (!std::isalpha(look))
	{
		esperado("Nombre");
	}	
	char nombre = std::toupper(look);
	getChar();
	return nombre; 
}

// get a number
char getNum()
{
	if (!std::isdigit(look)) 
	{
		esperado("Nuumero Entero");
	}
	char num = look;
	getChar();
	return num;
}

// imprime un String con TAB
void emitir(std::string s)
{
	std::cout << TAB << s;
}

// imprime un String con TAB y salto de liinea
void emitirLn(std::string s)
{
	emitir(s);
	std::cout << std::endl;
}


