//
// Created by User on 2/8/2024.
//

#ifndef CHAPTER1_SMARTPOINTER_H
#define CHAPTER1_SMARTPOINTER_H

template<typename T>
class SmartPointer {
    T* m_ptr;

    SmartPointer(const SmartPointer &) = delete;

    SmartPointer &operator=(const SmartPointer &);

public:

     explicit SmartPointer(T* p = 0) : m_ptr(p) {}

    ~SmartPointer() { delete m_ptr; }

    T *operator->() const { return m_ptr; }
    T &operator*() const { return *m_ptr; }

};


#endif //CHAPTER1_SMARTPOINTER_H
