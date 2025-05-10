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

![image](https://github.com/user-attachments/assets/1d537337-3be1-4d41-953c-31d01a172937)


### Viewing All Books

![image](https://github.com/user-attachments/assets/3a899a1e-f1a5-434b-8419-aa4a15a7bdc7)


### Adding a Book

![image](https://github.com/user-attachments/assets/249c1909-c69d-4c47-87ac-23c7eb8dbc81)


### Searching by ID

![image](https://github.com/user-attachments/assets/e67d387e-c274-4b0b-acfc-7336cd432487)


### Issuing a Book

![image](https://github.com/user-attachments/assets/72ef2484-2ea0-4ac7-969c-8ea3b2b85a36)


### Returning a Book

![image](https://github.com/user-attachments/assets/cf804527-1479-4cbf-a714-163286c38cf6)


### Exit Message

![image](https://github.com/user-attachments/assets/7b6afea4-eabc-40d1-97c1-0d800c57cd6f)


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
