#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QDebug>

namespace Ui {
class Application;
}

class Application : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Application(QWidget *parent = 0);
    ~Application();
    
private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    int wordsTipped = 0;
    int wordsTippedInLine = 0;

    Ui::Application *ui;
    QList<QString> words;
    QList<QString> actionWords;
    QList<QString> commingWords;
    void loadWordList();
    void fillList();
    void updateMarke(int markType);
};

#endif // APPLICATION_H
