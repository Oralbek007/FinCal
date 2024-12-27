#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Установка начальных значений
    ui->label1->setText("0");
    ui->label2->setText("0");
    ui->label1->setAlignment(Qt::AlignCenter);  // Центрируем текст в label
    ui->label2->setAlignment(Qt::AlignCenter);



    // Инициализация начальной позиции для новых кнопок
    additionalButtonX = ui->AddButton->geometry().right() + 10;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bool ok;
    double value = QInputDialog::getDouble(this, "Введите значение",
                                           "Введите значение для Wallet:",
                                           0, 0, 100000000, 2, &ok);

    if (ok && value > 0) {
        double currentValue = ui->label1->text().toDouble();
        ui->label1->setText(QString::number(currentValue + value));
    } else {
        QMessageBox::warning(this, "Ошибка", "Введите положительное значение!");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    handleSecondButtonClick(ui->pushButton_2, ui->label2);
}

// Указатель на последнюю добавленную кнопку
QPushButton *lastAddedButton = nullptr;

// Инициализация координат для новых кнопок
int nextButtonX;
int nextButtonY;

void MainWindow::on_AddButton_clicked()
{
    bool ok;
    QString buttonName = QInputDialog::getText(this, "Добавить кнопку",
                                               "Введите название новой кнопки:",
                                               QLineEdit::Normal, "", &ok);
    if (!ok || buttonName.isEmpty()) return;

    // Создание новой кнопки
    QPushButton *newButton = new QPushButton(buttonName, this);
    newButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #28a745;" // Основной цвет
        "    color: white;"              // Цвет текста
        "    font-weight: bold;"         // Жирный текст
        "    border: 2px solid #218838;" // Рамка
        "}"
        "QPushButton:hover {"
        "    background-color: #218838;" // Цвет при наведении
        "}"
        "QPushButton:pressed {"
        "    background-color: #1e7e34;" // Цвет при нажатии
        "}"
        );

    // Установить начальные координаты, если это первая кнопка
    if (lastAddedButton == nullptr) {
        nextButtonX = ui->pushButton_2->geometry().right() + 10;
        nextButtonY = ui->pushButton_2->geometry().y();
    }

    // Получаем ширину окна
    int windowWidth = this->width();

    // Проверяем, помещается ли кнопка в текущем ряду
    if (nextButtonX + newButton->width() > windowWidth) {
        // Если не помещается, переносим кнопку на новую строку
        nextButtonX = ui->pushButton_2->geometry().left(); // Начинаем с позиции первой кнопки
        nextButtonY += newButton->height() + 20;           // Смещаемся по Y вниз (учитываем отступы)
    }

    // Устанавливаем позицию новой кнопки
    newButton->setGeometry(nextButtonX, nextButtonY, 71, 31);
    newButton->show();

    // Создаем метку для новой кнопки
    QLabel *newLabel = new QLabel("0", this);
    newLabel->setGeometry(newButton->geometry().x(), newButton->geometry().bottom() + 2, 70, 20);
    newLabel->show();
    newLabel->setAlignment(Qt::AlignCenter);


    // Привязываем функционал к новой кнопке
    connect(newButton, &QPushButton::clicked, this, [=]() {
        handleSecondButtonClick(newButton, newLabel);
    });

    // Обновляем координаты для следующей кнопки
    nextButtonX = newButton->geometry().right() + 10; // Смещаем вправо для следующей кнопки
    lastAddedButton = newButton; // Сохраняем указатель на последнюю добавленную кнопку
}





void MainWindow::handleSecondButtonClick(QPushButton *button, QLabel *label)
{
    QStringList actions = {"Пополнить", "Отнять"};
    bool ok;
    QString action = QInputDialog::getItem(this, "Выберите действие",
                                           tr("Выберите действие для %1:").arg(button->text()),
                                           actions, 0, false, &ok);

    if (!ok || action.isEmpty()) return; // Если пользователь отменил действие

    double value = QInputDialog::getDouble(this, "Введите значение",
                                           tr("Введите значение для %1 (%2):").arg(button->text(), action),
                                           0, 0, 1000000, 2, &ok);

    if (!ok || value <= 0) {
        QMessageBox::warning(this, "Ошибка", "Введите положительное значение!");
        return;
    }

    double walletValue = ui->label1->text().toDouble();
    double buttonValue = label->text().toDouble();

    if (action == "Пополнить") {
        // Проверяем, хватает ли средств в кошельке
        if (value > walletValue) {
            QMessageBox::warning(this, "Ошибка",
                                 "Недостаточно средств в кошельке!");
            return;
        }
        // Обновляем значения
        ui->label1->setText(QString::number(walletValue - value));
        label->setText(QString::number(buttonValue + value));

        // Увеличиваем общую сумму расходов
        totalExpenses += value;
        ui->totalExpensesLabel->setText(tr("Expenses: %1").arg(totalExpenses));
    } else if (action == "Отнять") {
        // Проверяем, хватает ли средств под кнопкой
        if (value > buttonValue) {
            QMessageBox::warning(this, "Ошибка",
                                 "Недостаточно средств под кнопкой!");
            return;
        }
        // Обновляем значения
        ui->label1->setText(QString::number(walletValue + value));
        label->setText(QString::number(buttonValue - value));

        // Уменьшаем общую сумму расходов
        totalExpenses -= value;
        if (totalExpenses < 0) totalExpenses = 0; // Защита от отрицательных значений
        ui->totalExpensesLabel->setText(tr("Расходы: %1").arg(totalExpenses));
    }
}
