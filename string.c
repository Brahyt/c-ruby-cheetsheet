#include <stdio.h>
#include <string.h>

void string_details();
void array_details();

int main() {
  string_details();
  array_details();
}

void string_details() {
  printf("Strings\n");

  char * name = "Luke Skywalker"; // String that cannot be changed
  //strcat(name, " Nope");        // This will cause Seg fault
  printf("%s\n", name);

  char other_name[10] = "Old";
  strncat(other_name, " Ben", 5); // destination, src, length
  printf("%s\n", other_name);

  // Compare strings
  printf("%d", strncmp(name, "Lando", 4)); // if same, will return 0
}

void array_details() {
  printf("Arrays\n");

  int num_array[] = { 1, 2, 3, 4, 5 };
  printf("Byte Size of array is %lu\n", sizeof(num_array)); // This is size in bytes
  size_t elements = sizeof num_array / sizeof num_array[0];
  printf("Number of elements in array is %lu\n", elements);

  printf("Count the array: ");
  for (int i = 0; i < elements; i++) {
    printf("%d", num_array[i]);
  }
}
