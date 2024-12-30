def kadane_with_subarray(arr):
    max_so_far = float('-inf')
    max_ending_here = 0

    start = 0
    end = 0
    temp_start = 0

    for i in range(len(arr)):
        if max_ending_here + arr[i] < arr[i]:
            max_ending_here = arr[i]
            temp_start = i
        else:
            max_ending_here += arr[i]

        if max_ending_here > max_so_far:
            max_so_far = max_ending_here
            start = temp_start
            end = i

    return max_so_far, arr[start:end + 1]

# Example usage
array = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
max_sum, subarray = kadane_with_subarray(array)
print("Maximum Subarray Sum:", max_sum)
print("Subarray:", subarray)
