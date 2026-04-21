#include "common/pch.h"
#include <qgridlayout.h>
#include <qlabel.h>
#include <qspinbox.h>
#include <qwidget.h>

#include "pocketWidget.h"

PocketWidget::PocketWidget(QWidget *parent) : QWidget(parent) {
    setFixedWidth(200);
    setupUi();
    setupPages();
    setupValidators();
    setupConnections();
}

PocketWidget::~PocketWidget() {}

void PocketWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
}

void PocketWidget::setupUi() {
    auto *title = new QLabel("Pocket Cycle", this);

    auto *typeLabel = new QLabel("Type", this);
    typeCombo = new QComboBox(this);
    typeCombo->addItem("Circular", (int) PocketType::Circular);
    typeCombo->addItem("Rectangular", (int) PocketType::Rectangular);
    auto *typeLayout = new QHBoxLayout();
    typeLayout->setContentsMargins(0, 0, 0, 0);
    typeLayout->setSpacing(8);
    typeLayout->addWidget(typeLabel);
    typeLayout->addWidget(typeCombo);
    typePages = new QStackedWidget(this);

    centerXEdit = new QLineEdit(this);
    centerYEdit = new QLineEdit(this);
    depthEdit = new QLineEdit(this);
    auto *baseParamsLayout = new QGridLayout();
    baseParamsLayout->setContentsMargins(0, 0, 0, 0);
    baseParamsLayout->setSpacing(8);
    baseParamsLayout->addWidget(new QLabel("X = ", this), 0, 0);
    baseParamsLayout->addWidget(centerXEdit, 0, 1);
    baseParamsLayout->addWidget(new QLabel("Y = ", this), 1, 0);
    baseParamsLayout->addWidget(centerYEdit, 1, 1);
    baseParamsLayout->addWidget(new QLabel("Depth = ", this), 2, 0);
    baseParamsLayout->addWidget(depthEdit, 2, 1);

    auto *insertionLabel = new QLabel("Insertion", this);
    insertionCombo = new QComboBox(this);
    insertionCombo->addItem("Spiral", (int) InsertionType::Spiral);
    insertionCombo->addItem("Pendulum", (int) InsertionType::Pendulum);
    insertionCombo->addItem("Vertical", (int) InsertionType::Vertical);
    auto *insertionLayout = new QHBoxLayout();
    insertionLayout->setContentsMargins(0, 0, 0, 0);
    insertionLayout->setSpacing(8);
    insertionLayout->addWidget(insertionLabel);
    insertionLayout->addWidget(insertionCombo);
    insertionPages = new QStackedWidget(this);

    auto *machiningLabel = new QLabel("Machining", this);
    machiningCombo = new QComboBox(this);
    machiningCombo->addItem("Planar", (int) CircularMachining::Planar);
    machiningCombo->addItem("Helical", (int) CircularMachining::Helical);
    auto *machiningLayout = new QHBoxLayout();
    machiningLayout->setContentsMargins(0, 0, 0, 0);
    machiningLayout->setSpacing(8);
    machiningLayout->addWidget(machiningLabel);
    machiningLayout->addWidget(machiningCombo);
    machiningWidget = new QWidget(this);
    machiningWidget->setLayout(machiningLayout);

    btnGenerate = new QPushButton("Generate GCode", this);

    auto *root = new QVBoxLayout(this);
    root->setContentsMargins(8, 8, 8, 8);
    root->setSpacing(8);
    root->addWidget(title);

    root->addLayout(typeLayout);
    root->addLayout(baseParamsLayout);
    root->addWidget(typePages);

    root->addLayout(insertionLayout);
    root->addWidget(insertionPages);

    root->addWidget(machiningWidget);

    root->addWidget(btnGenerate);
    root->addStretch();
}

