#include "languagemanager.h"

#include <QCoreApplication>
#include <QDir>
#include <QDirIterator>
#include <QLibraryInfo>
#include <QString>

#include "preferences.h"
#include "view/uistrings.h"

namespace faircraft {

namespace {

constexpr char kTranslationDir[] = ":/translation";
constexpr char kTranslationFilePrefix[] = "_";
constexpr char kTranslationFileName[] = "faircraft";
constexpr char kTranslationFileSuffix[] = ".qm";

}  // namespace

LanguageManager* LanguageManager::GetInstance() {
  static LanguageManager* language_manager = new LanguageManager();
  return language_manager;
}

const std::vector<QLocale>& LanguageManager::AvailableLanguages() const {
  return languages_;
}

void LanguageManager::InstallTranslators() {
  QString qt_translation_path(
      QLibraryInfo::path(QLibraryInfo::TranslationsPath));

  QString lang = Preferences::GetInstance()->GetLanguage();
  QLocale locale = lang.isEmpty() ? QLocale::system() : QLocale(lang);

  qDebug() << "lang " << lang << " locale " << locale;

  // qt_ translator.
  if (qt_translator_ != nullptr) {
    QCoreApplication::removeTranslator(qt_translator_.get());
  }
  qt_translator_ = std::make_unique<QTranslator>();
  if (qt_translator_->load(locale, QStringLiteral("qt"), QStringLiteral("_"),
                           qt_translation_path)) {
    QCoreApplication::installTranslator(qt_translator_.get());
  } else {
    qt_translator_.reset();
  }

  // qtbase_ translator.
  if (qtbase_translator_ != nullptr) {
    QCoreApplication::removeTranslator(qtbase_translator_.get());
  }
  qtbase_translator_ = std::make_unique<QTranslator>();
  if (qtbase_translator_->load(locale, QStringLiteral("qtbase"),
                               QStringLiteral("_"), qt_translation_path)) {
    QCoreApplication::installTranslator(qtbase_translator_.get());
  } else {
    qtbase_translator_.reset();
  }

  // app translator.
  if (app_translator_ != nullptr) {
    QCoreApplication::removeTranslator(app_translator_.get());
  }
  app_translator_ = std::make_unique<QTranslator>();
  if (app_translator_->load(locale, kTranslationFileName,
                            kTranslationFilePrefix, kTranslationDir)) {
    QCoreApplication::installTranslator(app_translator_.get());
  } else {
    app_translator_.reset();
  }
}

LanguageManager::LanguageManager() {
  QStringList filter;
  filter.append(QString("%1%2*%3")
                    .arg(kTranslationFileName)
                    .arg(kTranslationFilePrefix)
                    .arg(kTranslationFileSuffix));

  QDirIterator iterator(kTranslationDir, filter, QDir::Files | QDir::Readable);

  while (iterator.hasNext()) {
    iterator.next();
    // Cut off prefix from the start.
    QString locale_name = iterator.fileInfo().completeBaseName().mid(
        strlen(kTranslationFileName) + strlen(kTranslationFilePrefix));
    qDebug() << "Full path " << iterator.filePath();
    qDebug() << "Local name " << locale_name;

    QLocale locale("nonone");
    qDebug() << "Bad: " << locale;
    qDebug() << "Bad name: " << locale.name();

    if (!locale_name.isEmpty()) {
      QLocale locale(locale_name);
      if (locale.name() != "C") {
        languages_.push_back(locale);
      }
    }
  }

  for (const QLocale& locale : languages_) {
    qDebug() << locale.name();
    qDebug() << locale.nativeLanguageName();
    qDebug() << locale.nativeCountryName();
  }
  qDebug() << "Total " << languages_.size();
}

}  // namespace faircraft
