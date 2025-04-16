def get_numbers():
    numbers = []
    for i in range(8):
        number = float(input(f"Enter number {i + 1}: "))
        numbers.append(number)
    return numbers

def display_numbers(numbers):
    print(" ".join([f"{num:.1f}" for num in numbers]))

def reverse_numbers(numbers):
    print(" ".join([f"{num:.1f}" for num in reversed(numbers)]))

def calculate_sum(numbers):
    total = sum(numbers)
    print(f"The sum of the numbers is {total:.2f}")

def calculate_average(numbers):
    average = sum(numbers) / len(numbers)
    print(f"The average of the numbers is {average:.2f}")
    return average

def display_above_average(numbers, average):
    above_average = [num for num in numbers if num > average]
    print(" ".join([f"{num:.1f}" for num in above_average]))

def main():
    numbers = get_numbers()
    display_numbers(numbers)
    reverse_numbers(numbers)
    calculate_sum(numbers)
    average = calculate_average(numbers)
    display_above_average(numbers, average)

if __name__ == "__main__":
    main()
