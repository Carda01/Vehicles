//
// Created by alfio on 08/06/2021.
//

#ifndef PROG_II_VEHICLES_HPP
#define PROG_II_VEHICLES_HPP

#include "Vehicles.h"
#include<stdexcept>

#define horseToWatt 746


Vehicle::Vehicle(std::string _brand, unsigned int _horsePower, unsigned int _mass,
                 double _acceleration = 0,
                 double _speed = 0) : brand(_brand), horsePower(_horsePower), mass(_mass), acceleration(_acceleration),
                                      speed(_speed) {}

void Vehicle::accelerate() { acceleration++; }

void Vehicle::init(std::string _brand, unsigned int _horsePower, unsigned int _mass) {
    brand = _brand;
    horsePower = _horsePower;
    mass = _mass;

}

void Vehicle::decelerate() { acceleration--; }

void Vehicle::updateSpeed() { speed = horsePower * horseToWatt / (mass * acceleration); }

std::ostream &operator<<(std::ostream &out, const Vehicle &vehicle) {
    out << "Brand: " << vehicle.brand << std::endl;
    out << "HorsePower: " << vehicle.horsePower << std::endl;
    out << "Mass: " << vehicle.mass << std::endl;
    out << "CurrentSpeed : " << vehicle.speed << std::endl;
    return out;
}

Car::Car(std::string _brand = "def", unsigned int _horsePower = 0, unsigned int _mass = 0) : Vehicle(_brand,
                                                                                                     _horsePower,
                                                                                                     _mass) {}

MotorCycle::MotorCycle(std::string _brand = "def", unsigned int _horsePower = 0, unsigned int _mass = 0) : Vehicle(
        _brand, _horsePower,
        _mass) {}

Boat::Boat(std::string _brand = "def", unsigned int _horsePower = 0, unsigned int _mass = 0) : Vehicle(_brand,
                                                                                                       _horsePower,
                                                                                                       _mass) {}
std::ostream & operator<<(std::ostream & out, const Boat & boat){
    out<<"Type: Boat"<<std::endl;
    return out;
}

template<class T>
Queue<T>::Queue(size_t _size) : size(_size) {
    arr = new T[size];
    head = 0;
    tail = -1;
    count = 0;
}

template<class T>
Queue<T>::~Queue() { delete[] arr; }

template<class T>
void Queue<T>::enQueue(const T &element) {
    if (isFull())
        throw std::overflow_error("Queue is full");
    else {
        tail++;
        count++;
        circular(tail);
        arr[tail] = element;
    }
}

template<class T>
T Queue<T>::deQueue() {
    if (isEmpty())
        throw std::underflow_error("Queue is empty");
    else {
        T element = arr[head];
        head++;
        count--;
        circular(head);
        return element;
    }
}

template<class T>
bool Queue<T>::isEmpty() const { return count == 0; }

template<class T>
bool Queue<T>::isFull() const { return count == size; }

template<class T>
void Queue<T>::circular(int &index) {
    index = index % size;
}

template<class U>
std::ostream &operator<<(std::ostream &out, const Queue<U> &queue) {
    for (int i = queue.head; i <= queue.tail; i++) {
        i = i % queue.size;
        out << queue.arr[i] << ' ';
    }
    out << std::endl;
    return out;
}


#endif //PROG_II_VEHICLES_HPP
