#pragma once

enum TokenType { //Идентификаторы
	Error,
	Plus,
	Minus,
	Mul,
	Div,
	EndOfText,
	OpenParenthesis,
	ClosedParenthesis,
	Variable,
	Number
};

struct Token { //Структура для хранения идетификаторов
	TokenType Type;
	double Value;
	char Symbol;

	Token():Type(Error), Value(0), Symbol(0)
	{}
};

enum ASTNodeType { //Типы веток (для приоритетов)
	Undefined,
	OperatorPlus,
	OperatorMinus,
	OperatorMul,
	OperatorDiv,
	SymbolVariable,
	NumberValue
};

struct ValueType{ //Тип значения
	double number; //для чисел
	char var; // для переменных
};

class ASTNode { //Класс синтаксического дерева
	public:
		ASTNodeType Type;
		ValueType Value;
		ASTNode* Left;
		ASTNode* Right;

		ASTNode(){ //Конструктор для ветки 
			Type = Undefined;
			Value.number = 0;
			Value.var = NULL;
			Left = nullptr;
			Right = nullptr;
		}

		~ASTNode(){ //Деструктор
			delete Left;
			delete Right;
		}
};