#ifndef QUIZDIALOG_H
#define QUIZDIALOG_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <sstream> //konwersja string - int

namespace Ui {
class Quizdialog;
}

class Quizdialog : public QDialog
{
    Q_OBJECT

    QString lista;
    int l,w;

public:
    explicit Quizdialog(QWidget *parent = nullptr);
    ~Quizdialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Quizdialog *ui;
};

#endif // QUIZDIALOG_H
