#include <QLineEdit>
class MyLineEdit:public QLineEdit
{
	Q_OBJECT //IMPORTANT
	public:
		MyLineEdit (QWidget *parent);
	public slots: //IMPORTANT
		void tractarReturn ();
	signals:
		void enviaText (const QString &);
};
