#include "chooselanguagedialog.h"

#include <QRadioButton>

#include "controller/languagemanager.h"
#include "controller/preferences.h"
#include "ui_chooselanguagedialog.h"

namespace faircraft {

ChooseLanguageDialog::ChooseLanguageDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::ChooseLanguageDialog) {
  ui->setupUi(this);

  QString curr_lang = Preferences::GetInstance()->GetLanguage();

  // System default
  auto* button = new QRadioButton(tr("System Default"), this->ui->groupBox);

  connect(button, &QRadioButton::toggled, this,
          [this]() { this->selected_ = ""; });
  if (curr_lang.isEmpty()) {
    button->setChecked(true);
  }
  this->ui->groupBox->layout()->addWidget(button);

  const auto& langs = LanguageManager::GetInstance()->AvailableLanguages();
  for (const auto& lang : langs) {
    auto* button =
        new QRadioButton(lang.nativeLanguageName(), this->ui->groupBox);
    connect(button, &QRadioButton::toggled, this,
            [this, lang]() { this->selected_ = lang.name(); });
    if (curr_lang == lang.name()) {
      button->setChecked(true);
    }
    this->ui->groupBox->layout()->addWidget(button);
  }
}

ChooseLanguageDialog::~ChooseLanguageDialog() { delete ui; }

QString ChooseLanguageDialog::Selected() const {
  qDebug() << "Selected: " << selected_;
  return selected_;
}

}  // namespace faircraft
