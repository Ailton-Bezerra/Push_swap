<p align="center">
  <img src="https://github.com/Ailton-Bezerra/Ailton-Bezerra/blob/main/badges/push_swapm.png" alt="Push_swap 42 project badge"/>
<p align="center">
  <p align="center">
  <strong>125/100</strong> 🌟
</p>

## Description
`Push_swap` program sorts a list of integers using a set of predefined stack operations.
- Duplicates and non-numeric inputs will cause an error.
- The goal is to sort the list using the least amount of moves possible.
- This version acepts numbers in strings.

### 1️⃣ Compile the program:
```sh
make
```
- This will generate the push_swap executable..

### 2️⃣ Run push_swap with a list of numbers
```sh
./push_swap 4 67 3 87 23
```
Example Output:
```sh
pb
pb
ra
sa
pa
pa
```
- The output consists of the sequence of operations needed to sort the numbers.

### 3️⃣ Check if the output is correct using the checker:
#### First, compile the checker program
```sh
make bonus
```
Then, use it to validate the output of push_swap:
```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

Expected Output:
```
OK
```
- If the output is "KO", it means the sorting algorithm did not work correctly.

### 4️⃣ Count the number of operations:
### To check how many operations push_swap is using, run:
```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```
- This will display the number of moves required to sort the list.

---
## Contact Information
For any questions or suggestions, feel free to reach out to me via my [GitHub profile](https://github.com/Ailton-Bezerra).
