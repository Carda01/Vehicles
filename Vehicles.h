//
// Created by alfio on 08/06/2021.
//

#ifndef PROG_II_VEHICLES_H
#define PROG_II_VEHICLES_H

#include<iostream>
#include<cstring>
#include<sstream>

class Vehicle {
public:
    std::string brand;
    unsigned int horsePower, mass;
    double acceleration, speed;

    Vehicle(std::string, unsigned int, unsigned int, double, double);

    void init(std::string, unsigned int, unsigned int);

    void accelerate();

    void decelerate();

    void updateSpeed();

    std::stringstream charger() const;

    friend std::ostream &operator<<(std::ostream &, const Vehicle &);

private:
    virtual std::string charge() const;
};

class Car : public Vehicle {
public:
    explicit Car(std::string = "def", unsigned int = 0, unsigned int = 0);

private:
    std::string charge() const override;
};

class MotorCycle : public Vehicle {
public:
    explicit MotorCycle(std::string = "def", unsigned int = 0, unsigned int = 0);

private:
    std::string charge() const override;
};

class Boat : public Vehicle {
public:
    explicit Boat(std::string = "def", unsigned int = 0, unsigned int = 0);

private:
    std::string charge() const override;
};

template<class T>
class Queue {
public:
    explicit Queue(size_t);

    ~Queue();

    void enQueue(const T &);

    T deQueue();

    bool isEmpty() const;

    bool isFull() const;

    template<class U>
    friend std::ostream &operator<<(std::ostream &, const Queue<U> &);

private:
    void circular(int &index);

private:
    T *arr;
    size_t size;
    int head, tail, count;
};

template<class T>
class Node {
public:
    T element;
    Node<T> *left, *right, *father;
};

template<class T>
class BST {
public:
    BST();

private:
    Node<T> *root;
};

#endif //PROG_II_VEHICLES_H
