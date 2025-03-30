# C Programming exercise

## Array

<details>
<summary>1-1. Initialise an array of `[1, 2, 3, 4]`</summary>

```c
int myArray[4] = { 1, 2, 3, 4}
// Without the size specified, the compiler will still make this array length as 4.
int myArray[] = {1, 2, 3, 4}
```

</details>

<details>
  <summary>1-2. Pointers and arrays.
    
  <summary>

- `&x[0]` is equivalent to `x`.
- `x[0]` is equivalent to `*x`.
- `&x[1]` is equivalent to `x+1`.
- `x[1]` is equivalent to `*(x+1)`.

</details>

## Memory

<details>
<summary>1. Explain how stack and heap memory allocations happen.</summary>

- **Stack:** Memory is allocated automatically for local variables and freed when the function returns.
- **Heap:** Memory is dynamically allocated using malloc() or calloc() and must be manually freed using free().

</details>
<details>
<summary>2-1. Declare a pointer of integer, assign a value, and get the value</summary>

```c
// 3 ways to declare a pointer
int* p;
int *p1;
int * p2;

// assign & get a value
p = 5;
printf("%d", *p)
```

More example:

```c
int main()
{
   int* pc, c;

   c = 22;
   printf("Address of c: %p\n", &c);
   printf("Value of c: %d\n\n", c);  // 22

   pc = &c;
   printf("Address of pointer pc: %p\n", pc);
   printf("Content of pointer pc: %d\n\n", *pc); // 22

   c = 11;
   printf("Address of pointer pc: %p\n", pc);
   printf("Content of pointer pc: %d\n\n", *pc); // 11

   *pc = 2;
   printf("Address of c: %p\n", &c);
   printf("Value of c: %d\n\n", c); // 2
   return 0;
}
```

</details>
