#include "mainwindow.h"

#include <QMessageBox>

#include "constant/uistrings.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  SetupMenuBar();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::SetupMenuBar() {
  auto* menubar = this->menuBar();

  auto* game = menubar->addMenu(UiStrings::Game());
  game->addAction(UiStrings::Exit(), this, &MainWindow::close);

  auto* settings = menubar->addMenu(UiStrings::Settings());
  settings->addAction(UiStrings::Languages());

  auto* help = menubar->addMenu(UiStrings::Help());
  auto* aboutAction = help->addAction(UiStrings::About());
  connect(aboutAction, &QAction::triggered, this, &MainWindow::About);
}

void MainWindow::About() {
  QMessageBox::about(this, UiStrings::AboutTitle(), UiStrings::AboutMessage());
}
