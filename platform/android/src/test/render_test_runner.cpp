#include "runtime.hpp"
#include <mbgl/render_test_runner.hpp>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (!mbgl::android::initRuntime(argc, argv)) {
        return 1;
    }
  
    for(int i=1; i<argc; ++i) {
        const std::string arg{argv[i]};
        std::string kClassPathCommand("--class_path=");
            //And remove this item from the list
        if (arg.compare(0, std::string("--class_path=").length(), kClassPathCommand) == 0) {
            argv[i][0] = 0;   //Transform it in an empty string, putting null as first character
        }
    }
    

    return mbgl::runRenderTests(argc, argv);
}
