#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_details();
void array_details();
void pointer_details();
void hash_map();
void malloc_memory_managment();
void calloc_memory_managment();

int main() {
 // string_details();
 // array_details();
 // pointer_details();
 // malloc_memory_managment();
 calloc_memory_managment();
 // hash_map();
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

void pointer_details() {
  printf("\n");
  int a = 1;

  int * pointer_to_a = &a;
  printf("%p\n", pointer_to_a);

  // Can even change the var

  *pointer_to_a += 1;

  printf("1 + 1 = %d\n", a);
}

void hash_map() {
}

void malloc_memory_managment() {
  // malloc()  - memory allocation
  // calloc()  - contigious memory allocation
  // realloc() - re-allocate
  // free()    - used to free allocated memory

  int n, *ptr, sum = 0;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  printf("Byte Size of ptr is %lu\n", sizeof(ptr));

  ptr = (int*) malloc(n * sizeof(int));

  // if memory cannot be allocated
  if(ptr == NULL) {
    printf("Error! memory not allocated.");
    exit(0);
  }

  printf("Enter elements\n");
  for(int i = 0; i < n; ++i) {
    printf("You num will be stored at %p: ", ptr + i); // Each number is loaded into memory and added to sum
    scanf("%d", ptr + i);
    sum += *(ptr + i);
  }

  printf("Sum = %d\n", sum);

  // deallocating the memory
  free(ptr);
}

void calloc_memory_managment() {
  int n, i, *ptr, sum = 0;
  printf("Enter number of elements: ");
  scanf("%d", &n);

  ptr = (int*) calloc(n, sizeof(int));

  if(ptr == NULL) {
    printf("Error! memory not allocated.");
    exit(0);
  }

  printf("Enter elements\n");
  for(i = 0; i < n; ++i) {
    printf("You num will be stored at %p: ", ptr + i); // Each number is loaded into memory and added to sum
    scanf("%d", ptr + i);
    sum += *(ptr + i);
  }

  printf("Sum = %d", sum);
  free(ptr);
}
