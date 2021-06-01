#include "rk_application.h"

int main(int argc, char **argv)
{
  auto app = rk_application::create();
  app->run(argc, argv);
  return 0;
}

