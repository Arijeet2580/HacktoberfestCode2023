# Function to add two numbers
def add(a, b):
    return a + b

# Function to subtract two numbers
def subtract(a, b):
    return a - b

# Function to multiply two numbers
def multiply(a, b):
    return a * b

# Function to divide two numbers
def divide(a, b):
    if b == 0:
        print("Cannot divide by zero")
        return None
    return a / b

# Function to calculate the power of a number
def power(a, b):
    return a ** b

# Display the menu and get user choice
def get_user_choice():
    print("Select operation:")
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Division")
    print("5. Power")
    print("6. Exit")
    return int(input("Enter choice: "))

# Main calculator loop
while True:
    choice = get_user_choice()

    if choice == 6:
        print("Exiting the calculator.")
        break

    if choice < 1 or choice > 6:
        print("Invalid choice. Please try again.")
        continue

    if choice == 5:
        # Get base and exponent for power operation
        base = float(input("Enter the base: "))
        exponent = float(input("Enter the exponent: "))
        result = power(base, exponent)
    else:
        # Get two numbers for other operations
        num1 = float(input("Enter first number: "))
        num2 = float(input("Enter second number: "))

        if choice == 1:
            result = add(num1, num2)
        elif choice == 2:
            result = subtract(num1, num2)
        elif choice == 3:
            result = multiply(num1, num2)
        elif choice == 4:
            result = divide(num1, num2)

    # Print the result
    if result is not None:
        print("Result:", result)
