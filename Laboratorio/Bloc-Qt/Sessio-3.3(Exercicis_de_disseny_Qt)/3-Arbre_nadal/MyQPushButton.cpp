#include "MyQPushButton.h" 

MyQPushButton::MyQPushButton(QWidget *parent)
	: QPushButton(parent) {
		qsrand(time(NULL));
		rand = qrand()%4;
		if(rand == 0) setStyleSheet("background-color: black;");
		else if(rand == 1) setStyleSheet("background-color: blue;");
		else if(rand == 2) setStyleSheet("background-color: green;");
		else setStyleSheet("background-color: red;");
}

void MyQPushButton::colorRandom(int n) {
	rand = qrand()%4;
	emit assignarColor(rand);
}

void MyQPushButton::pintarColor(int n) {
	if(n == 0) setStyleSheet("background-color: black;");
	else if(n == 1) setStyleSheet("background-color: blue;");
	else if(n == 2) setStyleSheet("background-color: green;");
	else setStyleSheet("background-color: red;");
}

void MyQPushButton::color(int n) {
	if(n == 0) setStyleSheet("background-color: black;");
	else if(n == 1) setStyleSheet("background-color: blue;");
	else if(n == 2) setStyleSheet("background-color: green;");
	else setStyleSheet("background-color: red;");
}


//sprintf(buff,"background: rgb(%d,%d,%d);", rgb[0]%255, rgb[1]%255, rgb[2]%255);
