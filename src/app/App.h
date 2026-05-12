// App.h
#pragma once

class PocketWidget;
class App : public QMainWindow {
    Q_OBJECT
  public:
    App(QWidget *parent = nullptr);
    PocketWidget *pocketWidget;
    QPlainTextEdit *outputEdit;
    ~App();
};