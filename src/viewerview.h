#ifndef VIEWERVIEW_H
#define VIEWERVIEW_H

#include <QMainWindow>
#include "viewercontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ViewerView; }
QT_END_NAMESPACE

class ViewerView : public QMainWindow
{
    Q_OBJECT

public:
    ViewerView(QWidget *parent = nullptr);
    ~ViewerView();

private slots:
    void LoadFile();

private:
    Ui::ViewerView *ui;
    ViewerController *controller;
};
#endif // VIEWERVIEW_H