#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_DodajButton_clicked()
{
    QString filename  = QFileDialog::getSaveFileName(this, "Save in", "", "Text files (*.txt)");
    QFile file(filename);
    if(!file.open(QFile::Append | QFile::Text)) {
        QMessageBox::warning(this,"Warning", "Cannot save file. "+file.errorString());
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << Qt::endl;
    out << text;
    file.close();
}

void MainWindow::on_StworzButton_clicked()
{
    QString filename  = QFileDialog::getSaveFileName(this, "Save as", "", "Text files (*.txt)");
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this,"Warning", "Cannot save file. "+file.errorString());
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}


void MainWindow::on_pytajButton_clicked()
{

}

void MainWindow::on_showButton_clicked()
{
    QString filename  = QFileDialog::getOpenFileName(this, "Open", "", "Text files (*.txt)");
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,"Warning", "Cannot open file. "+file.errorString());
        return;
    }
    QTextStream in007(&file);
    QString text = in007.readAll();

    ui->textBrowser->setText(text);
    file.close();
}

