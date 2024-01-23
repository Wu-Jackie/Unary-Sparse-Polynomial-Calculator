//window.h
#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <QMainWindow>
#include <QSystemTrayIcon>
#include "calculator.h"
#include "information.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

    QString a="";
    QString b="";
    QString m="";

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_0_clicked();
    void on_pushButton_backspace_clicked();//退格
    void on_pushButton_minus_clicked();//减
    void on_pushButton_plus_clicked();//加
    void on_pushButton_x_clicked();//x
    void on_pushButton_dot_clicked();//点
    void on_pushButton_power_clicked();//乘方
    void on_plus_clicked();
    void on_minus_clicked();
    void on_calculate_x_clicked();
    void on_Aclear_clicked();
    void on_Bclear_clicked();
    void on_Cclear_clicked();
    void on_about_triggered();

private:
    Ui::Window *ui;
    QPoint m_point;
        QSystemTrayIcon *trayIcon;
        QMenu* trayIconMenu;
        QAction* quitAction;
        QAction* aboutAction;
        QAction* minAction;
        QAction* restoreAction;
        QAction* configAction;
        calculator c;
        int m_i = 0;
        int queren = 0;

        Information *info;
};
#endif // WINDOW_H
