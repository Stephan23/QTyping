#include "application.h"
#include "ui_application.h"

typedef enum{NORMAL, RED, GREEN} markType;

Application::Application(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Application)
{
    loadWordList();
    ui->setupUi(this);
    for(int i = 0; i < words.length(); i++)
    {
        actionWords.append(words.at(i));
    }
    updateMarke(NORMAL);
}
void Application::loadWordList()
{
    QFile file("\Wortliste.txt");
         if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        words.append(line);
        qDebug() << line;
        //process_line(line);
    }
}

Application::~Application()
{
    delete ui;
}

void Application::updateMarke(int markType)
{
    ui->label->clear();
    for(int i = 0; i < actionWords.length(); i++)
    {
        qDebug()<< wordsTippedInLine;
        if(i == wordsTippedInLine)
        {
            switch(markType)
            {
            case NORMAL:
                ui->label->setText(ui->label->text() + "<b>" + actionWords.at(i) + "</b>" + " ");
                break;
            case RED:
                ui->label->setText(ui->label->text() + "<font color=red><b>" + actionWords.at(i) + "</b></font>" + " ");
                break;
            }


        }
        else
        {
            ui->label->setText(ui->label->text() + actionWords.at(i) + " ");
        }
    }
}

void Application::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1.at(arg1.length()-1) == ' ')
    {
        wordsTippedInLine ++;
        updateMarke(NORMAL);
        ui->lineEdit->clear();
    }
    else if(actionWords.at(wordsTippedInLine).left(ui->lineEdit->text().length()).compare(ui->lineEdit->text()))
    {
        updateMarke(RED);
    }
    else
    {
        updateMarke(NORMAL);
    }
}
