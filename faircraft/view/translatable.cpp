#include "translatable.h"

namespace faircraft {

Translatable::Translatable() {
  QObject::connect(Preferences::GetInstance(),
                   &Preferences::LanguageChangedSignal,
                   [this]() { this->Translate(); });
};

}  // namespace faircraft
