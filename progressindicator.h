#ifndef PROGRESSINDICATOR_H
#define PROGRESSINDICATOR_H

#include <QSlider>
#include <QLabel>
#include <QSlider>
#include <QPainter>
#include <QMouseEvent>
#include <QPushButton>
#include <QWheelEvent>
#include <QWidget>

class ProgressIndicator : public QSlider
{
public:
    ProgressIndicator(QWidget *parent = nullptr);

    inline int getProgressValue(){ return cur_val; }
    inline int getMinimumValue() { return min_val; }
    inline int getMaximumValue() { return max_val; }

    void setProgressValue(int value);
    void setMimmumValue(int value);
    void setMaximumValue(int value);

protected:
    void paintEvent(QPaintEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:

    QPushButton incButton, decButton;

    QSlider slider;
    QLabel label;
    int cur_val, max_val, min_val, cur_width;

    static const int DISTANCE   = 19;
    static const int WIDTH = 5;
    static const int DIVISIONS  = 10;
    static const int HEIGHT = 30;
    static const int CAPACITY = 700;
};

#endif // PROGRESSINDICATOR_H
