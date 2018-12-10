#include <QLineEdit>
//#include <QString>

class MyLineEdit: public QLineEdit
{
	Q_OBJECT
	public:
		MyLineEdit (QWidget *parent);
	public slots:
		void omplirLabel();
		void reset();
	signals:
		void enviaText(const QString &);
		void enviaNombreErrors(const int);
}; 
