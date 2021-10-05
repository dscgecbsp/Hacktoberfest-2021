# bubble sort is a better algorithm for sorting in few cases so, added this.

def bubble_sort(list1):  
    for i in range(len(list1)-1):  
        for j in range(len(list1)-1):  
            if(list1[j]>list1[j+1]):   
                list1[j],list1[j+1] = list1[j+1], list1[j]  
    return list1

array = [11, 1, 10, 2, 9, 3, 8, 4, 7, 6, 5, 0]
unsorted_array = array.copy()
sorted_array = bubble_sort(array)

print(f"Initial Array: {unsorted_array}\nFinal Array:   {sorted_array}")