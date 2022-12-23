# C_Dictionary
Simple implementation of Dictionary in C

# Usage
You could create a dll using `make.bat` (it require clang.exe)

### Command with clang.exe
```
clang -shared -o library\dictionary.dll -I include src\Dictionary.c -l set -l hash -l linkedlist -L library
```
N.B.<br>
It requires that the `library` folder exists and contains `linkedlist`, `hash` and `set` libraries

# API

First of all implement your structure with the data you want. This must contain dictionary_node_t node;

### Example
```C
struct int_item {
    dictionary_node_t node;
    const char* key;
    int value;
};
```

## Functions

<table>
    <thead>
        <tr>
            <th>Function</th>
            <th colspan=2><center>Parametrs</center></th>
            <th colspan=2><center>Return</center></th>
            <th>Explanation</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>dictionary_table_new</td>
            <td>size_t</td>
            <td>The desired size of the hashmap</td>
            <td>dictionary_table_t*</td>
            <td>Pointer to the dictionary_table created or NULL on failure</td>
            <td>Create the dictionary_table stucture with desired hasmap size</td>
        </tr>
        <tr>
            <td rowspan=3>dictionary_table_insert</td>
            <td>dictionary_table_t*</td>
            <td>Pointer to the dictionary_table</td>
            <td rowspan=3>dictionary_node_t*</td>
            <td rowspan=3>Pointer to the inserted item or NULL on failure</td>
            <td rowspan=3>Adds an item to the dictionary</td>
        </tr>
        <tr>
            <td>dictionary_node_t*</td>
            <td>Pointer to the item to be insert</td>
        </tr>
        <tr>
            <td>size_t</td>
            <td>Size of the data to compare in the structure<br/>In the above example the length of the int type</td>
        </tr>
        <tr>
            <td rowspan=3>dictionary_table_search</td>
            <td>dictionary_table_t*</td>
            <td>Pointer to the dictionary_table</td>
            <td rowspan=3>dictionary_node_t*</td>
            <td rowspan=3>Pointer to the funded item or NULL if not</td>
            <td rowspan=3>Returns item of the dictionary with same value of passed one if any</td>
        </tr>
        <tr>
            <td>dictionary_node_t*</td>
            <td>Pointer to the item to be search</td>
        </tr>
        <tr>
            <td>size_t</td>
            <td>Size of the data to compare in the structure<br/>In the above example the length of the int type</td>
        </tr>
        <tr>
            <td rowspan=3>dictionary_table_remove</td>
            <td>dictionary_table_t*</td>
            <td>Pointer to the dictionary_table</td>
            <td rowspan=3>dictionary_node_t*</td>
            <td rowspan=3>Pointer to the removed item or NULL on failure</td>
            <td rowspan=3>Remove a dictionary item with the same value as the one passed in and return it</td>
        </tr>
        <tr>
            <td>dictionary_node_t*</td>
            <td>Pointer to the item to be remove</td>
        </tr>
        <tr>
            <td>size_t</td>
            <td>Size of the data to compare in the structure<br/>In the above example the length of the int type</td>
        </tr>
    </tbody>
</table>

# Example

Create executable using `example.bat` (it require clang.exe)

## Command with clang.exe
```
clang -shared -o library\dictionary.dll -I include src\Dictionary.c -l set -l hash -l linkedlist -L library
```
N.B.<br>
It requires that the `examples/bin` folder exists.<br/>
Copy `linkedlist.dll`, `hash.dll` and `set.dll` from `library` folder to `examples/bin` folder

## Run it
```
./examples/bin/Example.exe
```