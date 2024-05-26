# **Assignment 8**

## **Implementing a Memory Resident File System**

The entire file system is allocated memory in a chunk, and hence in a contiguous fashion. 
The chunk begins with the Super block which contains the following:

    Block 0:
        super_block_constants: int sys_size, num_blocks, block_size, num_files;
        super_block_multiplicatives: int* used; vol_info* filename_map;

        vol_info is a mapping from a filename to the initial index of the block where it is stored.

    Block1:
        int *fat;
        It contains the FDT in which there is an integer array which contains where the next block index is. 
        In case there is no next block index, it stores -1.

    Block 2 onwards:
        char* other_blocks;
        It contains the data blocks, and is represented as an array with each element a char buffer having size
        equal to that of the given block size.

For i-nodes:

    Block 0:
        super_block_constants: char vol_name[100], int vol_size, block_size, num_blocks, free_ptr

    Block 1 & 2:
        Inodes: int valid, type, size, directly[5], singly, doubly

    Block 3 onwards:
        char* buff


## **Function documentation:**

`int my_open(char *filename);`
- creates a new file if it does not exist, or opens an already opened file. Returns a file descriptor integer

`int my_close(int file);`
- removes file from FDT and return 1 upon success, else -1

`void my_read(char *text, int file, int len)`
- copies len no of characters from file to text char buffer updating the seek.

`int my_write(int file, char *text, int len, char mode)`
- write len no of characters from text to file and returns the no of characters written. Mode ‘w’ overwrites the file, and mode ‘a’ appends to the file, mode ‘s’ uses the writing seek to write at a specified position.

`int my_mkdir(char *str)`
- Creates a directory named str in cwd. If a directory with the same name exists, a new directory is not created.

`int my_chdir(char *str)`
- Changes cwd to the directory named by str. If it doesn’t exist, an error is thrown.

`int my_rmdir(char *str)`
- Deletes the directory named by str. Also deletes the associated files and contents.

`int my_copy(char *system_file, char *file_here)`
- Copies a file from system named by system_file to a file named by file_here in the virtual system. Returns the file descriptor int. If the same named file already exists, it is overwritten.


## **Extra Functions Made :**

`int my_erase(int file);`
- Erases the contents of a file, but not the file itself. Returns 1 upon success and -1 upon error.

`int my_cat(char *str)`
`int my_cat(int file)`
- For FAT: Prints content of a file named by str. Return 1 upon success and -1 upon failure (if file not found).
- For inode: Prints the content of the FDT pointed to by the file







