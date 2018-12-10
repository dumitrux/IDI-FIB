#include "MyLineEdit.h"

// constructor
MyLineEdit::MyLineEdit(QWidget *parent)
	: QLineEdit(parent) {
}

void MyLineEdit::reset() {
	setEnabled(true);
	emit enviaNombreErrors(0);
	setStyleSheet("background-color: none;");
}

void MyLineEdit::omplirLabel() {
	QString str = text();
	str = str.toUpper();
	int errors = str.size();
	QString dic = "**********";
	
	if (str.contains('D')) {
		dic.replace(0, 1, 'D');
		--errors;
	}
	if (str.contains('I')) {
		dic.replace(1, 1, 'I');
		dic.replace(4, 1, 'I');
		dic.replace(9, 1, 'I');
		--errors;
	}
	if (str.contains('C')) {
		dic.replace(2, 1,'C');
		dic.replace(3, 1, 'C');
		--errors;
	}
	if (str.contains('O')) {
		dic.replace(5, 1, 'O');
		--errors;
	}
	if (str.contains('N')) {
		dic.replace(6, 1, 'N');
		--errors;
	}
	if (str.contains('A')) {
		dic.replace(7, 1, 'A');
		--errors;
	}
	if (str.contains('R')) {
		dic.replace(8, 1, 'R');
		--errors;
	}
	if(errors < 0 ) errors = 0;
	emit enviaNombreErrors(errors);
	emit enviaText(dic);
	if(str.size() == 12 or errors >= 5) {
		clear();
		setStyleSheet("background-color: red;");
		setEnabled(false);
	}
	else if(!dic.contains('*')) {
		clear();
		setStyleSheet("background-color: green;");
		setEnabled(false);
	}
}

	/*for (int i = 0; i < str.size(); ++i) {
		QChar c = str.at(i);
		if(str.contains('C'))
		else
	}*/
