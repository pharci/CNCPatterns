#pragma once

#include "services/PocketService.h"

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

    QPushButton *btnGenerate;
    void paintEvent(QPaintEvent *event) override;
    void setupUi();
    void setupValidators();
    void setupPages();
    void setupConnections();
    PocketParams readParamsFromUi();
  signals:
    void generated(const QString &text);
};