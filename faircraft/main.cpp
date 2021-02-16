#include <QApplication>
#include <QTranslator>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  QTranslator translator;
  if (!translator.load(":/translation/faircraft_zh_CN.qm")) {
    qDebug() << "failed";
    return 1;
  }
  a.installTranslator(&translator);

  MainWindow w;
  w.show();

  return a.exec();
}
