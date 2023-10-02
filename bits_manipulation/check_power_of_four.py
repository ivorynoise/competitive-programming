
# Returns true if `n` is a power of four
def check_power_of_four(n):
    return ((n & (n - 1)) == 0) and (n % 3 == 1)

# Driver code
if __name__ == "__main__":
    n = int(input("Enter a number: "))
    if check_power_of_four(n):
        print(f"{n} is a power of 4")
    else:
        print(f"{n} is not a power of 4")