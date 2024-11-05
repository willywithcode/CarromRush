#pragma once
#include <cstddef>
#include <memory>

namespace BanZ {
    template<class T>
    class SingletonTemplate {
    public:
        static T* getInstance() {
            if (!instance) {
                instance = new T;
            }
            return instance;
        }
    protected:
        static T* instance;

        SingletonTemplate() {
        };

        SingletonTemplate(const SingletonTemplate&) {
        };

        SingletonTemplate& operator=(const SingletonTemplate&) {
        };

    };
    template<typename T>
    T* SingletonTemplate<T>::instance = nullptr;
}