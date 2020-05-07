#include "../list.h"
#include <stdio.h>

void assert_equal(Status actual, Status expected, char *message)
{
  if (actual == expected)
  {
    printf("✔ %s", message);
  }
  else
  {
    printf("✗ %s", message);
  }
}

void run_tests()
{
  printf("running tests ....\n\n");

  List_ptr list = create_list();
  assert_equal(add_to_end(list, 10), Success, "Should insert element at end");
}

int main()
{
  run_tests();
}