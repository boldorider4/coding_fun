#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv)
{
  pid_t id = fork();

  if (id == 0) {
    // child process
    printf("enter child process\n");
    execl("./child", "child", NULL);
    printf("exit child process\n");

  } else {
    printf("parent process\n");
  }

  printf("bla\n");
  /*
  if (id >= 0)
  {
      if (id == 0)
      {
          printf("foo1\n");
      }
      else
      {
          execl("./child", "child", NULL);
      }
  }
  else
  {
      printf("fork failed!\n");
  }

  printf("foo3\n");
  */
}
