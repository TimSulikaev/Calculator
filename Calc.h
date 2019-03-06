#pragma once
#include "AST.h"

class EvaluatorException : public std::exception{
public:
	EvaluatorException(const std::string& message):
		std::exception(message.c_str()){
		}
};

class Evaluator { //класс обхода дерева и вычисления выражения
	double EvaluateSubtree(ASTNode* ast){
		if(ast == NULL) 
			throw EvaluatorException("Incorrect syntax tree!");

		if(ast->Type == NumberValue)
			return ast->Value.number;
		else if (ast->Type == SymbolVariable){
				if(ast->Value.var != NULL){
					std::cout << ">> " << ast->Value.var << " = ";
					std::cin >> ast->Value.number;
					std::cout << "<< OK" << std::endl;
					return ast->Value.number;
				}
		}
		else {
			double v1 = EvaluateSubtree(ast->Left);
			double v2 = EvaluateSubtree(ast->Right);
			switch(ast->Type){
				case OperatorPlus:  return v1 + v2;
				case OperatorMinus: return v1 - v2;
				case OperatorMul:   return v1 * v2;
				case OperatorDiv:   return v1 / v2;
			}
		}

		throw EvaluatorException("Incorrect syntax tree!");
	}

public:
	double Evaluate(ASTNode* ast){
		if(ast == NULL)
			throw EvaluatorException("Incorrect abstract syntax tree");

		return EvaluateSubtree(ast);
	}
};