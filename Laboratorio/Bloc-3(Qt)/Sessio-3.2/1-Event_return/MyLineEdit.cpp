#include "MyLineEdit.h"

// constructor
MyLineEdit::MyLineEdit(QWidget *parent)
	: QLineEdit(parent) {
		// Inicialitzacio datributs si cal
}

// implementacio slots
void MyLineEdit::tractaReturn() {
	// Implementacio de tractaReturn
	emit enviaText (text());
}
