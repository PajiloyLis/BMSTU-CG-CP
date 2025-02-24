//
// Created by ivan on 25.02.25.
//

#ifndef CP_CG_QDIALOGS_H
#define CP_CG_QDIALOGS_H

#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>

class WindDialog : public QDialog {
    Q_OBJECT

public:
    WindDialog(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("Установить параметры ветра");

        QLabel *label = new QLabel("E");
        QSlider *slider = new QSlider(Qt::Horizontal);
        slider->setRange(0, 35);
        slider->setValue(5); // Начальное значение
        QLineEdit *inputField = new QLineEdit(this);
        QPushButton *okButton = new QPushButton("OK", this);
        QPushButton *cancelButton = new QPushButton("Cancel", this);

        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(label);
        mainLayout->addWidget(inputField);

        QHBoxLayout *buttonLayout = new QHBoxLayout();
        buttonLayout->addWidget(okButton);
        buttonLayout->addWidget(cancelButton);

        mainLayout->addLayout(buttonLayout);

        connect(okButton, &QPushButton::clicked, this, &WindDialog::accept);
        connect(cancelButton, &QPushButton::clicked, this, &WindDialog::reject);
    }

    QString getInputText() const {
        return findChild<QLineEdit *>())->text();
    }
};


#endif //CP_CG_QDIALOGS_H
