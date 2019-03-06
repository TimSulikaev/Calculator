#include <iostream>
#include <cstdlib>
#include "Parser.h"
#include "Calc.h"

using namespace std;

void Calculate(const char* text){  //Вычисление выражения
	Parser parser;

	try {
		ASTNode* ast = parser.Parse(text);
		cout << "<< OK" << endl;


		try {
		Evaluator eval;
		double val = eval.Evaluate(ast);

		cout << ">> calculate" << endl;
		cout << "<< " << val << endl;
		}
		catch(EvaluatorException& ex){
		cout << text << " \t " << ex.what() << endl; 
		}

		delete ast;
	}
	catch(ParserException& ex){
		cout << text << " \t " << ex.what() << endl; 
	}   
}

void interact_input() {
	char input_text[256] = "";
	cout << "Enter expression (without spaces): ";
	cin >> input_text;
	Calculate(input_text);
}

void cmd_args(const int c, const char ** v){
	char argtostr[256] = "";
	for (int i = 1; i < c; i++) { //нулевой элемент не считываем
		strcat_s(argtostr, sizeof(argtostr), v[i]);
	}
	Calculate(argtostr);
}

int main(int argc, const char ** argv){
	if (argv[1] == NULL)
		interact_input();
	else
		cmd_args(argc, argv);
	system("pause");
	return 0;
}
