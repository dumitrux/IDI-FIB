#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent=0):QLabel(parent)
{
	numCamions = numCotxes = numMotos =  = recaudat = 0;
}

void MyLabel::incCotxe()
{
	if (obert) {
		++numCotxes;
		setNum(numCotxes);
		++recaudat;
	}
}

void MyLabel::incMoto()
{
	if (obert) {
		++numMotos;
		setNum(numMotos);
		++recaudat;
	}
}

void MyLabel::incCamio()
{
	if (obert) {
		++numCamions;
		setNum(numCamions);
		recaudat += 4;
	}
}

void MyLabel::obrir()
{
	obert = true;
	setStyleSheet("background-color: green;");
	setText("Obert");
}

void MyLabel::tancar()
{
	obert = false;
	setStyleSheet("background-color: red;");
	setText("Tancat");
}
