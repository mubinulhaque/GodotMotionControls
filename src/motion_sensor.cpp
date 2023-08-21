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
}