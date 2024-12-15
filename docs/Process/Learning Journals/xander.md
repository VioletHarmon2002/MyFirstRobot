# **Learning Journal |** Xander Tamis

## Learning Story [#122]: C++ Header Files and their benefits and drawbacks

To avoid having one large bloated main file with every function in it, we want to use header files to contain the separate functions. But what exactly are header files, what benefits and drawbacks do they have and what are their use cases?

### Header files

Header files allow developers to put their declarations in one place and then import them wherever necessary.

They usually have a <code>.h</code> extension, but there are also header files with a <code>.hpp</code> extension or no extension at all.

The content of a header file is inserted at the point of inclusion. That means that if a function calls on data from a header file before the header file is inserted, then the function won't be able to access the data.

If you use a function multiple times across several files, then any change would require you to go through all those files and change the function everywhere. 

By using a function file to contain the function in combination with a header file to contain the declarations, you can simply include these two files in every file that you want to access the function and then you only need to change these two files to have it change everywhere.

### Example

If you have a function <code> add() </code> that you want to access in multiple files, you could create a function and header file for it.

The header file: <code>add.h</code> would look like this:

```
int add(int x, int y);
```

The function file: <code>add.cpp</code> could look something like this:

```
#include "add.h"

int add(int x, int y) {
    return x + y;
}
```

And then in <code>main.cpp</code> you can have it as follows:

```
#include "add.h"
#include <iostream>

int main() {
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}
```

Without a header file, you would have to include the declaration for the function file in every file where you'd wnat to use the function like in the code example below:

```
int add(int x, int y);

int main() {
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}
```

This is not a big deal when you only have a few declarations, but can get annoying quickly when dealing with a lot of declarations that need to be written down in every file.

### Upsides

- Code Organization:
Header files help separate interface from implementation, making code easier to manage.

- Reusability:
Once written, a header file can be included in multiple source files.

- Ease of Collaboration:
In larger projects, header files allow team members to work independently on different parts of the program by clearly defining the interface between modules.

### Downsides

- Increased Compilation Time:
If headers are large or include other headers, it can lead to longer compilation times due to repeated processing of the same headers for each source file.

- Easier to create circular dependencies: Poorly designed header files can lead to circular dependencies, leading to compilation errors.

- Overuse: Using too many headers can lead to unnecessarily complex codebases. 

### Sources

https://www.learncpp.com/cpp-tutorial/header-files/