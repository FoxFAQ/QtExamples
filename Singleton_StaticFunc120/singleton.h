#ifndef SINGLETON_H
#define SINGLETON_H

#include <assert.h>

template <class T>
class Singleton
{
public:
    static T* Instance()
    {
        if(!instance_) instance_ = new T;
        assert(instance_ != nullptr);
        return instance_;
    }

protected:
    Singleton();
    ~Singleton();
private:
    Singleton(Singleton const&);
    Singleton& operator=(Singleton const&);
    static T* instance_;
};

template <class T> T* Singleton<T>::instance_ = nullptr;

#endif // SINGLETON_H
