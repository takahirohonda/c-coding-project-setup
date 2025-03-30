# C Coding Exercise

## 1. Array

<h3>1-1. Create an array from user input</h3>
<details>
  <summary>
    Write a program that takes 5 values from the user and store them in an array. Then print them out.
  </summary>

```c
#include <stdio.h>
int main() {
  int values[5];
  printf("Enter 5 numbers:\n");
  for(int i = 0; i < 5; ++i) {
    // Storing input value to the memory address (in stack)
    // by using the address-of operator (&)
    scanf("%d", &values[i]);
  }
  printf("You entered:\n");
  for(int i = 0; i < 5; ++i) {
    printf("%d\n", values[i]);
  }
}
```

</details>

<h3>1-2. Print out pinter addresses of array and its elements</h3>
<details>
  <summary>
  Create an integer array with a length of 4 and print out an address for each element as well as the array itself.
  </summary>

```c
int main(){
  int array[4];

  for(int i = 0; i < 4; ++i) {
    printf("&x[%d] = %p\n", i, &array[i]);
  }

  // array is the same as &array
  printf("Address of the array (&x): %p\n", array);
}
```

**output**
The address of the array is the same as the first element of the array. Note that there are 4 bytes between two consecutive elements of the array.

```bash
&x[0] = 0x16d1ab238
&x[1] = 0x16d1ab23c
&x[2] = 0x16d1ab240
&x[3] = 0x16d1ab244
Address of the array (&x): 0x16d1ab238
```

</details>

## 2. File IO

`fopen()` opens the file and return a point to a `FILE` stream. It doesn't load the entire file into memory. Instead, it keeps an internal buffer and reads data on demand.

```c
#include <stdio.h>

int main() {
    FILE *file = fopen("data.txt", "r");  // File is NOT loaded into memory yet
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char buffer[100];  // Buffer in stack
    while (fgets(buffer, sizeof(buffer), file)) {  // Reads line-by-line
        printf("%s", buffer);  // Only small parts are loaded at a time
    }

    fclose(file);
    return 0;
}
```

`fget()`

- It reaches a newline (\n).
- It reaches the buffer size limit.
- It reaches the end of the file (EOF).
