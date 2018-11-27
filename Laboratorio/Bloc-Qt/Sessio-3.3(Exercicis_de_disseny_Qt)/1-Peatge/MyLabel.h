#include <QLabel>
class MyLabel:public QLabel 
{
	Q_OBJECT
	public:
		MyLabel(QWidget *parent);
		int numCamions, numCotxes, numMotos, recaudat;
		bool obert;
		
	public slots:
		void incCotxe();
		void incMoto();
		void incCamio();
		void obrir();
		void tancar();
		
};
