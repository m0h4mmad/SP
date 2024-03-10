# description: calculating the approximate value of Pi by Leibniz way,


def Pi_approximate_value_by_Leibniz_way(): # function to calculate the approximate value of Pi
    Pi = 0
    try: # calculating the value of Pi
        n = int(input("Enter n: ")) # getting the user input
        if n > 0: # allowing for only positive integers
            flip_flag = False # setting a flag to determine when to add and when to subtract
            for i in range(1, n * 2, 2): # iterating on the double of value which the used provided, start with 1 and step is 2
                if flip_flag: # if the flip flag value is True, then subtract
                    Pi -= (1 / i)
                else: # if the flip flag value is True, then add
                    Pi += (1 / i)
                flip_flag = not flip_flag # changing the flip flag value
            print(f"The approximate value of Pi is: {Pi * 4}")
        else:
            print("\033[91mERR: Please enter a positive integer.\033[0m")
    except ValueError: # error to print when the input is character not positive integer
        print("\033[91mERR: Please enter a valid integer.\033[0m")
Pi_approximate_value_by_Leibniz_way()