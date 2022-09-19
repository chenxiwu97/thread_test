//
// Created by ChenxiWu on 2022/9/7.
//

#include "FireEvent.h"

void FireEvent::fire() {
    if (m_mutex1.try_lock()) {
//        fireDoing(m_mutex1, &FireEvent::valueChange1);
        std::thread thread(&FireEvent::fireDoing, this, std::ref(m_mutex1), 1);
        thread.detach();
    }
    else if (m_mutex2.try_lock()) {
        std::thread thread(&FireEvent::fireDoing, this, std::ref(m_mutex2), 2);
        thread.detach();
    }
    else if (m_mutex3.try_lock()) {
        std::thread thread(&FireEvent::fireDoing, this, std::ref(m_mutex3), 3);
        thread.detach();
    }
}

void FireEvent::fireDoing(std::mutex& mutex, int k) {
    for (int j = 0; j <= 100; ++j) {
        for (int i = 0; i < 30000000; ++i) {
            bool flag = true;
        }
        switch (k) {
            case 1:
                emit valueChange1(j);
                break;
            case 2:
                emit valueChange2(j);
                break;
            case 3:
                emit valueChange3(j);
        }

    }
    mutex.unlock();
}

void FireEvent::reset() {
    if (m_mutex1.try_lock()) {
        emit valueChange1(0);
        m_mutex1.unlock();
    }
    if (m_mutex2.try_lock()) {
        emit valueChange2(0);
        m_mutex2.unlock();
    }
    if (m_mutex3.try_lock()) {
        emit valueChange3(0);
        m_mutex3.unlock();
    }
}