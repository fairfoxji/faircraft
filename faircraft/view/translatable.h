#ifndef FAIRCRAFT_TRANSLATABLE_H
#define FAIRCRAFT_TRANSLATABLE_H

#include <QObject>

#include "controller/preferences.h"

namespace faircraft {

class Translatable {
 public:
  Translatable();
  virtual ~Translatable() = default;

 private slots:
  virtual void Translate() = 0;
};

}  // namespace faircraft

#endif  // FAIRCRAFT_TRANSLATABLE_H
