#include <QPushButton>

class MyQPushButton: public QPushButton
{
	Q_OBJECT
	public:
		MyQPushButton (QWidget *parent);
		unsigned int rand;
		
		void pintarColor(int n);
	public slots:
		void colorRandom(int n);
		void color(int n);
	signals:
		void assignarColor(int n);
};
 
