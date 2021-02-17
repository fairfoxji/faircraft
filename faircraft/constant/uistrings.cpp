#include "uistrings.h"

#include <QAction>
#include <QCoreApplication>
#include <QMessageBox>
#include <QTranslator>

namespace faircraft {

namespace {

constexpr char kContext[] = "faircraft::UiStrings";

QString tr(const char* text) {
  return QCoreApplication::translate(kContext, text);
}

}  // namespace

QString UiStrings::Game() { return tr(kGame); }

QString UiStrings::Settings() { return tr(kSettings); }

QString UiStrings::Help() { return tr(kHelp); }

QString UiStrings::Exit() { return tr(kExit); }

QString UiStrings::Languages() { return tr(kLanguages); }

QString UiStrings::SystemLanguage() { return tr(kSystemLanguage); }

QString UiStrings::TranslatedLanguageName(const QString& qml_file) {
  QTranslator translator;
  QString ret;
  if (translator.load(qml_file)) {
    ret = translator.translate("LanguageChooser", kTheLanguageName);
  }
  return ret.isEmpty() ? kTheLanguageName : ret;
}

QString UiStrings::About() { return tr(kAbout).arg(tr(kAppName)); }

QString UiStrings::AboutTitle() { return tr(kAboutTitle).arg(tr(kAppName)); }

QString UiStrings::AboutMessage() {
  return tr(kAboutMessage)
      .arg(tr(kAppName))
      .arg(QStringLiteral(FAIRCRAFT_VERSION));
}

}  // namespace faircraft
