#ifndef FAIRCRAFT_MAINWINDOW_H
#define FAIRCRAFT_MAINWINDOW_H

#include <QMainWindow>

#include "view/translatable.h"

namespace faircraft {

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Translatable {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
 public slots:
  void About();
  void ChooseLanguage();
  void Translate() override;

 private:
  Ui::MainWindow *ui;
};

}  // namespace faircraft
#endif  // FAIRCRAFT_MAINWINDOW_H
