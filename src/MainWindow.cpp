#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileHelper = new FileHelper(this);
    openSaveDialog = new QFileDialog(this);
    openSaveDialog->setNameFilters(fileHelper->filter);
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(actionFileOpenClicked()));
    connect(ui->actionClose, SIGNAL(triggered()), SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actionFileOpenClicked()
{
    QString text;
    openSaveDialog->setAcceptMode(QFileDialog::AcceptOpen);
    openSaveDialog->setDirectory(QDir::currentPath());
    connect(fileHelper, SIGNAL(fileContent(text)),
            ui->mainEditor, SLOT(insertPlainText(text)));
    if(openSaveDialog->exec() == QFileDialog::Accept)
    {
        QString selectFileName = openSaveDialog->selectedFiles().first();
        fileHelper->fileOpen(selectFileName);
    }
}

void MainWindow::actionFileSaveClicked()
{
    openSaveDialog->setAcceptMode(QFileDialog::AcceptSave);
}
