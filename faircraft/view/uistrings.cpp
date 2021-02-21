#include "uistrings.h"

#include <QCoreApplication>

namespace faircraft {

namespace {

constexpr char kContext[] = "faircraft::UiStrings";

QString tr(const char* text) {
  return QCoreApplication::translate(kContext, text);
}

}  // namespace

QString UiStrings::AppName() { return tr(kAppName); }

}  // namespace faircraft
