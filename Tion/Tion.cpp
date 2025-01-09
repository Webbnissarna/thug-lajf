
#include "Engine.h"
#include "Logger.h"

int main() {
	Engine engine = Engine();
	if (!engine.setup()) {
		Logger::error("Something went shit\n");
		return -1;
	}
	
	if (!engine.run()) {
		Logger::error("Something went shit");
	}

	engine.cleanup();
	Logger::success("Exited gracefully");
	
	return 0;
}