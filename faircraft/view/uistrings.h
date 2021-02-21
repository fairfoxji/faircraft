#ifndef UISTRINGS_H
#define UISTRINGS_H

#include <QString>

namespace faircraft {

class UiStrings {
 public:
  static QString AppName();

 private:
  static constexpr char kAppName[] = QT_TR_NOOP("Faircraft");

  UiStrings() = delete;
};

}  // namespace faircraft

#endif  // UISTRINGS_H
