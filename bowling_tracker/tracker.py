def main():
    first_name, last_name, age = get_user_info()
    username = create_username(first_name, last_name, age)
    scores = get_bowling_scores()
    highest, lowest, average = calculate_score_stats(scores)
    skill_level = determine_skill_level(average)
    display_output(first_name, last_name, username, highest, lowest, average, skill_level)


def get_user_info():
    """Accepts user's personal information and returns it."""
    first_name = input("Enter your first name: ")
    last_name = input("Enter your last name: ")
    age = input("Enter your age: ")
    return first_name, last_name, age


def create_username(first_name, last_name, age):
    """Creates and returns the user's username based on first name initial, last name, and age."""
    username = (first_name[0] + last_name + age).lower()
    return username


def get_bowling_scores():
    """Accepts an unknown number of bowling scores and returns them as a list."""
    scores = []
    while True:
        try:
            score_input = input("Enter a bowling score (0-300), or type 'done' to finish: ")
            if score_input.lower() == 'done':
                break
            score = int(score_input)
            if valid_score(score):
                scores.append(score)
            else:
                print("Error: Score must be between 0 and 300.")
        except ValueError:
            print("Invalid input! Please enter a valid numeric score or 'done' to finish.")
    return scores


def valid_score(score):
    """Returns True if score is between 0 and 300, False otherwise."""
    return 0 <= score <= 300


def calculate_score_stats(scores):
    """Calculates and returns the highest, lowest, and average scores from the list."""
    if scores:
        highest = max(scores)
        lowest = min(scores)
        average = sum(scores) / len(scores)
        return highest, lowest, average
    else:
        return 0, 0, 0  # Default values if no valid scores are entered


def determine_skill_level(average_score):
    """Determines and returns the user's skill level based on the average score."""
    if average_score <= 89:
        return "Beginner"
    elif 90 <= average_score <= 184:
        return "Intermediate"
    else:
        return "Advanced"


def display_output(first_name, last_name, username, highest, lowest, average, skill_level):
    """Displays the user's information, scores, and skill level."""
    print(f"\nHi {first_name} {last_name}!")
    print(f"Your username is {username}.")
    print(f"Highest score: {highest}")
    print(f"Lowest score: {lowest}")
    print(f"Average score: {average:.2f}")
    print(f"Skill level: {skill_level}. Keep practicing!")


# Run the program
if __name__ == "__main__":
    main()