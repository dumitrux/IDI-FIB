#include "MyLCDNumber.h"

MyLCDNumber::MyLCDNumber(QWidget *parent)
	: QLCDNumber(parent) {
}

void MyLCDNumber::colorLCDNumber(int valor) {
	if(valor == 0) setStyleSheet("color: green;");
	else if(valor%2 != 0) setStyleSheet("color: red;");
	else setStyleSheet("color: blue;");
	display(valor);
}

void MyLCDNumber::posarZero() {
	setStyleSheet("color: green;");
	display(0);
}
