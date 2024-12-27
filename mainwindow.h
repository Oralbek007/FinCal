#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_addButton_clicked();

    void on_AddButton_clicked();

private:
    Ui::MainWindow *ui;

    // Переменные
    int additionalButtonX;  // Координата X для размещения новых кнопок

    double totalExpenses = 0.0;
    void handleSecondButtonClick(QPushButton *button, QLabel *label);
};

#endif // MAINWINDOW_H
