#pragma once

enum TokenType { //��������������
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

struct Token { //��������� ��� �������� ��������������
	TokenType Type;
	double Value;
	char Symbol;

	Token():Type(Error), Value(0), Symbol(0)
	{}
};

enum ASTNodeType { //���� ����� (��� �����������)
	Undefined,
	OperatorPlus,
	OperatorMinus,
	OperatorMul,
	OperatorDiv,
	SymbolVariable,
	NumberValue
};

struct ValueType{ //��� ��������
	double number; //��� �����
	char var; // ��� ����������
};

class ASTNode { //����� ��������������� ������
	public:
		ASTNodeType Type;
		ValueType Value;
		ASTNode* Left;
		ASTNode* Right;

		ASTNode(){ //����������� ��� ����� 
			Type = Undefined;
			Value.number = 0;
			Value.var = NULL;
			Left = nullptr;
			Right = nullptr;
		}

		~ASTNode(){ //����������
			delete Left;
			delete Right;
		}
};