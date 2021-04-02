
#include <Game.h>
#include <chrono>
#include <iostream>
int main(const int argc, const char** argv)
{
    std::srand(time(NULL));
    Game().Run();
    return 0;
}
