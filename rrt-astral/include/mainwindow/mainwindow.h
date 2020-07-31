#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "common/renderarea.h"
#include "rrt/rrt.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    RenderArea *renderArea;
    RRT *rrt;
    bool simulated;
private slots:
    void on_startButton_clicked();
    void on_resetButton_clicked();
};

#endif // MAINWINDOW_H