class ParkingSystem {
public:
    unordered_map<int,pair<int, int>> car;
    ParkingSystem(int big, int medium, int small) {
        car[1] = {0, big}; //big car
        car[2] = {0, medium}; //medium car
        car[3] = {0, small}; //small car
    }
    
    bool addCar(int carType) {
        if(car[carType].first == car[carType].second)
            return false;
        car[carType].first += 1; //park this car
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */