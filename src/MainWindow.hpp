#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QtGui/QMainWindow>
#include "FileHelper.hpp"
#include <QFileDialog>

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
    FileHelper *fileHelper;
    QFileDialog *openSaveDialog;
private slots:
    void actionFileOpenClicked();
    void actionFileSaveClicked();
};

#endif // MAINWINDOW_HPP
