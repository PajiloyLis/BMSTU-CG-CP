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

        QLabel *speed_label = new QLabel("Установите скорость ветра (м/с):");
        QSlider *speed_slider = new QSlider(Qt::Horizontal);
        speed_slider->setObjectName("speed_slider");
        speed_slider->setTickInterval(1);
        speed_slider->setRange(0, 35);
        speed_slider->setValue(5); // Начальное значение

        QLabel *angle_label = new QLabel("Установите направление ветра (в градусах по часовой стрелке от севера):");
        QSlider *angle_slider = new QSlider(Qt::Horizontal);
        angle_slider->setObjectName("angle_slider");
        angle_slider->setTickInterval(1);
        speed_slider->setRange(0, 360);
        speed_slider->setValue(90); // Начальное значение

        QPushButton *okButton = new QPushButton("OK", this);
        QPushButton *cancelButton = new QPushButton("Cancel", this);


        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(speed_label);
        mainLayout->addWidget(speed_slider);
        mainLayout->addWidget(angle_label);
        mainLayout->addWidget(angle_slider);

        QHBoxLayout *buttonLayout = new QHBoxLayout();
        buttonLayout->addWidget(okButton);
        buttonLayout->addWidget(cancelButton);

        mainLayout->addLayout(buttonLayout);

        connect(okButton, &QPushButton::clicked, this, &WindDialog::accept);
        connect(cancelButton, &QPushButton::clicked, this, &WindDialog::reject);
    }

     [[nodiscard]] int getWindSpeed() const {
        auto slider = findChild<QSlider *>("speed_slider");
        return slider->value();
    }

};


#endif //CP_CG_QDIALOGS_H
