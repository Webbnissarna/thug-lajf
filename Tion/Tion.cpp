
#include "Engine.h"
#include "Logger.h"

int main() {
	Engine engine = Engine();
	if (!engine.setup()) {
		Logger::Error("Something went shit\n");
		return -1;
	}
	
	if (!engine.run()) {
		Logger::Error("Something went shit");
	}

	engine.cleanup();
	Logger::Success("Exited gracefully");
	
	return 0;
}