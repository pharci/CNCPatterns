// App.h
#pragma once
#include "services/PocketService.h"
#include "subject/PocketData.h"
#include "widgets/PocketWidget.h"
#include "widgets/PreviewWidget.h"

class PocketWidget;
class App : public QMainWindow {
    Q_OBJECT
  public:
    App(QWidget *parent = nullptr);
    PocketData pocketData;
    PocketService pocketService;
    PocketWidget *pocketWidget;
    PreviewWidget *previewWidget;
    ~App();
};