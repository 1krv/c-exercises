# Exercise: Binary File Management in C

This project is a practical exercise designed to deepen the understanding of Binary Input/Output in C. The goal was to build a CRUD (Create, Read, Update, Delete) system while avoiding the sequential limitations of standard `.txt` files.

### Concepts Applied
* **Structs and Padding:** Handling fixed-size data structures in memory and on disk.
* **`fwrite` / `fread`:** Direct memory reading and writing operations.
* **`fseek`:** File navigation using the file pointer (cursor) to modify specific records "in-place".
* **Database Logic:** ID management, file size calculation, and handling deleted record flags.

---

### How to Run
Compile the project using GCC:

```bash
gcc students-db.c -o db.o
./db.o
