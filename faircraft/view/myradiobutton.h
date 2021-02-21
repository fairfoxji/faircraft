#ifndef MYRADIOBUTTON_H
#define MYRADIOBUTTON_H

#include <QRadioButton>
#include <QString>
#include <QWidget>

class MyRadioButton : public QRadioButton {
 public:
  MyRadioButton(const QString& text, QWidget* parent = nullptr,
                const QString& data = "");

  const QString& data() const { return data_; }

 private:
  const QString data_;
};

#endif  // MYRADIOBUTTON_H
