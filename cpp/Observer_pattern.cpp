#include<iostream>
#include<string>
#include<vector>
#include<windows.h>
using namespace std;

// --------------------------------------------Weather Dataclass ------------------------------------
typedef struct WeatherData{
    float tempertature;
    float humidity;
    float pressure;
    WeatherData(float temperature,float humidity,float pressure){
        this->tempertature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
    }
    WeatherData(){
        this->tempertature = 0;
        this->pressure = 0;
        this->humidity = 0;
    }
} WeatherData;

// --------------------------------------------Observer Interface------------------------------------
/*  Observer Interface
    This is the interface for all the observers
    All the observers must implement this interface
*/
class Observer{
public:
    ~Observer(){};
    virtual void update(WeatherData* data)=0;
};

// ---------------------------------------------Subject Interface------------------------------------
/*  Subject Interface
    This is the interface for all the subjects
    All the subjects must implement this interface
*/
class Subject{
public:
    ~Subject(){};
    virtual void registerObserver(Observer* o){};
    virtual void removeObserver(Observer* o){};
    virtual void notifyObserver()=0;
};


// ------------------------------------------Weather Monitor class-----------------------------------
/* Weather Monitor
    This is the concrete subject class
    This class implements the Subject interface
    This class is responsible for registering,removing and notifying the observers
*/
class WeatherMointor:public Subject{
private:
    vector<Observer*> observers;
    WeatherData* data;
public:
    WeatherMointor(){
        data = new WeatherData();
    }
    void registerObserver(Observer* o) {
        observers.push_back(o);
    }
    void removeObserver(Observer* o) {
        
        for( auto it = observers.begin();it!=observers.end();it++){
            if(*it == o){
                observers.erase(it);
                break;
            }
        }
    }
    void notifyObserver() override{
        for ( auto it :observers){
            it->update(data);
        }
    }
    void dataUpdated(){
        notifyObserver();
    }
    void setData(float temperature,float humidity,float pressure){
        data->humidity=humidity;
        data->pressure = pressure;
        data->tempertature = temperature;
        dataUpdated();
    }
};

// --------------------------------------------Concrete Observer Class---------------------------------
/* Current Weather Display
    This is the concrete observer class
    This class implements the Observer interface
    This class is responsible for displaying the current weather data
*/
class CurrentWeatherDisplay:public Observer{
private:
    WeatherData* data;
public:
    CurrentWeatherDisplay(){}

    void update(WeatherData* data) override{
        this->data = data;
        display();
    }

    void display(){
        cout<<"Current Weather Data"<<endl;
        cout<<"Temperature: "<<data->tempertature<<endl;
        cout<<"Humidity: "<<data->humidity<<endl;
        cout<<"Pressure: "<<data->pressure<<endl;
    }

};

// --------------------------------------------Concrete Observer Class---------------------------------
class ForecastWeatherDisplay:public Observer{
private:
    WeatherData* data;
public:
    ForecastWeatherDisplay(){}

    void update(WeatherData* data) override{
        this->data = data;
        display();
    }

    void display(){
        cout<<"Forecast Weather Data"<<endl;
        cout<<"Temperature: "<<data->tempertature<<endl;
        cout<<"Humidity: "<<data->humidity<<endl;
        cout<<"Pressure: "<<data->pressure<<endl;
    }

};

// --------------------------------------------Main Function-------------------------------------------
int main(){
    WeatherMointor* weatherReporter = new WeatherMointor();
    CurrentWeatherDisplay* currentWeatherDisplay = new CurrentWeatherDisplay();
    ForecastWeatherDisplay* forecastWeatherDisplay = new ForecastWeatherDisplay();

    // Register the observer
    weatherReporter->registerObserver(currentWeatherDisplay);

    weatherReporter->setData(10,20,30);
    weatherReporter->registerObserver(forecastWeatherDisplay);
    Sleep(5000); // Sleep for 5 seconds
    weatherReporter->setData(20,30,40);

    weatherReporter->removeObserver(currentWeatherDisplay);

    Sleep(5000); // Sleep for 5 seconds
    weatherReporter->setData(30,40,50);
    return 0;
}