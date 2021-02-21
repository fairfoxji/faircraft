#include "myradiobutton.h"

MyRadioButton::MyRadioButton(const QString& text, QWidget* parent,
                             const QString& data)
    : QRadioButton(text, parent), data_(data) {}
