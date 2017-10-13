#include "camera.h"
#include "ui_camera.h"

Camera::Camera(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Camera)
{
    ui->setupUi(this);
}

Camera::~Camera()
{
    delete ui;
}
