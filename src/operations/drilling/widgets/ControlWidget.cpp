// ControlWidget.cpp
#include "ControlWidget.h"

namespace drilling {

ControlWidget::ControlWidget(Data *data, QWidget *parent) : QWidget(parent), data(data) {
    setFixedWidth(200);
    setupUi();
    setupInputFields();
}

ControlWidget::~ControlWidget() {}

void ControlWidget::setupUi() {
    QFormLayout *form = new QFormLayout();

    toolNumberEdit = new QLineEdit(this);
    feedEdit = new QLineEdit(this);
    spindleSpeedEdit = new QLineEdit(this);
    xEdit = new QLineEdit(this);
    yEdit = new QLineEdit(this);
    safeZEdit = new QLineEdit(this);
    depthEdit = new QLineEdit(this);
    peckDepthEdit = new QLineEdit(this);
    holeDiameterEdit = new QLineEdit(this);

    cycleCombo = new QComboBox(this);
    cycleCombo->addItem("Simple", (int) CycleType::Simple);
    cycleCombo->addItem("Peck", (int) CycleType::Peck);

    form->addRow("Tool", toolNumberEdit);
    form->addRow("Feed", feedEdit);
    form->addRow("Spindle", spindleSpeedEdit);
    form->addRow("X", xEdit);
    form->addRow("Y", yEdit);
    form->addRow("Safe Z", safeZEdit);
    form->addRow("Depth", depthEdit);
    form->addRow("Peck Depth", peckDepthEdit);
    form->addRow("Hole Diameter", holeDiameterEdit);
    form->addRow("Cycle", cycleCombo);

    auto *root = new QVBoxLayout(this);
    root->setContentsMargins(8, 8, 8, 8);
    root->setSpacing(8);
    root->addWidget(new QLabel("Сверление", this));
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

Params ControlWidget::readParamsFromUi() {
    Params params;
    params.toolNumber = toolNumberEdit->text().toInt();
    params.feed = feedEdit->text().toDouble();
    params.spindleSpeed = spindleSpeedEdit->text().toDouble();
    params.x = xEdit->text().toDouble();
    params.y = yEdit->text().toDouble();
    params.safeZ = safeZEdit->text().toDouble();
    params.depth = depthEdit->text().toDouble();
    params.peckDepth = peckDepthEdit->text().toDouble();
    params.holeDiameter = holeDiameterEdit->text().toDouble();
    params.cycle = static_cast<CycleType>(cycleCombo->currentData().toInt());
    return params;
}

} // namespace drilling