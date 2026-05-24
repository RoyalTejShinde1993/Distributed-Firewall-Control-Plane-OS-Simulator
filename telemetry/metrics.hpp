
#pragma once

namespace fwos {

class Metrics {

private:
    int allowed = 0;
    int denied = 0;

public:
    void recordPacket(bool verdict);
    void printSummary();
};

}
