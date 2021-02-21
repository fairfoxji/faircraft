#include "chooselanguagedialog.h"

#include "controller/languagemanager.h"
#include "controller/preferences.h"
#include "myradiobutton.h"
#include "ui_chooselanguagedialog.h"

namespace faircraft {

ChooseLanguageDialog::ChooseLanguageDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::ChooseLanguageDialog) {
  ui->setupUi(this);

  QString curr_lang = Preferences::GetInstance()->GetLanguage();

  // System default
  auto* button =
      new MyRadioButton(tr("System Default"), this->ui->groupBox, "");
  buttons_.push_back(button);

  if (curr_lang.isEmpty()) {
    button->setChecked(true);
  }
  this->ui->groupBox->layout()->addWidget(button);

  const auto& langs = LanguageManager::GetInstance()->AvailableLanguages();
  for (const auto& lang : langs) {
    auto* button = new MyRadioButton(lang.nativeLanguageName(),
                                     this->ui->groupBox, lang.name());
    buttons_.push_back(button);

    if (curr_lang == lang.name()) {
      button->setChecked(true);
    }
    this->ui->groupBox->layout()->addWidget(button);
  }
}

ChooseLanguageDialog::~ChooseLanguageDialog() { delete ui; }

QString ChooseLanguageDialog::Selected() const {
  QString selected;

  for (const MyRadioButton* button : buttons_) {
    if (button->isChecked()) {
      selected = button->data();
      break;
    }
  }
  qDebug() << "Selected: " << selected;

  return selected;
}

}  // namespace faircraft
