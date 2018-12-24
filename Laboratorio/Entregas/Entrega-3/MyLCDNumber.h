#include <QLCDNumber>
class MyLCDNumber:public QLCDNumber
{
	Q_OBJECT
	public:
		MyLCDNumber(QWidget *parent);
		int op1, op2, res;
		bool valorAbs;
	
	public slots:
		void assignarOp1(int valor);
		void assignarOp2(int valor);
		
		void suma();
		void resta();
		void multiplicacio();
		void divisio();
		
		void canviarValorAbsolut();
		void acumular();
		void reset();
		
		void error(int tipus);
		void resetError();

	signals:
		void desactivarValorAbsolut();
		void valorPerDefecte(int valor);
		void enviarAOp1(int valorRes);
		void evniarInfoError(QString str);
		void enviarEstilError(QString str);
}; 
