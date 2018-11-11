#include "MyLineEdit.h"

// constructor
MyLineEdit::MyLineEdit(QWidget *parent=0)
	: QLineEdit(parent) {
	// inicialitzaio datributs si cal
}

// implementacio slots
void MyLineEdit::tractarReturn() {
	// implementacio de tractarReturn
	emit enviaText (text());
}
