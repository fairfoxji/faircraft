#ifndef UISTRINGS_H
#define UISTRINGS_H

#include <QString>

class UiStrings {
 public:
  // Menu
  static QString About();
  static QString AboutTitle();
  static QString AboutMessage();
  static QString Game();
  static QString Settings();
  static QString Help();
  static QString Exit();
  static QString Languages();

 private:
  static constexpr char kAppName[] = QT_TR_NOOP("Faircraft");

  // Menu.
  static constexpr char kGame[] = QT_TR_NOOP("&Game");
  static constexpr char kExit[] = QT_TR_NOOP("&Exit");
  static constexpr char kSettings[] = QT_TR_NOOP("&Settings");
  static constexpr char kLanguages[] = QT_TR_NOOP("&Languages");
  static constexpr char kHelp[] = QT_TR_NOOP("&Help");
  static constexpr char kAbout[] = QT_TR_NOOP("&About %1");

  static constexpr char kAboutTitle[] = QT_TR_NOOP("About %1");
  static constexpr char kAboutMessage[] = QT_TR_NOOP(
      "<p><b>%1 0.1</b></p>"
      "<p>Copyright © 2021 Ning Ji.  All rights reserved.</p>");

  UiStrings() = delete;
};

#endif  // UISTRINGS_H
