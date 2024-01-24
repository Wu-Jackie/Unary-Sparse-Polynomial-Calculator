#include "window.h"
#include "ui_window.h"
#include <QMouseEvent>
#include <QPoint>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QDialog>
#include <QMessageBox>
#include <QProcess>
#include <QSplashScreen>
//#include <synchapi.h>
#include <QKeyEvent>
#include <QScrollBar>
#include <QLineEdit>
#include <QWidget>
#include <QRegExpValidator>

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    setWindowTitle("简易计算器");
    setWindowIcon(QIcon(":/nuc.ico"));
    QRegExp regx("[x0-9+-/./^]+$");
    QValidator *validator=new QRegExpValidator(regx,this);

        ui->AlineEdit->setValidator(validator);
        ui->BlineEdit->setValidator(validator);
}

Window::~Window()
{
    delete ui;
}

void Window::mousePressEvent(QMouseEvent *e){
    if(e->button()==Qt::LeftButton){
        m_point=e->globalPos()-pos();//如果是左键，计算鼠标按下时的全局位置减去窗口的位置，并将结果存储在成员变量 m_point 中
        e->accept();//表示事件已被处理。
    }
}

void Window::mouseMoveEvent(QMouseEvent *e){
    if(e->button()&Qt::LeftButton){
        move(e->globalPos()-m_point);//移动窗口到当前全局鼠标位置减去之前存储的 m_point
        e->accept();
    }
}


void Window::on_pushButton_0_clicked(){
    if(ui->BlineEdit->hasFocus()){
        b+="0";
        ui->BlineEdit->setText(ui->BlineEdit->text()+"0");
    }else if(ui->XlineEdit->hasFocus()) {
        m+="0";
        ui->XlineEdit->setText(ui->XlineEdit->text()+"0");
    }else{
        a+="0";
        ui->AlineEdit->setText(ui->AlineEdit->text()+"0");
    }
}

void Window::on_pushButton_1_clicked(){
    if(ui->BlineEdit->hasFocus()){
        b+="1";
        ui->BlineEdit->setText(ui->BlineEdit->text()+"1");
    }else if(ui->XlineEdit->hasFocus()) {
        m+="1";
        ui->XlineEdit->setText(ui->XlineEdit->text()+"1");
    }else{
        a+="1";
        ui->AlineEdit->setText(ui->AlineEdit->text()+"1");
    }
}

void Window::on_pushButton_2_clicked(){
    if(ui->BlineEdit->hasFocus()){
        b+="2";
        ui->BlineEdit->setText(ui->BlineEdit->text()+"2");
    }else if(ui->XlineEdit->hasFocus()) {
        m+="2";
        ui->XlineEdit->setText(ui->XlineEdit->text()+"2");
    }else{
        a+="2";
        ui->AlineEdit->setText(ui->AlineEdit->text()+"2");
    }
}

void Window::on_pushButton_3_clicked(){
    if(ui->BlineEdit->hasFocus()){
        b+="3";
        ui->BlineEdit->setText(ui->BlineEdit->text()+"3");
    }else if(ui->XlineEdit->hasFocus()) {
        m+="3";
        ui->XlineEdit->setText(ui->XlineEdit->text()+"3");
    }else{
        a+="3";
        ui->AlineEdit->setText(ui->AlineEdit->text()+"3");
    }
}

void Window::on_pushButton_4_clicked(){
    if(ui->BlineEdit->hasFocus()){
        b+="4";
        ui->BlineEdit->setText(ui->BlineEdit->text()+"4");
    }else if(ui->XlineEdit->hasFocus()) {
        m+="4";
        ui->XlineEdit->setText(ui->XlineEdit->text()+"4");
    }else{
        a+="4";
        ui->AlineEdit->setText(ui->AlineEdit->text()+"4");
    }
}

void Window::on_pushButton_5_clicked(){
    if(ui->BlineEdit->hasFocus()){
        b+="5";
        ui->BlineEdit->setText(ui->BlineEdit->text()+"5");
    }else if(ui->XlineEdit->hasFocus()) {
        m+="5";
        ui->XlineEdit->setText(ui->XlineEdit->text()+"5");
    }else{
        a+="5";
        ui->AlineEdit->setText(ui->AlineEdit->text()+"5");
    }
}

void Window::on_pushButton_6_clicked(){
    if(ui->BlineEdit->hasFocus()){
        b+="6";
        ui->BlineEdit->setText(ui->BlineEdit->text()+"6");
    }else if(ui->XlineEdit->hasFocus()) {
        m+="6";
        ui->XlineEdit->setText(ui->XlineEdit->text()+"6");
    }else{
        a+="6";
        ui->AlineEdit->setText(ui->AlineEdit->text()+"6");
    }
}

void Window::on_pushButton_7_clicked(){
    if(ui->BlineEdit->hasFocus()){
        b+="7";
        ui->BlineEdit->setText(ui->BlineEdit->text()+"7");
    }else if(ui->XlineEdit->hasFocus()) {
        m+="7";
        ui->XlineEdit->setText(ui->XlineEdit->text()+"7");
    }else{
        a+="7";
        ui->AlineEdit->setText(ui->AlineEdit->text()+"7");
    }
}

