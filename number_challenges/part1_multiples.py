# Part A
print("Multiples of 9 less than 99")
for i in range(1, 99):
    if i % 9 == 0:
        print(f"{i:<8}", end="")  # 8 spaces between each multiple of 9
print("\n")  # Move to the next line after outputting all multiples
#part B
print("Numbers less than 500 divisible by both 3 and 7")
count = 0
for i in range(1, 500):
    if i % 3 == 0 and i % 7 == 0:
        print(f"{i:<4}", end="    ")  # 4 spaces between each number
        count += 1
        if count % 5 == 0:  # After every 5 numbers, move to a new line
            print()
print("\n")  # move to the next line

# Part C
print("Sum of multiples of 17 between 200 and 400")
sum_of_multiples = 0
for i in range(200, 401):
    if i % 17 == 0:
        sum_of_multiples += i

print(f"Sum of multiples of 17 between 200 and 400: {sum_of_multiples}")
