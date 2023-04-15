def minOperations(n):
    """Method that calculates the fewest number of operations to obtain n"""

    """minimo comun multiplo"""
    mcm = 2
    operations = 0

    if n <= 1:
        return 0

    while n > 1:
        if n % mcm == 0:
            n /= mcm
            operations += mcm

        else:
            mcm += 1

    return operations
