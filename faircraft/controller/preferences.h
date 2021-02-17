#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QObject>
#include <QString>

namespace faircraft {

class Preferences : public QObject {
  Q_OBJECT

 public:
  static Preferences* GetInstance();

  void RestoreDefaults();

  QString GetLanguage() const;
  void SetLanguage(const QString& language);

 signals:
  void LanguageChangedSignal();

 private:
  Preferences() = default;
};

}  // namespace faircraft

#endif  // PREFERENCES_H
