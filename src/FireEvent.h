//
// Created by ChenxiWu on 2022/9/7.
//

#ifndef UNTITLED2_FIREEVENT_H
#define UNTITLED2_FIREEVENT_H
#include <QObject>
#include <thread>
#include <mutex>

class FireEvent : public QObject
{
Q_OBJECT

public:
    ~FireEvent() override = default;
    void fire();
    void reset();
private:
    void fireDoing(std::mutex& mutex, int k);

private:
    std::mutex m_mutex1, m_mutex2, m_mutex3;

signals:
    void valueChange1(int num);
    void valueChange2(int num);
    void valueChange3(int num);


};


#endif //UNTITLED2_FIREEVENT_H