void PocketWidget::setupPages() {
    QWidget *circularPage = new QWidget(this);
    auto *circularPageLayout = new QGridLayout(circularPage);
    circularPage->setLayout(circularPageLayout);
    circularPageLayout->setContentsMargins(0, 0, 0, 0);
    circularPageLayout->addWidget(new QLabel("R = ", circularPage), 0, 0);
    pocketRadius = new QLineEdit(circularPage);
    circularPageLayout->addWidget(pocketRadius, 0, 1);

    QWidget *rectangularPage = new QWidget(this);
    auto *rectangularPageLayout = new QGridLayout(rectangularPage);
    rectangularPageLayout->setContentsMargins(0, 0, 0, 0);
    rectangularPage->setLayout(rectangularPageLayout);
    rectangularPageLayout->addWidget(new QLabel("L = ", rectangularPage), 0, 0);
    pocketLength = new QLineEdit(rectangularPage);
    rectangularPageLayout->addWidget(pocketLength, 0, 1);
    rectangularPageLayout->addWidget(new QLabel("W = ", rectangularPage), 1, 0);
    pocketWidth = new QLineEdit(rectangularPage);
    rectangularPageLayout->addWidget(pocketWidth, 1, 1);

    typePages->setSizePolicy(
        QSizePolicy::Expanding,
        QSizePolicy::Fixed);
    typePages->addWidget(circularPage);
    typePages->addWidget(rectangularPage);

    QWidget *spiralPage = new QWidget(this);
    auto *spiralPageLayout = new QGridLayout(spiralPage);
    spiralPage->setLayout(spiralPageLayout);
    spiralPageLayout->setContentsMargins(0, 0, 0, 0);
    spiralPageLayout->addWidget(new QLabel("R = ", spiralPage), 0, 0);
    insertionR = new QLineEdit(spiralPage);
    spiralPageLayout->addWidget(insertionR, 0, 1);
    spiralPageLayout->addWidget(new QLabel("H = ", spiralPage), 1, 0);
    insertionH = new QLineEdit(spiralPage);
    spiralPageLayout->addWidget(insertionH, 1, 1);

    QWidget *pendulumPage = new QWidget(this);
    auto *pendulumPageLayout = new QGridLayout(pendulumPage);
    pendulumPage->setLayout(pendulumPageLayout);
    pendulumPageLayout->setContentsMargins(0, 0, 0, 0);
    pendulumPageLayout->addWidget(new QLabel("α₀ = ", pendulumPage), 1, 0);
    insertionAlpha0 = new QLineEdit(pendulumPage);
    pendulumPageLayout->addWidget(insertionAlpha0, 1, 1);

    QWidget *verticalPage = new QWidget(this);
    auto *verticalPageLayout = new QGridLayout(verticalPage);
    verticalPage->setLayout(verticalPageLayout);
    verticalPageLayout->setContentsMargins(0, 0, 0, 0);

    insertionPages->setSizePolicy(
        QSizePolicy::Expanding,
        QSizePolicy::Fixed);
    insertionPages->addWidget(spiralPage);
    insertionPages->addWidget(pendulumPage);
    insertionPages->addWidget(verticalPage);
}

void PocketWidget::setupConnections() {
    connect(typeCombo,
            &QComboBox::currentIndexChanged,
            this,
            [this](int index) {
                typePages->setCurrentIndex(index);
                if (index == 0) {
                    machiningWidget->show();
                } else {
                    machiningWidget->hide();
                }
            });

    connect(insertionCombo,
            &QComboBox::currentIndexChanged,
            this,
            [this](int index) {
                insertionPages->setCurrentIndex(index);
            });

    connect(btnGenerate, &QPushButton::clicked, this, [this]() {
        PocketParams params = readParamsFromUi();
        emit generated(
            pocketService.generate(params));
    });
}

PocketParams PocketWidget::readParamsFromUi() {
    PocketParams params;

    params.type = static_cast<PocketType>(typeCombo->currentData().toInt());

    params.x = centerXEdit->text().toDouble();
    params.y = centerYEdit->text().toDouble();
    params.depth = depthEdit->text().toDouble();

    params.radius = pocketRadius->text().toDouble();
    params.length = pocketLength->text().toDouble();
    params.width = pocketWidth->text().toDouble();

    params.insertion = static_cast<InsertionType>(insertionCombo->currentData().toInt());

    params.insertionR = insertionR->text().toDouble();
    params.insertionH = insertionH->text().toDouble();
    params.insertionAngle = insertionAlpha0->text().toDouble();

    params.machining = static_cast<CircularMachining>(machiningCombo->currentData().toInt());

    return params;
}

void PocketWidget::setupValidators() {
    auto *validator =
        new QDoubleValidator(-999999, 999999, 3, this);

    validator->setNotation(QDoubleValidator::StandardNotation);

    QList<QLineEdit *> edits = findChildren<QLineEdit *>();

    for (auto *edit : edits)
        edit->setValidator(validator);
}