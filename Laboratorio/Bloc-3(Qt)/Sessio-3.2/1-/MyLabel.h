#include <QLabel>
class MyLabel:public QLabel
{
	Q_OBJECT //IMPORTANT
	public:
		MyLabel(QWidget *parent);
	
	public slots: //IMPORTANT
		void setTextMajuscules(QString);
};
