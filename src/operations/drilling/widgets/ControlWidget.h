// ControlWidget.h
#pragma once

#include "operations/drilling/Service.h"
#include "operations/drilling/models/Data.h"

namespace drilling {

class ControlWidget : public QWidget {
    Q_OBJECT

  public:
    explicit ControlWidget(Service *service, Data *data, QWidget *parent = nullptr);

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
    Service *service;
    Data *data;
  signals:
    void generated(const QString &text);
};

} // namespace drilling