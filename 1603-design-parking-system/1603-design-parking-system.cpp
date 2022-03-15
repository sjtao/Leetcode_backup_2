class ParkingSystem {
public:
    unordered_map<int, int> car;
    ParkingSystem(int big, int medium, int small) {
        car[1] = big; //big car
        car[2] = medium; //medium car
        car[3] = small; //small car
    }
    
    bool addCar(int carType) {
        if(car[carType] <= 0)
            return false;
        car[carType]-= 1; //park this car
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */