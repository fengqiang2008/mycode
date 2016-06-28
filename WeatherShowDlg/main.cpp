#include "weathershowdlg.h"
#include <QtGui/QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
#ifdef WIN32
		QTextCodec *codec = QTextCodec::codecForName("gbk");
#else
		QTextCodec *codec = QTextCodec::codecForName("utf8");
#endif


	QTextCodec::setCodecForLocale(codec);
	WeatherShowDlg w;
	w.show();
	return a.exec();
}
