n = int(input())

for _ in range(n):
    day_sum = 0
    year, month, day = map(int, input().split())

    # total days of the first year (including the first day)
    # print("total days include the first day.")
    day_sum += 1

    # print("for the first month {0} in the first year {1}:".format(month, year))
    if year % 3 == 0 or month % 2 == 1:
        day_sum += 20 - day
        # print("plus {0} day.".format(20 - day))
    else:
        day_sum += 19 - day
        # print("plus {0} day.".format(19 - day))

    for m in range(month+1, 11):
        # print("for the month {0} in the first year:".format(m))
        if m % 2 == 1:
            day_sum += 20
            # print("plus 20 day.")
        else:
            day_sum += 19
            # print("plus 19 day.")

    # total days from the second year to the second year from the last
    for y in range(1, 1000-year):
        # print("for year {0}:".format(year+y))
        for m in range(1, 11):
            # print("for the month {0}".format(m))
            if y % 3 == 0 or m % 2 == 1:
                day_sum += 20
                # print("plus 20 day.")
            else:
                day_sum += 19
                # print("plus 19 day.")

    print(day_sum)