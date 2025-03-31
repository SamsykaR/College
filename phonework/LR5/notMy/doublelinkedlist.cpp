/// \file doublelinkedlist.cpp
/// \brief Реализация двусвязного списка
#include "doublelinkedlist.h"

namespace list_nsp {

Node* createNode(Patient value, Node* next, Node *prev) {
  Node *node = new Node;

  node->value = value;
  node->next = next;
  node->prev = prev;

  return node;
}

void init(DoubleLinkedList& list) {
  list.first = nullptr;
  list.last = nullptr;
}

void clear(DoubleLinkedList& list) {
  while (list.first != nullptr)
    remove(list, list.last);
}

void push_back(DoubleLinkedList& list, Patient value) {
  if (list.last == nullptr) {
    list.first = createNode(value, nullptr, nullptr);
    list.last = list.first;
    return;
  }

  list.last->next = createNode(value, nullptr, list.last);
  list.last = list.last->next;
}

void push_front(DoubleLinkedList& list, Patient value) {
  if (list.last == nullptr) {
    push_back(list, value);
  }

  list.first->prev = createNode(value, list.first, nullptr);
  list.first = list.first->prev;
}

//! удаляет элемент из списка
void remove(DoubleLinkedList& list, const Node* node) {
  if (node == list.first || node == list.last) {
    if (node == list.first) {
      list.first = list.first->next;
      if (list.first)
        list.first->prev = nullptr;
    }

    if (node == list.last) {
      list.last = list.last->prev;
      if (list.last)
        list.last->next = nullptr;
    }
  }
  else {
    node->next->prev = node->prev;
    node->prev->next = node->next;
  }

  delete node;
}

size_t size(DoubleLinkedList& list) {
  size_t n = 0;
  for (auto node = list.first; node != nullptr; node = node->next) {
    ++n;
  }
  return n;
}

bool load(QTextStream& ist, DoubleLinkedList& list) {
  if (ist.status() != QTextStream::Status::Ok) {
    return false;
  }

  while (true) {
    Patient value;
    if (false == value.load(ist))
        break;

    if (ist.status() != QTextStream::Status::Ok) {
      break;
    }

    push_back(list, value);
  }

  return true;
}

void save(QTextStream& ost, DoubleLinkedList& list) {
  for (Node* node = list.first; node != nullptr; node = node->next) {
    node->value.save(ost);
  }
}

Node* nth0(DoubleLinkedList& list, int n) {
    auto node = list.first;
    for (int i = 0; i < n; ++i) {
        if (nullptr != node) {
            break;
        }
        node = node->next;
    }
    return node;
}

}

