#include "mainwindow.h"

#include <QMessageBox>

#include "chooselanguagedialog.h"
#include "controller/preferences.h"
#include "ui_mainwindow.h"
#include "uistrings.h"

namespace faircraft {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::About() {
  QMessageBox::about(
      this, tr("About %1").arg(UiStrings::AppName()),
      tr("<p><b>%1 %2</b></p>"
         "<p>Copyright © 2021 Ning Ji (fairfoxji@gmail.com).  All rights "
         "reserved.</p>")
          .arg(UiStrings::AppName())
          .arg(QStringLiteral(FAIRCRAFT_VERSION)));
}

void MainWindow::ChooseLanguage() {
  ChooseLanguageDialog dialog;
  int ret = dialog.exec();
  if (ret == QDialog::Accepted) {
    Preferences::GetInstance()->SetLanguage(dialog.Selected());
  }
}

void MainWindow::Translate() {
  this->ui->menu_Game->setTitle(tr("&Game"));
  this->ui->menu_Help->setTitle(tr("&Help"));
  this->ui->menu_Settings->setTitle(tr("&Settings"));
  this->ui->action_About->setText(tr("&About"));
  this->ui->action_Exit->setText(tr("&Exit"));
  this->ui->action_Language->setText(tr("&Language"));
}

}  // namespace faircraft
