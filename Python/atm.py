class Atm:
    def __init__(self):
        self.pin = None
        self.balance = 0

    def start(self):
        while True:
            user_input = input('''
                Hello, how would you like to proceed?
                1. Enter 1 to create pin
                2. Enter 2 to deposit
                3. Enter 3 to withdraw
                4. Enter 4 to check balance
                5. Enter 5 to exit
            ''')

            if user_input == '1':
                self.create_pin()
            elif user_input == '2':
                self.deposit()
            elif user_input == '3':
                self.withdraw()
            elif user_input == '4':
                self.check_balance()
            elif user_input == '5':
                print("Bye")
                break
            else:
                print("Invalid Number!")

    def create_pin(self):
        self.pin = input("Enter Your pin: ")
        print("Pin Created Successfully!")

    def deposit(self):
        if self.pin is None:
            print("You need to create a pin first.")
            return

        entered_pin = input("Enter Your pin: ")
        if entered_pin == self.pin:
            amount = int(input("Enter the amount: "))
            self.balance += amount
            print("Deposit Successful")
        else:
            print("Invalid pin!")

    def withdraw(self):
        if self.pin is None:
            print("You need to create a pin first.")
            return

        entered_pin = input("Enter Your pin: ")
        if entered_pin == self.pin:
            amount = int(input("Enter the amount: "))
            if amount <= self.balance:
                self.balance -= amount
                print("Withdrawal Successful")
            else:
                print("Insufficient balance")
        else:
            print("Invalid pin!")

    def check_balance(self):
        if self.pin is None:
            print("You need to create a pin first.")
            return

        entered_pin = input("Enter Your pin: ")
        if entered_pin == self.pin:
            print("Your balance: $" + str(self.balance))
        else:
            print("Invalid pin!")

# Create an instance of the ATM class
atm = Atm()
atm.start()
