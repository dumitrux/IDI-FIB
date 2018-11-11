#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent=0):QLabel(parent)
{
}

void MyLabel::setTextMajuscules(QString s)
{
	QString str = s.toUpper();
	setText(str); // heredat de QLabel
}
