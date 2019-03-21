#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <iostream>
#include "gtest/gtest.h"

template <typename T>
class SharedPtr
{
  public:
    explicit SharedPtr(T *ptr);
    ~SharedPtr();
    SharedPtr(SharedPtr const &);
    SharedPtr &operator=(SharedPtr const &);

    T *operator->() const;
    T &operator*() const;
    operator bool() const;
    SharedPtr &operator=(T *ptr); // this no need except sp =NULL

    T *get() const; // Using a function.
    size_t getCountInstance();

  private:
    T *m_ptr;
    size_t *m_count;
};

template <typename T>
size_t SharedPtr<T>::getCountInstance()
{
    return *m_count;
}

template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr const &sp)
{
    m_ptr = sp.m_ptr;
    m_count = sp.m_count;
    ++(*m_count);
}

template <typename T>
template <typename U>
SharedPtr<T> &SharedPtr<T>::operator=(U *ptr)
{
    if (m_ptr != ptr)
    {
        delete m_ptr;
        delete m_count;
        m_count = new size_t(1);
        m_ptr = ptr;
    }
    return *this;
}

template <typename T>
SharedPtr<T> &SharedPtr<T>::operator=(SharedPtr const &ptr)
{
    if (1 == *m_count)
    { // 1== ..  better from 1 == ..
        delete m_ptr;
        delete m_count;
    }
    --(*m_count);
    m_ptr = ptr.m_ptr;
    m_count = ptr.m_count;
    ++(*m_count);
    return *this;
}

template <typename T>
SharedPtr<T>::SharedPtr(T *ptr) try : m_ptr(ptr), m_count(new size_t(1))
{
    // why do I need to throw exception?
    // Because there isn't enough memory to allocate to m_count so, delete ptr that already it created in main.cpp
}
catch (std::bad_alloc &ex)
{
    delete ptr;
    throw;
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
    if (1 == *m_count)
    {
        delete m_ptr;
        delete m_count;
    }
    else
    {
        --(*m_count);
    }
}
template <typename T>
T *SharedPtr<T>::operator->() const { return m_ptr; }

template <typename T>
T &SharedPtr<T>::operator*() const { return *m_ptr; }

template <typename T>
SharedPtr<T>::operator bool() const
{
    return (bool)m_ptr;
}

template <typename T>
T *SharedPtr<T>::get() const { return m_ptr; }

#endif