// PocketWidget.cpp
#include "ControlWidget.h"

namespace pocket {
ControlWidget::ControlWidget(Data *data, QWidget *parent) : QWidget(parent), data(data) {
    setFixedWidth(200);
    setupUi();
    setupPages();
    setupInputFields();
    setupConnections();
}

ControlWidget::~ControlWidget() {}

void ControlWidget::setupUi() {
    typeCombo = new QComboBox(this);
    typeCombo->addItem("Круговой", (int) PocketType::Circular);
    typeCombo->addItem("Прямоугольный", (int) PocketType::Rectangular);

    ToolNumberEdit = new QLineEdit(this);
    FeedEdit = new QLineEdit(this);
    SpindleSpeedEdit = new QLineEdit(this);

    typePages = new QStackedWidget(this);

    XEdit = new QLineEdit(this);
    YEdit = new QLineEdit(this);
    ZEdit = new QLineEdit(this);
    Z1Edit = new QLineEdit(this);
    DZEdit = new QLineEdit(this);

    insertionCombo = new QComboBox(this);
    insertionCombo->addItem("По спирали", (int) InsertionType::Spiral);
    insertionCombo->addItem("Маятниковое", (int) InsertionType::Pendulum);
    insertionCombo->addItem("Вертикальное", (int) InsertionType::Vertical);
    insertionPages = new QStackedWidget(this);

    machiningCombo = new QComboBox(this);
    machiningCombo->addItem("В плоскости", (int) MachiningType::Planar);
    machiningCombo->addItem("Спирально", (int) MachiningType::Helical);

    auto *machiningLayout = new QHBoxLayout();
    machiningLayout->setContentsMargins(0, 0, 0, 0);
    machiningLayout->setSpacing(8);
    machiningLayout->addWidget(new QLabel("Обработка", this));
    machiningLayout->addWidget(machiningCombo);
    machiningWidget = new QWidget(this);
    machiningWidget->setLayout(machiningLayout);

    auto *form = new QFormLayout();
    form->addRow("Тип", typeCombo);
    form->addRow("T", ToolNumberEdit);
    form->addRow("F", FeedEdit);
    form->addRow("S", SpindleSpeedEdit);
    form->addRow(typePages);
    form->addRow("X", XEdit);
    form->addRow("Y", YEdit);
    form->addRow("Z", ZEdit);
    form->addRow("Z1", Z1Edit);
    form->addRow("DZ", DZEdit);
    form->addRow("Врезание", insertionCombo);
    form->addRow(insertionPages);
    form->addRow(machiningWidget);

    auto *root = new QVBoxLayout(this);
    root->setContentsMargins(8, 8, 8, 8);
    root->setSpacing(8);
    root->addWidget(new QLabel("Карман", this));
    root->addLayout(form);
    root->addStretch();
}

void ControlWidget::setupInputFields() {
    auto *validator = new QDoubleValidator(this);
    validator->setDecimals(3);
    validator->setRange(-999999, 999999, 3);
    validator->setNotation(QDoubleValidator::StandardNotation);
    validator->setLocale(QLocale::C);

    QList<QLineEdit *> edits = findChildren<QLineEdit *>();

    for (auto *edit : edits) {
        edit->setValidator(validator);
        edit->setPlaceholderText("0.000");
        edit->setAlignment(Qt::AlignRight);
        connect(edit, &QLineEdit::textChanged, this,
                [this]() { data->setParams(readParamsFromUi()); });
    }

    QList<QComboBox *> combos = findChildren<QComboBox *>();

    for (auto *combo : combos) {
        connect(combo, &QComboBox::currentIndexChanged, this,
                [this](int) { data->setParams(readParamsFromUi()); });
    }
}

void ControlWidget::setupPages() {
    QWidget *circularPage = new QWidget(this);
    auto *circularPageLayout = new QGridLayout(circularPage);
    circularPage->setLayout(circularPageLayout);
    circularPageLayout->setContentsMargins(0, 0, 0, 0);
    circularPageLayout->addWidget(new QLabel("R", circularPage), 0, 0);
    pocketRadius = new QLineEdit(circularPage);
    circularPageLayout->addWidget(pocketRadius, 0, 1);

    QWidget *rectangularPage = new QWidget(this);
    auto *rectangularPageLayout = new QGridLayout(rectangularPage);
    rectangularPageLayout->setContentsMargins(0, 0, 0, 0);
    rectangularPage->setLayout(rectangularPageLayout);
    rectangularPageLayout->addWidget(new QLabel("W", rectangularPage), 0, 0);
    pocketWidth = new QLineEdit(rectangularPage);
    rectangularPageLayout->addWidget(pocketWidth, 0, 1);
    rectangularPageLayout->addWidget(new QLabel("L", rectangularPage), 1, 0);
    pocketLength = new QLineEdit(rectangularPage);
    rectangularPageLayout->addWidget(pocketLength, 1, 1);

    typePages->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    typePages->addWidget(circularPage);
    typePages->addWidget(rectangularPage);

    QWidget *spiralPage = new QWidget(this);
    auto *spiralPageLayout = new QGridLayout(spiralPage);
    spiralPage->setLayout(spiralPageLayout);
    spiralPageLayout->setContentsMargins(0, 0, 0, 0);
    spiralPageLayout->addWidget(new QLabel("R", spiralPage), 0, 0);
    insertionR = new QLineEdit(spiralPage);
    spiralPageLayout->addWidget(insertionR, 0, 1);
    spiralPageLayout->addWidget(new QLabel("H", spiralPage), 1, 0);
    insertionH = new QLineEdit(spiralPage);
    spiralPageLayout->addWidget(insertionH, 1, 1);

    QWidget *pendulumPage = new QWidget(this);
    auto *pendulumPageLayout = new QGridLayout(pendulumPage);
    pendulumPage->setLayout(pendulumPageLayout);
    pendulumPageLayout->setContentsMargins(0, 0, 0, 0);
    pendulumPageLayout->addWidget(new QLabel("α₀", pendulumPage), 1, 0);
    insertionAlpha0 = new QLineEdit(pendulumPage);
    pendulumPageLayout->addWidget(insertionAlpha0, 1, 1);

    QWidget *verticalPage = new QWidget(this);
    auto *verticalPageLayout = new QGridLayout(verticalPage);
    verticalPage->setLayout(verticalPageLayout);
    verticalPageLayout->setContentsMargins(0, 0, 0, 0);

    insertionPages->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    insertionPages->addWidget(spiralPage);
    insertionPages->addWidget(pendulumPage);
    insertionPages->addWidget(verticalPage);
}

void ControlWidget::setupConnections() {
    connect(typeCombo, &QComboBox::currentIndexChanged, this, [this](int index) {
        typePages->setCurrentIndex(index);
        if (index == 0) machiningWidget->show();
        else machiningWidget->hide();
    });

    connect(insertionCombo, &QComboBox::currentIndexChanged, this,
            [this](int index) { insertionPages->setCurrentIndex(index); });
}

Params ControlWidget::readParamsFromUi() {
    Params params;

    params.type = static_cast<PocketType>(typeCombo->currentData().toInt());

    params.ToolNumber = ToolNumberEdit->text().toDouble();
    params.Feed = FeedEdit->text().toDouble();
    params.SpindleSpeed = SpindleSpeedEdit->text().toDouble();

    params.X = XEdit->text().toDouble();
    params.Y = YEdit->text().toDouble();
    params.Z = ZEdit->text().toDouble();
    params.Z1 = Z1Edit->text().toDouble();
    params.DZ = DZEdit->text().toDouble();

    params.radius = pocketRadius->text().toDouble();
    params.length = pocketLength->text().toDouble();
    params.width = pocketWidth->text().toDouble();

    params.insertion = static_cast<InsertionType>(insertionCombo->currentData().toInt());

    params.insertionR = insertionR->text().toDouble();
    params.insertionH = insertionH->text().toDouble();
    params.insertionAngle = insertionAlpha0->text().toDouble();

    params.machining = static_cast<MachiningType>(machiningCombo->currentData().toInt());

    return params;
}
} // namespace pocket