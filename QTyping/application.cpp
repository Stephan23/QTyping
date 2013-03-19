#include "application.h"
#include "ui_application.h"

Application::Application(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Application)
{
    loadWordList();
    ui->setupUi(this);
    for(int i = 0; i < words.length(); i++)
    {
        ui->label->setText(ui->label->text() + words.at(i) + " ");
    }
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
