#include "mainwindow.h"

#include <QAction>
#include <QMenuBar>
#include <QMessageBox>

#include "constant/uistrings.h"
#include "controller/preferences.h"

namespace faircraft {

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  SetupMenuBar();
  Translate();
}

void MainWindow::SetupMenuBar() {
  auto* menubar = this->menuBar();

  game_ = menubar->addMenu(QStringLiteral(""));
  exit_ = game_->addAction(QStringLiteral(""), this, &MainWindow::close);

  settings_ = menubar->addMenu(QStringLiteral(""));
  languages_ = settings_->addAction(QStringLiteral(""));

  help_ = menubar->addMenu(QStringLiteral(""));
  about_ = help_->addAction(QStringLiteral(""), this, &MainWindow::About);
}

void MainWindow::About() {
  QMessageBox::about(this, UiStrings::AboutTitle(), UiStrings::AboutMessage());
}

void MainWindow::Translate() {
  game_->setTitle(UiStrings::Game());
  exit_->setText(UiStrings::Exit());
  settings_->setTitle(UiStrings::Settings());
  languages_->setText(UiStrings::Languages());
  help_->setTitle(UiStrings::Help());
  about_->setText(UiStrings::About());
}

}  // namespace faircraft
