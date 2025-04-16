import random

# Step 1: Generate 50 random integers between 1 and 100 inclusive
random_numbers = []
count = 0

while count < 50:
    random_number = random.randint(1, 100)  # Generate a random integer between 1 and 100
    random_numbers.append(random_number)  # Append it to the list
    count += 1

# Step 2: Initialize variables for counting and finding highest and lowest numbers
count_in_range = 0
highest = random_numbers[0]
lowest = random_numbers[0]

# Step 3: Analyze the numbers using a for loop
for number in random_numbers:
    # Check if the number is between 42 and 61 inclusive
    if 42 <= number <= 61:
        count_in_range += 1


    if number > highest:
        highest = number


    if number < lowest:
        lowest = number


print("Random Numbers:", random_numbers)
print(f"There are {count_in_range} numbers between 42 and 61 inclusive.")
print(f"The highest number in the list is: {highest}.")
print(f"The lowest number in the list is: {lowest}.")
