#include <QApplication>

#include "constant/configs.h"
#include "controller/languagemanager.h"
#include "view/mainwindow.h"

using faircraft::Configs;
using faircraft::LanguageManager;
using faircraft::MainWindow;

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  QCoreApplication::setOrganizationName(Configs::kOrganizeName);
  QCoreApplication::setOrganizationDomain(Configs::kOrganizeDomain);
  QCoreApplication::setApplicationName(Configs::kApplicationName);

  LanguageManager::GetInstance()->AvailableLanguages();
  LanguageManager::GetInstance()->InstallTranslators();

  MainWindow w;
  w.show();

  return a.exec();
}
