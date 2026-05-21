// ControlWidget.h
#pragma once
#include "operations/pocket/Service.h"
#include "operations/pocket/models/Data.h"
namespace pocket {
class ControlWidget : public QWidget {
    Q_OBJECT
  public:
    explicit ControlWidget(Service *service, Data *data, QWidget *parent = nullptr);
    ~ControlWidget();

  private:
    QComboBox *typeCombo;
    QStackedWidget *typePages;

    QLineEdit *ToolNumberEdit;
    QLineEdit *FeedEdit;
    QLineEdit *SpindleSpeedEdit;

    QLineEdit *XEdit;
    QLineEdit *YEdit;
    QLineEdit *ZEdit;
    QLineEdit *Z1Edit;
    QLineEdit *DZEdit;
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

    void setupUi();
    void setupInputFields();
    void setupPages();
    void setupConnections();
    Params readParamsFromUi();

    Service *service;
    Data *data;
  signals:
    void generated(const QString &text);
};
} // namespace pocket