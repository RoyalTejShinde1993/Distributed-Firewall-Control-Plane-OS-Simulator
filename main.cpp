
#include "core/control_plane.hpp"

int main() {
    fwos::ControlPlane cp;
    cp.initialize();
    cp.run();
}
