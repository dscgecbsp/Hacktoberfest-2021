// bubble sort fucntion
function bubbleSort(arr) {
    let noSwaps = true
    for (let index1 = arr.length; index1 > 0; index1--) {
        for (let index2 = 0; index2 < index1 - 1; index2++) {
            if (arr[index2] > arr[index2 + 1]) {
                let temp = arr[index2 + 1]
                arr[index2 + 1] = arr[index2]
                arr[index2] = temp
                noSwaps = false
            }
        }
        if (noSwaps) break // if no swap is there then break (way to optimize)
    }
    return arr
}

// input your elements here
console.log(bubbleSort([2, 6, 7, 2, 3, 4, 10, 16, 11, 14]))
