#include "uistrings.h"

#include <QAction>
#include <QCoreApplication>
#include <QMessageBox>

namespace {

QString tr(const char* text) {
  return QCoreApplication::translate("UiStrings", text);
}

}  // namespace

QString UiStrings::Game() { return tr(kGame); }

QString UiStrings::Settings() { return tr(kSettings); }

QString UiStrings::Help() { return tr(kHelp); }

QString UiStrings::Exit() { return tr(kExit); }

QString UiStrings::Languages() { return tr(kLanguages); }

QString UiStrings::About() { return tr(kAbout).arg(tr(kAppName)); }

QString UiStrings::AboutTitle() { return tr(kAboutTitle).arg(tr(kAppName)); }

QString UiStrings::AboutMessage() {
  return tr(kAboutMessage).arg(tr(kAppName)).arg(FAIRCRAFT_VERSION);
}
