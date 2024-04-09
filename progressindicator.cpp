#include "progressindicator.h"

ProgressIndicator::ProgressIndicator(QWidget *parent):
    QSlider(parent)
{
    setOrientation(Qt::Horizontal);
    setTickPosition(QSlider::TicksAbove);
    setRange(0, 100);
    max_val=100;
    min_val=0;
    cur_val=70;
    slider.setValue(70);

    connect(&incButton, &QPushButton::clicked, [=](){
        slider.setValue(slider.value() + 1);
        cur_val = slider.value() + 1;
    });

    connect(&decButton, &QPushButton::clicked, [=](){
        slider.setValue(slider.value() - 1);
        cur_val = slider.value() - 1;
    });
    cur_val=70;
}

void ProgressIndicator::setProgressValue(int value) {cur_val=value;}

void ProgressIndicator::setMimmumValue(int value)  {
    if(value < max_val)
    {
        setMinimum(value);
        min_val=value;
    }
}

void ProgressIndicator::setMaximumValue(int value)  {
    if(value > min_val)
    {
        setMaximum(value);
        max_val=value;
    }
}

void ProgressIndicator::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    cur_val=slider.value();
    QSlider::paintEvent(event);
}

void ProgressIndicator::wheelEvent(QWheelEvent *event){
    int delta = event->angleDelta().y() / 120;
    setValue(value() + delta);
    event->accept();
}
