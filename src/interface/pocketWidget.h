#pragma once

#include "services/pocketService.h"
#include <QWidget>
#include <qcombobox.h>
#include <qwidget.h>

class BaseObject;
class PocketWidget : public QWidget {
    Q_OBJECT
  public:
    explicit PocketWidget(QWidget *parent = nullptr);
    ~PocketWidget();

  private:
    PocketService pocketService;

    QComboBox *typeCombo;
    QStackedWidget *typePages;
    QLineEdit *centerXEdit;
    QLineEdit *centerYEdit;
    QLineEdit *depthEdit;
    QLineEdit *pocketRadius;
    QLineEdit *pocketLength;
    QLineEdit *pocketWidth;

    QComboBox *insertionCombo;
    QStackedWidget *insertionPages;
    QLineEdit *insertionR;
    QLineEdit *insertionH;
    QLineEdit *insertionAlpha0;

    QWidget *machiningWidget;
    QComboBox *machiningCombo;

    QPushButton *btnGenerate;
    void paintEvent(QPaintEvent *event) override;
    void setupUi();
    void setupPages();
    void setupValidators();
    void setupConnections();
    PocketParams readParamsFromUi();
  signals:
    void generated(const QString &text);
};