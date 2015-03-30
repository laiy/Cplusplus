#include "DouList.h"
#include <sstream>

int DouList::_error_sign = -1;

DouList::DouList() {
    m_head = m_tail = NULL;
}

DouList::DouList(const DouList &src) {
    m_head = m_tail = NULL;
    *this = src;
}

DouList::~DouList() {
    this->clear();
}

void DouList::clear() {
    if (this->empty()) return;
    DouListNode *temp;
    while (m_head != m_tail) {
        temp = m_head;
        m_head = m_head->next;
        delete temp;
    }
    delete m_head;
    m_head = m_tail = NULL;
}

bool DouList::empty() const {
    return m_head == NULL && m_tail == NULL;
}

std::string DouList::to_str() const {
    if (this->empty()) return "[]";
    std::stringstream ss;
    DouListNode *temp = m_head;
    ss << '[';
    while (temp != m_tail) {
        ss << temp->elem << ", ";
        temp = temp->next;
    }
    ss << temp->elem << ']';
    return ss.str();
}

int DouList::front() const {
    if (m_head == NULL) {
        return _error_sign;
    } else {
        return m_head->elem;
    }
}

int DouList::back() const {
    if (m_tail == NULL) {
        return _error_sign;
    } else {
        return m_tail->elem;
    }
}

void DouList::push_back(const int &e) {
    DouListNode *new_node = new DouListNode(e, m_tail, NULL);
    if (m_tail == NULL) {
        m_tail = m_head = new_node;
    } else {
        m_tail->next = new_node;
        m_tail = new_node;
    }
}

void DouList::push_front(const int &e) {
    DouListNode *new_node = new DouListNode(e, NULL, m_head);
    if (m_head == NULL) {
        m_tail = m_head = new_node;
    } else {
        m_head->prev = new_node;
        m_head = new_node;
    }
}

void DouList::pop_front() {
    if (m_head == NULL) {
        return;
    } else {
        DouListNode *temp = m_head;
        m_head = m_head->next;
        m_head->prev = NULL;
        delete temp;
    }
}

void DouList::pop_back() {
    if (m_tail == NULL) {
        return;
    } else {
        DouListNode *temp = m_tail;
        m_tail = m_tail->prev;
        m_tail->next = NULL;
        delete temp;
    }
}

void DouList::operator=(const DouList &other) {
    this->clear();
    DouListNode *temp = other.m_head;
    while (temp != NULL) {
        this->push_back(temp->elem);
        temp = temp->next;
    }
}

std::ostream& operator<<(std::ostream &out, const DouList &list) {
    out << list.to_str();
    return out;
}