void Window::on_pushButton_8_clicked(){
    if(ui->BlineEdit->hasFocus()){
        b+="8";
        ui->BlineEdit->setText(ui->BlineEdit->text()+"8");
    }else if(ui->XlineEdit->hasFocus()) {
        m+="8";
        ui->XlineEdit->setText(ui->XlineEdit->text()+"8");
    }else{
        a+="8";
        ui->AlineEdit->setText(ui->AlineEdit->text()+"8");
    }
}

void Window::on_pushButton_9_clicked(){
    if(ui->BlineEdit->hasFocus()){
        b+="9";
        ui->BlineEdit->setText(ui->BlineEdit->text()+"9");
    }else if(ui->XlineEdit->hasFocus()) {
        m+="9";
        ui->XlineEdit->setText(ui->XlineEdit->text()+"9");
    }else{
        a+="9";
        ui->AlineEdit->setText(ui->AlineEdit->text()+"9");
    }
}

void Window::on_pushButton_backspace_clicked(){
    if(ui->BlineEdit->hasFocus()){
        if(ui->BlineEdit->text()!=""){
            QString temp=ui->BlineEdit->text();
            temp=temp.left(temp.length()-1);
            ui->BlineEdit->setText(temp);
        }
    }else if(ui->XlineEdit->hasFocus()){
        if(ui->XlineEdit->text()!=""){
            QString temp=ui->XlineEdit->text();
            temp=temp.left(temp.length()-1);
            ui->XlineEdit->setText(temp);
        }
    }else {
        if(ui->AlineEdit->text()!=""){
            QString temp=ui->AlineEdit->text();
            temp=temp.left(temp.length()-1);
            ui->AlineEdit->setText(temp);
        }
    }
}

void Window::on_pushButton_minus_clicked(){
    if(ui->BlineEdit->hasFocus()){
        b+="-";
        ui->BlineEdit->setText(ui->BlineEdit->text()+"-");
    }else {
        a+="-";
        ui->AlineEdit->setText(ui->AlineEdit->text()+"-");
    }
}

void Window::on_pushButton_plus_clicked(){
    if(ui->BlineEdit->hasFocus()){
        b+="+";
        ui->BlineEdit->setText(ui->BlineEdit->text()+"+");
    }else {
        a+="+";
        ui->AlineEdit->setText(ui->AlineEdit->text()+"+");
    }
}

void Window::on_pushButton_x_clicked(){
    if(ui->BlineEdit->hasFocus()){
        b+="x";
        ui->BlineEdit->setText(ui->BlineEdit->text()+"x");
    }else {
        a+="x";
        ui->AlineEdit->setText(ui->AlineEdit->text()+"x");
    }
}

void Window::on_pushButton_dot_clicked(){
    if(ui->BlineEdit->hasFocus()){
        b+=".";
        ui->BlineEdit->setText(ui->BlineEdit->text()+".");
    }else {
        a+=".";
        ui->AlineEdit->setText(ui->AlineEdit->text()+".");
    }
}

void Window::on_pushButton_power_clicked(){
    if(ui->BlineEdit->hasFocus()){
        b+="^";
        ui->BlineEdit->setText(ui->BlineEdit->text()+"^");
    }else {
        a+="^";
        ui->AlineEdit->setText(ui->AlineEdit->text()+"^");
    }
}

void Window::on_plus_clicked(){
    if(!c.check(ui->AlineEdit->text())){
        QMessageBox::about(NULL,"计算错误","存在错误的多项式A！");
        return;
    }if(!c.check(ui->BlineEdit->text())){
        QMessageBox::about(NULL,"计算错误","存在错误的多项式B！");
        return;
    }
    ui->AlineEdit->setText(c.Build(ui->AlineEdit->text(),1));
    ui->BlineEdit->setText(c.Build(ui->BlineEdit->text(),2));
    ui->ClineEdit->setText(c.algorithm(1));

}

void Window::on_minus_clicked(){
    if(!c.check(ui->AlineEdit->text())){
        QMessageBox::about(NULL,"计算错误","存在错误的多项式A！");
        return;
    }if(!c.check(ui->BlineEdit->text())){
        QMessageBox::about(NULL,"计算错误","存在错误的多项式B！");
        return;
    }
    ui->AlineEdit->setText(c.Build(ui->AlineEdit->text(),1));
    ui->BlineEdit->setText(c.Build(ui->BlineEdit->text(),2));
    ui->ClineEdit->setText(c.algorithm(2));

}

void Window::on_calculate_x_clicked(){
    bool OK;
    QString text;
    text=ui->XlineEdit->text();
    int r=text.toInt(&OK);
    ui->XlineEdit->setText(c.calX1(r));
}

void Window::on_Aclear_clicked(){
    ui->AlineEdit->clear();
}

void Window::on_Bclear_clicked(){
    ui->BlineEdit->clear();
}

void Window::on_Cclear_clicked()
{
     ui->AlineEdit->clear();
     ui->BlineEdit->clear();
     ui->ClineEdit->clear();
}

void Window::on_about_triggered()
{
    this->info = new Information;
    info->setWindowFlags(info->windowFlags() | Qt::Dialog);
    info->show();
}
