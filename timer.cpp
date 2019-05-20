#include <chrono>

struct Timer{
    chrono::system_clock::time_point start_t;
    void start(){
        start_t = chrono::system_clock::now();
    }
    double now(){
        chrono::system_clock::time_point now_t = chrono::system_clock::now();
        return chrono::duration_cast<std::chrono::milliseconds>(now_t - start_t).count() / 1000.0;
    }
}