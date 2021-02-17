#ifndef FAIRCRAFT_LANGUAGEMANAGER_H
#define FAIRCRAFT_LANGUAGEMANAGER_H

#include <QMap>
#include <QTranslator>

namespace faircraft {

class LanguageManager {
 public:
  static LanguageManager* GetInstance();

  // Returns the available languages as a map of local name -> the translated
  // language name.
  const QMap<QString, QString>& AvailableLanguages() const;

 public slots:
  // Installs the translators on the application. Should be called when the
  // language changes.
  void InstallTranslators();

 private:
  LanguageManager();

  QString translations_dir_;
  QMap<QString, QString> languages_;
  std::unique_ptr<QTranslator> qt_translator_;
  std::unique_ptr<QTranslator> qtbase_translator_;
  std::unique_ptr<QTranslator> app_translator_;
};

}  // namespace faircraft

#endif  // FAIRCRAFT_LANGUAGEMANAGER_H
