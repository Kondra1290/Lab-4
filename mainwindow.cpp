#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    indicator = new ProgressIndicator();
    ui->gridLayout->addWidget(indicator,0,1);

    connect(indicator, &QSlider::valueChanged, [=](int value) {
        ui->lineEdit->setText(QString::number(value));
    });

    connect(indicator, &QSlider::valueChanged, [&](int value) {
        QColor color;
        value = value >= 0 ? value : value*(-1);
        color.setHsv(value, 255, 255);
        ui->label_4->setStyleSheet("color: #" + QString::number(color.rgb(), 16));
    });

    resize(350, 350);
}

MainWindow::~MainWindow()
{
    delete indicator;
    delete ui;
}


void MainWindow::on_Button1_clicked()
{
    indicator->setMaximumValue(ui->lineEdit_2->text().toInt());
}

void MainWindow::on_Button2_clicked()
{
    indicator->setMimmumValue(ui->lineEdit_3->text().toInt());
}

