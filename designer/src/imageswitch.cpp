﻿#pragma execution_character_set("utf-8")

#include "imageswitch.h"
#include "qpainter.h"

ImageSwitch::ImageSwitch(QWidget *parent) : QWidget(parent)
{
	isChecked = false;
	buttonStyle = ButtonStyle_2;

	imgOffFile = ":/image/btncheckoff2.png";
	imgOnFile = ":/image/btncheckon2.png";
	imgFile = imgOffFile;
}

void ImageSwitch::mousePressEvent(QMouseEvent *)
{
	if (isChecked) {
		imgFile = imgOffFile;
	} else {
		imgFile = imgOnFile;
	}

	isChecked = !isChecked;
}

void ImageSwitch::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.setRenderHints(QPainter::SmoothPixmapTransform);
	QImage img(imgFile);
	painter.drawImage(rect(), img);
}

bool ImageSwitch::getChecked() const
{
	return isChecked;
}

ImageSwitch::ButtonStyle ImageSwitch::getButtonStyle() const
{
	return this->buttonStyle;
}

QSize ImageSwitch::sizeHint() const
{
	return QSize(87, 28);
}

QSize ImageSwitch::minimumSizeHint() const
{
	return QSize(87, 28);
}

void ImageSwitch::setChecked(bool isChecked)
{
    if (this->isChecked != isChecked){
        this->isChecked = isChecked;

        if (isChecked) {
            imgFile = imgOnFile;
        } else {
            imgFile = imgOffFile;
        }

        update();
    }
}

void ImageSwitch::setButtonStyle(ImageSwitch::ButtonStyle buttonStyle)
{
    if (this->buttonStyle != buttonStyle) {
        this->buttonStyle = buttonStyle;

        if (buttonStyle == ButtonStyle_1) {
            imgOffFile = ":/image/btncheckoff1.png";
            imgOnFile = ":/image/btncheckon1.png";
            this->resize(87, 28);
        } else if (buttonStyle == ButtonStyle_2) {
            imgOffFile = ":/image/btncheckoff2.png";
            imgOnFile = ":/image/btncheckon2.png";
            this->resize(87, 28);
        } else if (buttonStyle == ButtonStyle_3) {
            imgOffFile = ":/image/btncheckoff3.png";
            imgOnFile = ":/image/btncheckon3.png";
            this->resize(96, 38);
        }

        setChecked(isChecked);
        update();
        updateGeometry();
	}	
}