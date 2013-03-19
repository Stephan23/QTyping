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
    
private:
    Ui::Application *ui;
    QList<QString> words;
    void loadWordList();
};

#endif // APPLICATION_H
