//information.cpp
#include "information.h"
#include "ui_information.h"
#include <QIcon>

Information::Information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/CSTlogo.ico"));
    ui->pic->setPixmap(QPixmap(":/NUC.jpeg"));
    ui->pic->setScaledContents(true);
    ui->pic->lower();
    setWindowTitle("关于");
}

Information::~Information()
{
    delete ui;
}

void Information::on_pushButton_clicked()
{
    this->close();
}
