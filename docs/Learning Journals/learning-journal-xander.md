# **Learning Journal |** Xander Tamis

## Learning Story [#122]: C++ Header Files and their benefits and drawbacks

To avoid having one large bloated main file with every function in it, we want to use header files to contain the separate functions. But what exactly are header files, what benefits and drawbacks do they have and what are their use cases?

### Header files

Header files allow developers to put their declarations in one place and then import them wherever necessary.

They usually have a <code>.h</code> extension, but there are also header files with a <code>.hpp</code> extension or no extension at all.

The content of a header file is inserted at the point of inclusion. That means that if a function calls on data from a header file before the header file is inserted, then the function won't be able to access the data.

If you use a function multiple times across several files, then any change would require you to go through all those files and change the function everywhere. 

By using a function file to contain the function in combination with a header file to contain the declarations, you can simply include these two files in every file that you want to access the function and then you only need to change these two files to have it change everywhere.