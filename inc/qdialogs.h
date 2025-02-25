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
        QLabel *left_speed_boud = new QLabel("0"), *right_speed_bound  = new QLabel("35");
        QLabel *cur_speed_value = new QLabel("5");
        QSlider *speed_slider = new QSlider(Qt::Horizontal);
        speed_slider->setObjectName("speed_slider");
        speed_slider->setTickInterval(1);
        speed_slider->setRange(0, 35);
        speed_slider->setValue(5); // Начальное значение
        speed_slider->setTickPosition(QSlider::TicksBelow);

        QLabel *angle_label = new QLabel("Установите направление ветра (в градусах по часовой стрелке от севера):");
        QSlider *angle_slider = new QSlider(Qt::Horizontal);
        QLabel *left_angle_boud = new QLabel("0"), *right_angle_bound  = new QLabel("360");
        QLabel *cur_angle_value = new QLabel("90");
        angle_slider->setObjectName("angle_slider");
        angle_slider->setTickInterval(5);
        angle_slider->setRange(0, 360);
        angle_slider->setValue(90); // Начальное значение
        angle_slider->setTickPosition(QSlider::TicksBelow);


        QPushButton *okButton = new QPushButton("OK", this);
        QPushButton *cancelButton = new QPushButton("Cancel", this);


        QGridLayout *mainLayout = new QGridLayout(this);
        mainLayout->addWidget(speed_label, 0, 0, 1, 3, Qt::AlignJustify);
        mainLayout->addWidget(left_speed_boud, 1, 0, 1, 1, Qt::AlignLeft);
        mainLayout->addWidget(speed_slider, 1, 1, 1, 1, Qt::AlignJustify);
        mainLayout->addWidget(right_speed_bound, 1, 2, 1, 1, Qt::AlignRight);
        mainLayout->addWidget(cur_speed_value, 2, 0, 1, 3, Qt::AlignJustify);
        mainLayout->addWidget(angle_label, 3, 0, 1, 3, Qt::AlignJustify);
        mainLayout->addWidget(left_angle_boud, 4, 0, 1, 1, Qt::AlignLeft);
        mainLayout->addWidget(angle_slider, 4, 1, 1, 1, Qt::AlignJustify);
        mainLayout->addWidget(right_angle_bound, 4, 2, 1, 1, Qt::AlignRight);
        mainLayout->addWidget(cur_angle_value, 5, 0, 1, 3, Qt::AlignJustify);

        QHBoxLayout *buttonLayout = new QHBoxLayout();
        buttonLayout->addWidget(okButton);
        buttonLayout->addWidget(cancelButton);

        mainLayout->addLayout(buttonLayout, 6, 0, 1, 3, Qt::AlignJustify);

        connect(okButton, &QPushButton::clicked, this, &WindDialog::accept);
        connect(cancelButton, &QPushButton::clicked, this, &WindDialog::reject);
        connect(speed_slider, &QSlider::valueChanged, [cur_speed_value](int value) {
            cur_speed_value->setText(QString("%1").arg(value));
        });
        connect(angle_slider, &QSlider::valueChanged, [cur_angle_value](int value) {
            cur_angle_value->setText(QString("%1").arg(value));
        });
    }

     [[nodiscard]] int getWindSpeed() const {
        auto slider = findChild<QSlider *>("speed_slider");
        return slider->value();
    }

};


#endif //CP_CG_QDIALOGS_H
