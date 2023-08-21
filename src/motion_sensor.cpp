#include "motion_sensor.h"
#include <godot_cpp/core/class_db.hpp>
#include <SDL2/SDL.h>

using namespace godot;

MotionSensor::MotionSensor() {
    SDL_Init(SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER | SDL_INIT_SENSOR);
}

MotionSensor::~MotionSensor() {
    SDL_Quit();
}

void MotionSensor::_bind_methods() {
    ClassDB::bind_method(D_METHOD("has_sensor", "controller_index"), MotionSensor::has_sensor);
}

String MotionSensor::has_sensor(const int controller_index) {
    SDL_JoystickEventState(SDL_ENABLE);

    SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI_PS4_RUMBLE, "1");
    SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI_PS5, "1");

    // Initializing the controller
    SDL_GameController* controller = SDL_GameControllerOpen(controller_index);

    SDL_GameControllerSetSensorEnabled(controller, SDL_SENSOR_ACCEL, SDL_TRUE);
    SDL_GameControllerSetSensorEnabled(controller, SDL_SENSOR_GYRO, SDL_TRUE);

    // Polling the controller
    if(SDL_GameControllerHasSensor(controller, SDL_SENSOR_GYRO)) {
        return "The first controller has a gyroscope"; //SDL_GameControllerName(controller); 
    } else {
        return "The first controller does not have a gyroscope"; //SDL_GameControllerName(controller);
    }
    
    SDL_GameControllerClose(controller);
}