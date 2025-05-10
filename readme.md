# 📚 Library Management System – C Language

A simple console-based **Library Management System** developed in **C**, using **binary file handling** to store and manage book records. This mini-project simulates a real-world library experience with core features like adding, searching, issuing, and returning books.

---

## 🚀 Features

* ✅ Add new books (with duplicate ID and title/author check)
* 🔍 Search books by:

  * Book ID
  * Title
  * Author
* 📦 Issue books with quantity check and tracking of issued count
* 🔄 Return books and update inventory
* 📋 View all books stored in the system
* 💾 Data is stored persistently using a binary file `books.dat`

---

## 🛠️ Technologies Used

* C Programming Language
* File Handling (`fopen`, `fread`, `fwrite`, `fseek`, `rewind`, `fclose`)
* Console UI

---

## 📸 Screenshots

### Menu Interface

![alt text](image.png)

### Viewing All Books

![alt text](image-1.png)

### Adding a Book

![alt text](image-2.png)

### Searching by ID

![alt text](image-3.png)

### Issuing a Book

![alt text](image-4.png)

### Returning a Book

![alt text](image-5.png)

### Exit Message

![alt text](image-6.png)

---

## 🧪 How to Run

```bash
# Step 1: Compile
gcc lib_man_sys.c 

# Step 2: Run
./a.exe
```

Make sure `books.dat` is in the same directory. If it doesn’t exist, it will be created automatically.

---

## 🙌 Credits

Developed by **Abhishek Chourasia** as a mini C programming project to demonstrate practical file handling and menu-driven logic.

---

## 📝 License

This project is open for educational use. Feel free to fork, modify, and learn from it!
