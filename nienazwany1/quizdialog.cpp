#include "quizdialog.h"
#include "ui_quizdialog.h"

Quizdialog::Quizdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Quizdialog)
{
    ui->setupUi(this);
    ui->textBrowser->setText("hello world");

    QString filename  = QFileDialog::getOpenFileName(this, "Open", "", "Text files (*.txt)");
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,"Warning", "Cannot open file. "+file.errorString());
        return;
    }
    QTextStream in007(&file); //wczytywanie danych z pliku do zmiennej in007
    lista = in007.readAll();

    file.close();
}

Quizdialog::~Quizdialog()
{
    delete ui;

}

void Quizdialog::on_pushButton_clicked()
{
    QString text1;
    text1 = lista.section('\n',0,0);
    ui->textBrowser->setText(text1);
}
