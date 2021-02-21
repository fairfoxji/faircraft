#ifndef FAIRCRAFT_CHOOSELANGUAGEDIALOG_H
#define FAIRCRAFT_CHOOSELANGUAGEDIALOG_H

#include <QDialog>
#include <QLocale>

namespace faircraft {

namespace Ui {
class ChooseLanguageDialog;
}

class ChooseLanguageDialog : public QDialog {
  Q_OBJECT

 public:
  explicit ChooseLanguageDialog(QWidget *parent = nullptr);
  ~ChooseLanguageDialog();

  QString Selected() const;

 private:
  QString selected_;
  Ui::ChooseLanguageDialog *ui;
};

}  // namespace faircraft
#endif  // FAIRCRAFT_CHOOSELANGUAGEDIALOG_H
