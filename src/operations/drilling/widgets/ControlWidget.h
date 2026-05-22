// ControlWidget.h
#pragma once

#include "operations/drilling/models/Data.h"

namespace drilling {

class ControlWidget : public QWidget {
    Q_OBJECT

  public:
    explicit ControlWidget(Data *data, QWidget *parent = nullptr);

    ~ControlWidget();

  private:
    QLineEdit *toolNumberEdit;
    QLineEdit *feedEdit;
    QLineEdit *spindleSpeedEdit;
    QLineEdit *xEdit;
    QLineEdit *yEdit;
    QLineEdit *safeZEdit;
    QLineEdit *depthEdit;
    QLineEdit *peckDepthEdit;
    QLineEdit *holeDiameterEdit;
    QComboBox *cycleCombo;

    void setupUi();
    void setupInputFields();

    Params readParamsFromUi();
    Data *data;
  signals:
    void generated(const QString &text);
};

} // namespace drilling