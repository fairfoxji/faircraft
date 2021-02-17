#ifndef FAIRCRAFT_MAINWINDOW_H
#define FAIRCRAFT_MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>

#include "translatable.h"

namespace faircraft {

class MainWindow : public QMainWindow, public Translatable {
  Q_OBJECT
 public:
  explicit MainWindow(QWidget* parent = nullptr);

 signals:

 private slots:
  // About box.
  void About();
  void Translate() override;

 private:
  void SetupMenuBar();

  QMenu* game_ = nullptr;
  QMenu* settings_ = nullptr;
  QMenu* help_ = nullptr;

  QAction* exit_ = nullptr;
  QAction* languages_ = nullptr;
  QAction* about_ = nullptr;
};

}  // namespace faircraft

#endif  // FAIRCRAFT_MAINWINDOW_H
