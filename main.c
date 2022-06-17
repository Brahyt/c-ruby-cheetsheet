#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_details();
void array_details();
void pointer_details();
void hash_map();
void malloc_memory_managment();
void calloc_memory_managment();
void memory_managment();
void var_passing();

int main() {
  /* string_details(); */
  /* array_details(); */
  /* pointer_details(); */
  /* memory_managment(); */
  /* malloc_memory_managment(); */
  /* calloc_memory_managment(); */
  var_passing();
  /* hash_map(); // TODO */
}

void string_details() {
  printf("Strings\n");

  char* name = "Luke Skywalker"; // String that cannot be changed
  //strcat(name, " Nope");        // This will cause Seg fault
  printf("%s\n", name);

  char other_name[10] = "Old";
  strncat(other_name, " Ben", 5); // destination, src, length
  printf("%s\n", other_name);     // This is memory safe

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

  int* pointer_to_a = &a;
  printf("%p\n", pointer_to_a);

  *pointer_to_a += 1;

  printf("1 + 1 = %d\n", a);
}

void hash_map() {
}

void memory_managment() {
  // malloc wont use memory at hardware level until its used.
  // your operating system will let malloc allocate memory
  // in a plan to use it later, but can ultimatly do what it wants
  // with that memory.

  #define ONEGB (1 << 30) // bitwise leftshift operator

  /* int* *p = (int*) malloc(ONEGB); */
  int n;

  while (1) {
    int *p = malloc(ONEGB);

    scanf("%d", &n);

    if (n == 0) {
      printf("FREE SPACE!\n");
      void free(void *p);
    } else {
      printf("Allocating more space\n");
      memset(p, 1, ONEGB); // Fill up the reserved space with 1s
    }
  }
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

int multiply_by_2(int i){            // Memory allocated on the stack automatic.
  printf("i*2 pointer: %p\n", &i);   // var i is copied into stack then released
  return i *= 2;                     // after out of scope
}

int multiply_by_4(int* i){           // Instead of copying the value of var i this
  printf("i*4 pointer: %p\n", i);    // this will refrence the var at the address'
  return *i *= 4;                    // it was passed. (int* i)
}

void var_passing(){
  int i = 2;

  int x = multiply_by_2(i);      // 2 * 2 = 4
  printf("%d * 2 = %d\n", i, x); // i == 2
                                 // the original value of `i` doesn''t change

  int y = multiply_by_4(&i);        // 2 * 4 = 8
  printf("%d * 4 = %d\n", i , y);   // this is wrong becuase i was changed
}
