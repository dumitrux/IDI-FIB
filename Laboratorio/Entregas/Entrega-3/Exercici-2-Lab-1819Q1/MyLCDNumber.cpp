#include "MyLCDNumber.h"

MyLCDNumber::MyLCDNumber(QWidget *parent=0):QLCDNumber(parent)
{
	op1 = op2 = res = 0;
	valorAbs = false;
}

void MyLCDNumber::assignarOp1(int valor)
{
	op1 = valor;
	resetError();
}

void MyLCDNumber::assignarOp2(int valor)
{
	op2 = valor;
	resetError();
}

void MyLCDNumber::suma()
{
	res = op1 + op2;
	display(res);
	resetError();
}

void MyLCDNumber::resta()
{
	res = op1 - op2;
	display(res);
	resetError();
}

void MyLCDNumber::multiplicacio()
{
	res = op1 * op2;
	display(res);
	resetError();
}

void MyLCDNumber::divisio()
{
	resetError();
	if (op2 == 0) error(0);
	else {
		res = op1 / op2;
		display(res);
	}
}

void MyLCDNumber::error(int tipus)
{
	QString str;
	if(tipus == 0) // divisio per zero
		str = "Error: No es pot dividir per 0.";
	else if(tipus == 1)// acumula valor negatiu a Op1
		str = "Error: No es pot acumular un valor negatiu.";
	else // acumula valor major a 99
		str = "Error: No es pot acumular un valor major a 99.";
	emit evniarInfoError(str);
	emit enviarEstilError("background-color: rgba(255, 0, 4, 60);");
}

void MyLCDNumber::resetError()
{
	emit evniarInfoError("");
	emit enviarEstilError("background-color: none;");
}

void MyLCDNumber::canviarValorAbsolut()
{
	valorAbs = !valorAbs;
	if(res < 0) res = -res;
	display(res);
}

void MyLCDNumber::acumular()
{
	resetError();
	if (res < 0) error(1);
	else if(res > 99) error(2);
	else {
		emit enviarAOp1(res);
		op1 = res;
	}
}

void MyLCDNumber::reset()
{
	op1 = op2 = res = 0;
	display(0);
	emit valorPerDefecte(0);
	if (valorAbs) emit desactivarValorAbsolut();
	resetError();
}
