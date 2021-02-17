#include "preferences.h"

#include <QCoreApplication>
#include <QProcess>
#include <QSettings>

#include "languagemanager.h"

namespace faircraft {

namespace {

// Settings keys.
constexpr char kLanguage[] = "ui/language";

}  // namespace

Preferences* Preferences::GetInstance() {
  static Preferences* pref = new Preferences();
  return pref;
}

void Preferences::RestoreDefaults() {
  QSettings settings;
  settings.clear();

  QCoreApplication::quit();
  QProcess::startDetached(QCoreApplication::applicationFilePath());
}

QString Preferences::GetLanguage() const {
  QSettings settings;
  return settings.value(kLanguage).toString();
}

void Preferences::SetLanguage(const QString& language) {
  QSettings settings;
  settings.setValue(kLanguage, language);
  LanguageManager::GetInstance()->InstallTranslators();
  emit LanguageChangedSignal();
}

}  // namespace faircraft
