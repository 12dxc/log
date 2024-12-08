#include "log.hpp"

using namespace std;

int main()
{
    setLevel(level::debug);

    debug("hello{}", 123);
    info("hello{}", 123);
    warn("hello{}", 123);
    error("hello{}", 123);
}