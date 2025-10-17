#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QTextEdit>
#include <QPushButton>

/// \brief Класс окна с информацией о программе
///
/// Отображает информацию о программе
class about : public QWidget
{
    Q_OBJECT
public:
    /// \brief Конструктор класса
    /// \param parent родительский виджет
    explicit about(QWidget *parent = nullptr);

private:
    QLabel* logotype;        ///< Логотип программы
    QLabel* informationlbl;  ///< Текст с информацией о программе
    QHBoxLayout* headerLayout; ///< Макет заголовка
    QLabel *headerLabel;     ///< Заголовок окна
};

#endif // ABOUT_H
