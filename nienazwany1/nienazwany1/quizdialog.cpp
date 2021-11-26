#include "quizdialog.h"
#include "ui_quizdialog.h"

Quizdialog::Quizdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Quizdialog)
{
    ui->setupUi(this);
    ui-> label_3 -> setText("");
    ui-> label_4 -> setText("");
    w=l=0;

    QString filename  = QFileDialog::getOpenFileName(this, "Open", "", "Text files (*.txt)");
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,"Warning", "Cannot open file. "+file.errorString());
        return;
    }
    QTextStream in007(&file); //wczytywanie danych z pliku do zmiennej in007
    lista = in007.readAll(); //zmienna globalna dla calego qiuzdialog
    file.close();

    QString text1,text2; //zadane pierwsze pytanie
    text1 = lista.section('\n',l,l);
    text2 = text1.section(':',0,0);
    ui->textBrowser->setText(text2);
    l++;

}

Quizdialog::~Quizdialog()
{
    delete ui;

}

void Quizdialog::on_pushButton_clicked()
{

    QString text1,text2,text3;
    text1 = lista.section('\n',l-1,l-1);
    text2 = text1.section(':',1,1);
    text3 = ui-> textEdit-> toPlainText();
    if(text3 == text2) {
        ui-> label_3 -> setText("Prawidłowa odpowiedź");
        w++;
    } else {
        text3 = "Zła odpowiedź: " + text1;
        ui-> label_3 -> setText( text3);
    }
    text1.setNum(w);
    text2.setNum(l);
    text3= "Poprawne odpowiedzi " + text1 + "/" + text2 ;
    ui-> label_4 -> setText(text3); //to_string(l) + (char)w

    text1 = lista.section('\n',l,l);
    text2 = text1.section(':',0,0);
    ui->textBrowser->setText(text2);
    l++;
}
