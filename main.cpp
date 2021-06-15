//
// Created by alfio on 08/06/2021.
//

#include "Vehicles.hpp"

using namespace std;

int main() {
    unsigned int N, horsePower, mass;
    short type;
    std::string brand;

    do {
        cout << "Insert the number of Vehicle you want to create: ";
        cin >> N;
    } while (N < 0);
    Queue<Car> queueCar(N);
    Queue<MotorCycle> queueMotorCycle(N);
    Queue<Boat> queueBoat(N);

    for (int i = 0; i < N; i++) {
        do {
            cout << "Choose a type (1 = Car, 2 = Motorcycle, 3 = Boat): ";
            cin >> type;
        } while (type != 1 && type != 2 && type != 3);
        cout << "Insert brand: ";
        cin >> brand;
        cout << "Insert horsePower: ";
        cin >> horsePower;
        cout << "Insert mass: ";
        cin >> mass;

        if (type == 1) {
            Car element{brand, horsePower, mass};
            queueCar.enQueue(element);
        } else if (type == 2) {
            MotorCycle element{brand, horsePower, mass};
            queueMotorCycle.enQueue(element);
        } else {
            Boat element{brand, horsePower, mass};
            queueBoat.enQueue(element);
        }

    }

    cout << queueBoat << endl;
    cout << queueMotorCycle << endl;
    cout << queueCar << endl;
}
