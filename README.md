# CVec: Vector Library in C

CVec is a simple C library for working with dynamic arrays, providing functionality similar to vectors in other programming languages. It allows you to create, manipulate, and free dynamic arrays efficiently.

## Functions

- `new_cvec`: Create a new CVec with an initial capacity.
- `cvec_from`: Create a new CVec from an existing array.
- `cvec_free`: Free memory allocated for a CVec.
- `cvec_push`: Append an element to the end of the CVec.
- `cvec_pop`: Remove and return the last element of the CVec.
- `cvec_resize`: Resize the capacity of the CVec.
- `cvec_remove`: Remove an element from the CVec at a specified index.
- `cvec_insert`: Insert an element at a specified index in the CVec.
- `cvec_clean`: Remove all elements from the CVec.
- `cvec_front`: Get the first element of the CVec.
- `cvec_back`: Get the last element of the CVec.
- `cvec_at`: Get the element at a specified index in the CVec.
- `cvec_iter`: Iterator for traversing the elements of the CVec.

## Installation

- **Create a build directory**: `mkdir build && cd build`
- **Build from source**: `cmake .. && make`
- **Install all the files**: `sudo make install`

## Usage

- **Include the Header File**: Include `cvec.h` in your C source file.
- **Compile with Your Project**: Compile your project with -lcvec.
- **Use the Functions**: Start using the CVec functions in your code.

## CMake Usage

- **Link the library**: `target_link_libraries(ExecName PRIVATE cvec)`

## Example

```c
#include <stdio.h>
#include <cvec.h>

int main() {
    // Create a new CVec
    cvec* vec = new_cvec();
    // cvec_from(3, 10, 20, 30) - first argument is number of the elements

    // Push elements into the CVec
    cvec_push(vec, 10);
    cvec_push(vec, 20);
    cvec_push(vec, 30);

    // Print elements
    for (int i = 0; i < vec->size; i++) {
        printf("%d ", cvec_iter(vec));
        // or vec->items[i]
    }

    // Free memory
    cvec_free(vec);

    return 0;
}
```

## License
This project is licensed under the MIT License