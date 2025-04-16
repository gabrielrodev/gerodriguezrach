first_name = input('Enter your first name: ')
last_name = input('Enter your last name: ')
age = input('Enter your age: ')

username = first_name[0] + last_name + age  # Concatenate first character, last name, and age
username = username.lower()  # Convert to lowercase

# Step 3: Define a function to validate bowling scores
def valid_score(score): #creates a function
    """Check if the score is a valid bowling score between 0 and 300."""
    return 0 <= score <= 300 #return should only be between grater then or equal to 0 or less than or equal to 300, if they are they will be defined as valid_score

try: #makes it so that the whole thing don't brake if input is wrong
    # Input bowling scores and convert them to integers
    bowling_score1 = int(input('Enter your first bowling score (0-300): '))
    bowling_score2 = int(input('Enter your second bowling score (0-300): '))
    bowling_score3 = int(input('Enter your third bowling score (0-300): '))

    # Validate each bowling score
    if not valid_score(bowling_score1) or not valid_score(bowling_score2) or not valid_score(bowling_score3): #This part is telling that if not every single one of the scores is between the def function then is going to print an error
        print("Error: Some of your bowling scores are invalid.")
        print("        Scores must be between 0 to 300.       ")
        quit()  #makes it so that the program exits after displaying the message

    #calculates the average score of the three
    average_score = (bowling_score1 + bowling_score2 + bowling_score3) / 3
    average_score = int(average_score)

    if average_score <= 89: #creating a new function to define greater then or equal to 89 define skill_level
        skill_level = 'Beginner'
    elif 90 <= average_score <= 184: #same thing here just use elif to prolong the 'if'
        skill_level = 'Intermediate'
    else:                           #everything else is expert, and that just means 184 and higher until 300 because all else is an error
        skill_level = 'Advanced'

    print(f"Hi {first_name} {last_name}! Your username is {username}, your average score is {average_score:.2f}, "
          f"and your skill level is {skill_level}. Keep practicing!") #same as writing print it just easier to use F''{} instead of '',''

except ValueError:
    # If there is an error prints the message bellow
    print("Invalid input! Please enter valid numeric scores.")