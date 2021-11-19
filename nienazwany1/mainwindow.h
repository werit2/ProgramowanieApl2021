#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile> //do obslugi plikow
#include <QFileDialog> // okno wyboru pliku
#include <QTextStream> // do wczytywania tekstu z pliku
#include <QMessageBox> //do komunikatu o bledzie przy otwarciu pliku


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pytajButton_clicked();

    void on_showButton_clicked();

    void on_DodajButton_clicked();

    void on_StworzButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
