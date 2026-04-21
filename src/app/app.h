#pragma once

#include <QtWidgets/QMainWindow>

class PocketWidget;
class App : public QMainWindow {
    Q_OBJECT
  public:
    App(QWidget *parent = nullptr);
    PocketWidget *pocketWidget;
    QPlainTextEdit *outputEdit;
    ~App();
};