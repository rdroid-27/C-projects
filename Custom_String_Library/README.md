# Custom String Library in C

This project implements a custom string manipulation library in C, covering basic to advanced string handling functions without relying on the C standard library's `string.h` functions.

## 📁 Files

* `main.c` - Test driver to verify all functions
* `myString.h` - Header file with function declarations
* `myString.c` - Contains all function definitions
* [`FUNCTIONS.md`](./FUNCTIONS.md) - Full function reference and documentation

## 🛠️ Build Instructions

Use `gcc` to compile the project:

```bash
gcc main.c myString.c -o string_test
./string_test
```

Make sure `myString.c` implements all the functions declared in `myString.h`.

## 📚 Implemented Functions

See the full list and descriptions in [FUNCTIONS.md](./FUNCTIONS.md).


## ✅ Testing

All functions are tested in `main.c` using a range of inputs including edge and tricky cases. You can add more test cases to verify behavior.

---

Feel free to expand this library with additional utilities or port it into embedded environments without libc support.
