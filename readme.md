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

![Menu](sandbox:/mnt/data/f9f70fc2-ae75-430a-aff3-5586e9ff1e3b.png)

### Viewing All Books

![View Books](sandbox:/mnt/data/2f28cc41-4a55-42de-95bb-2964e06c3a38.png)

### Adding a Book

![Add Book](sandbox:/mnt/data/83ca243c-323e-42d6-af4f-0a506598f479.png)

### Searching by ID

![Search Book](sandbox:/mnt/data/c1914dfd-e856-483b-8232-132dce409370.png)

### Issuing a Book

![Issue Book](sandbox:/mnt/data/59f029cc-cfaa-48da-9f9a-40b47a8cd28f.png)

### Returning a Book

![Return Book](sandbox:/mnt/data/11ea3741-9b8b-4ff5-809b-0df5c056e910.png)

### Exit Message

![Exit](sandbox:/mnt/data/512d5dd8-8a46-4e45-93a2-d781820b620a.png)

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
