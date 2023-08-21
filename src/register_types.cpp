#include "register_types.h"
#include "motion_sensor.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

static const ModuleInitializationLevel min_init_level = MODULE_INITIALIZATION_LEVEL_SCENE;

void initialize_gdextension_types(ModuleInitializationLevel p_level) {
	if (p_level != min_init_level) {
		return;
	}

	ClassDB::register_class<MotionSensor>();
}

void uninitialize_gdextension_types(ModuleInitializationLevel p_level) {
	if (p_level != min_init_level) {
		return;
	}
}

extern "C" {
	// Initialization
	GDExtensionBool GDE_EXPORT motion_controls_init(
			GDExtensionInterfaceGetProcAddress p_get_proc_address,
			GDExtensionClassLibraryPtr p_library,
			GDExtensionInitialization *r_initialization) {
		GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
		init_obj.register_initializer(initialize_gdextension_types);
		init_obj.register_terminator(uninitialize_gdextension_types);
		init_obj.set_minimum_library_initialization_level(min_init_level);

		return init_obj.init();
	}
}