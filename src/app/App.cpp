// App.cpp
#include "App.h"
#include "interface/PocketWidget.h"

App::App(QWidget *parent) : QMainWindow(parent) {
    QWidget *main = new QWidget(this);
    setCentralWidget(main);

    QHBoxLayout *layout = new QHBoxLayout(main);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    outputEdit = new QPlainTextEdit(this);
    outputEdit->setReadOnly(true);

    pocketWidget = new PocketWidget(this);

    layout->addWidget(pocketWidget);
    layout->addWidget(outputEdit);

    connect(pocketWidget,
            &PocketWidget::generated,
            outputEdit,
            &QPlainTextEdit::setPlainText);
}

App::~App() {}