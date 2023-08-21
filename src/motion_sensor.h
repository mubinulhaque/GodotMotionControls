#ifndef MOTION_SENSOR_H
#define MOTION_SENSOR_H

#include <godot_cpp/classes/node.hpp>

namespace godot {

class MotionSensor : public Node {
    GDCLASS(MotionSensor, Node)

    public:
        MotionSensor();
        ~MotionSensor();
    
    protected:
        static void _bind_methods();
};

}

#endif //MOTION_SENSOR_H