#include <cstdio>
#include <memory.h>
#include <iostream>

/**
 * Modified example used by Olve Maudal : Insecure C and C++
 * clang++ -z execstack -fno-stack-protector -o target target.cpp
 */
void launch_missiles(int n) {
  printf("Launching %d missiles\n", n);
}

void authenticate_and_launch() {
  int n_missiles = 2;
  bool allowaccess = false;
  char response[110];

  printf("%p\n", &response);
  printf("Secret: ");
  std::cin >> response;

  if (strcmp(response, "Joshua") == 0)
    allowaccess = true;

  if (allowaccess) {
    puts("Access granted");
    launch_missiles(n_missiles);
  }

  if (!allowaccess)
    puts("Access denied");
}

int main() {
  puts("WarGames MissileLauncher v0.1");
  authenticate_and_launch();
  puts("Operation complete");
}
