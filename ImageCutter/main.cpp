#include "stdafx.h"
#include "ImageCutterWindow.h"
#include <QtWidgets/QApplication>
#include <vld.h>

int main(int argc, char *argv[])
{
	//Q_INIT_RESOURCE(rc);
	//解决库路径问题============info@seatrix.com
	QTextCodec *xcodec = QTextCodec::codecForLocale() ;
	//QString exeDir = xcodec->toUnicode( QByteArray(argv[0]) ) ;
	//QString BKE_CURRENT_DIR = QFileInfo(exeDir).path() ;
	//QStringList  libpath;
	//libpath << BKE_CURRENT_DIR+QString::fromLocal8Bit("/plugins/platforms");
	//libpath << BKE_CURRENT_DIR <<BKE_CURRENT_DIR+QString::fromLocal8Bit("/plugins/imageformats");
	//libpath << BKE_CURRENT_DIR+QString::fromLocal8Bit("/plugins");
	//libpath << QApplication::libraryPaths();
	//QApplication::setLibraryPaths(libpath) ;
	QTextCodec::setCodecForLocale(xcodec);
	QApplication a(argc, argv);
	ImageCutterWindow w;
	w.show();
	return a.exec();
}
