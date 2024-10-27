#include "log.hpp"

using namespace std;

int main()
{
    for (int i = 0; i != 100; ++i)
    {
        LOG_DEBUG << "log " << i << ENDL;
        LOG_INFO << "log " << i << ENDL;
        LOG_WARN << "log " << i << ENDL;
        LOG_ERROR << "log " << i << ENDL;
    }
}