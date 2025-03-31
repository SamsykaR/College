/// \file doublelinkedlist.h
/// \brief Заголовочный файл двусвязного списка

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
#include "patient.h"
#include <fstream>
using namespace std;

namespace list_nsp {

/// \struct Node
/// \brief Узел двусвязного списка
///
/// Содержит данные пациента и указатели на соседние узлы
struct Node {
    Patient value;  /*!< Данные пациента */
    Node* next;     /*!< Указатель на следующий узел */
    Node* prev;     /*!< Указатель на предыдущий узел */
};

/// \struct DoubleLinkedList
/// \brief Двусвязный список
///
/// Хранит указатели на первый и последний узлы списка
struct DoubleLinkedList {
    Node *first;    /*!< Указатель на первый узел списка */
    Node *last;     /*!< Указатель на последний узел списка */
};

/// \brief Создает новый узел
/// \param value Данные пациента
/// \param next Указатель на следующий узел
/// \param prev Указатель на предыдущий узел
/// \return Указатель на созданный узел
Node* createNode(Patient value, Node* next, Node* prev);

/// \brief Инициализирует список
/// \param list Ссылка на список
void init(DoubleLinkedList& list);

/// \brief Очищает список, удаляя все узлы
/// \param list Ссылка на список
void clear(DoubleLinkedList& list);

/// \brief Добавляет элемент в конец списка
/// \param list Ссылка на список
/// \param value Данные пациента
void push_back(DoubleLinkedList& list, Patient value);

/// \brief Добавляет элемент в начало списка
/// \param list Ссылка на список
/// \param value Данные пациента
void push_front(DoubleLinkedList& list, Patient value);

/// \brief Удаляет указанный узел из списка
/// \param list Ссылка на список
/// \param node Указатель на удаляемый узел
void remove(DoubleLinkedList& list, const Node* node);


/// \brief Возвращает n-й узел списка (индексация с 0)
/// \param list Ссылка на список
/// \param n Индекс узла
/// \return Указатель на узел или nullptr, если индекс некорректен
Node* nth0(DoubleLinkedList& list, int n);


/// \brief Возвращает количество элементов в списке
/// \param list Ссылка на список
/// \return Размер списка
size_t size(DoubleLinkedList& list);

/// \brief Загружает данные из потока в список
/// \param ist Входной поток
/// \param list Ссылка на список
/// \return true, если загрузка успешна, иначе false
bool load(QTextStream& ist, DoubleLinkedList& list);

/// \brief Сохраняет данные списка в поток
/// \param ost Выходной поток
/// \param list Ссылка на список
void save(QTextStream& ost, DoubleLinkedList& list);

}
#endif // DOUBLELINKEDLIST_H
