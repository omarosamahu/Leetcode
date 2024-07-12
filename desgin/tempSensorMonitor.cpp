#include <iostream>

class Sensor{
public:
    virtual ~Sensor(){}
    virtual void connect() = 0;
};

class TempSensor : public Sensor {
public:
    TempSensor() = default;
    ~TempSensor();

    // Copy Constructor
    TempSensor(const TempSensor&) = delete;
    // Copy operator
    TempSensor& operator=(const TempSensor&) = delete;
    // Move Constructor
    TempSensor(TempSensor&&) = delete;
    // Move operator
    TempSensor& operator=(TempSensor&&) = delete;
    
    void connect() override{
        // Connect with the driver
    }

    void update(){
        // update temperature
    }

    float getTemparture() const{
        return temp;
    }
private:
    float temp;
};


class Monitor{
public:
    Monitor() = default;
    ~Monitor();

private:

};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
