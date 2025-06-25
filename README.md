# C++ Restaurant Ordering System 🍽️

An Object-Oriented C++ project that simulates a restaurant ordering system with exception handling.  
Users can view a menu, add items to their order, and calculate the total bill. The system throws custom exceptions for invalid inputs like negative quantities.

---

## 📌 Features

- 🍕 Menu display with items and prices  
- 🛒 Add menu items to order  
- ❌ Input validation using exceptions (e.g., quantity must be positive)  
- 💵 Calculate total cost of the order  
- 🧾 Print receipt of the full order

---

## ⚠️ Exception Handling

- ✅ Ensures item quantity is positive  
- ✅ Prevents invalid menu selections  
- ✅ Catches and displays appropriate error messages  
- Custom exception classes used for clarity and structure

---

## 🧠 Concepts Used

- Object-Oriented Programming (OOP)  
- Classes & Objects  
- Exception Handling with `throw` / `try` / `catch`  
- Class Composition (`Order` contains `MenuItem`s)  
- Loops and Input Validation

---

## ⚙️ How to Run

```bash
g++ order-system.cpp -o order-system
./order-system
