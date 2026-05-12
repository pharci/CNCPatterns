// PocketWidget.h
#pragma once

#include "services/PocketService.h"
#include "subject/PocketData.h"

class BaseObject;
class PocketWidget : public QWidget {
    Q_OBJECT
  public:
    explicit PocketWidget(PocketService *pocketService, PocketData *pocketData, QWidget *parent = nullptr);
    ~PocketWidget();

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
    PocketParams readParamsFromUi();

    PocketService *pocketService;
    PocketData *pocketData;
  signals:
    void generated(const QString &text);
};